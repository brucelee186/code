#include "Keyboard.h"
const int led = 15; 
void setup ()
{
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH); 
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  Keyboard.begin();
}

void loop ()
{
if (digitalRead(A0) == LOW) {
Keyboard.press('wwwwwwwwwwwwwwwww');
}
else {
Keyboard.release('w');
}
if (digitalRead(A1) == LOW) {
Keyboard.press('s');
}
else {
Keyboard.release('s');
}
if (digitalRead(A2) == LOW) {
Keyboard.press('a');
}
else {
Keyboard.release('a');
}
if (digitalRead(A3) == LOW) {
Keyboard.press('d');
}
else {
Keyboard.release('d');
}
if (digitalRead(2) == LOW) {
Keyboard.press('j');
}
else {
Keyboard.release('j');
}
if (digitalRead(3) == LOW) {
Keyboard.press('k');
}
else {
Keyboard.release('k');
}
if (digitalRead(4) == LOW) {
Keyboard.press('l');
}
else {
Keyboard.release('l');
}
if (digitalRead(5) == LOW) {
Keyboard.press(';');
}
else {
Keyboard.release(';');
}
if (digitalRead(2) == LOW) {
Keyboard.press('j');
}
else {
Keyboard.release('j');
}
}
