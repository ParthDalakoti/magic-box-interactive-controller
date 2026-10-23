/*
=============================================
MAGIC BOX - Sequence Based Switch-LED Trick
=============================================
 
LOGIC:
- It does NOT matter which physical switch (1,2,3 or 4) is turned ON.
- Whichever switch is turned ON FIRST -> RED LED lights up
- Whichever switch is turned ON SECOND -> BLUE LED lights up
- Whichever switch is turned ON THIRD -> YELLOW LED lights up
- Whichever switch is turned ON FOURTH -> GREEN LED lights up
- When ALL switches are turned back OFF, the system auto-resets
for the next round (so you can shuffle the color caps again).
 
WIRING:
--------
Switches (toggle/slide type, SPST):
Switch 1 -> Pin 2 ---> other leg to GND
Switch 2 -> Pin 3 ---> other leg to GND
Switch 3 -> Pin 4 ---> other leg to GND
Switch 4 -> Pin 5 ---> other leg to GND
(We use INPUT_PULLUP, so NO external resistor needed on switches)
 
LEDs (with 220 ohm resistor in series to GND):
Red LED -> Pin 8
Blue LED -> Pin 9
Yellow LED -> Pin 10
Green LED -> Pin 11
 
NOTE: The color caps you place on the switches are just a physical
prop for the "magic" effect - they are NOT wired to the Arduino at all.
The Arduino only tracks the ORDER in which switches are flipped on.
*/
 
const int switchPins[4] = {2, 3, 4, 5};
const int ledPins[4] = {8, 9, 10, 11}; // Red, Blue, Yellow, Green - in activation order
 
bool prevState[4]; // last DEBOUNCED reading of each switch (HIGH = OFF, LOW = ON)
bool lastRaw[4]; // last RAW reading (used only for debounce timing)
unsigned long lastChangeTime[4]; // when the raw reading last changed, per switch
const unsigned long DEBOUNCE_MS = 40; // ignore switch flicker faster than this
 
bool ledOn[4]; // current state of each LED (true = lit)
int assignedLed[4]; // which LED slot each switch currently owns (-1 = none)
 
void setup() {
for (int i = 0; i < 4; i++) {
pinMode(switchPins[i], INPUT_PULLUP);
pinMode(ledPins[i], OUTPUT);
digitalWrite(ledPins[i], LOW);
prevState[i] = HIGH; // assume all switches start OFF
lastRaw[i] = HIGH;
lastChangeTime[i] = 0;
assignedLed[i] = -1;
}
for (int j = 0; j < 4; j++) {
ledOn[j] = false;
}
Serial.begin(9600);
}
 
void loop() {
for (int i = 0; i < 4; i++) {
bool raw = digitalRead(switchPins[i]); // LOW = ON, HIGH = OFF
 
// Debounce: only accept a new state once it's been stable for DEBOUNCE_MS
if (raw != lastRaw[i]) {
lastChangeTime[i] = millis();
lastRaw[i] = raw;
}
 
if ((millis() - lastChangeTime[i]) > DEBOUNCE_MS) {
bool currentState = raw;
 

// OFF -> ON: give this switch the lowest available (unlit) LED slot
if (prevState[i] == HIGH && currentState == LOW) {
int slot = lowestFreeSlot();
if (slot != -1) {
ledOn[slot] = true;
digitalWrite(ledPins[slot], HIGH);
assignedLed[i] = slot;
Serial.print("Switch "); Serial.print(i + 1);
Serial.print(" ON -> LED slot "); Serial.println(slot);
}
}
 
// ON -> OFF: turn off only the LED this switch owns
if (prevState[i] == LOW && currentState == HIGH) {
if (assignedLed[i] != -1) {
int slot = assignedLed[i];
ledOn[slot] = false;
digitalWrite(ledPins[slot], LOW);
assignedLed[i] = -1;
Serial.print("Switch "); Serial.print(i + 1);
Serial.print(" OFF -> LED slot "); Serial.print(slot);
Serial.println(" cleared");
}
}
 
prevState[i] = currentState;
}
}
}
 
// Returns the lowest-index LED that is currently OFF (Red=0 has priority, then Blue=1, etc.)
// Returns -1 if all 4 LEDs are already lit.
int lowestFreeSlot() {
for (int j = 0; j < 4; j++) {
if (!ledOn[j]) return j;
}
return -1;
}