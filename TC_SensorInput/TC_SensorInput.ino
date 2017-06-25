
/*

  Tincon/AMaze Alternative Controller Workshop 2017
  ~ Code example for sensor input with keyboard output ~

  Run this on Arduino Leonardo/Pro Micro or any other Arduino-compatible with 32U4 chip!
  

  

*/


// the Keyboard library gives you simple acces to keaboard output
#include "Keyboard.h"
#include "Mouse.h"

// in this example you can have 2 inputs, i.e. buttons, sensors etc
int signalPlayer1 = 8;
int signalPlayer2 = 9;

const char keyPlayer1 = 'q';    // key for player 1
const char keyPlayer2 = 'p';    // key for player 2

boolean analogInput = false;    // change this to true to read analog signals
boolean pullupPinMode = true;  // change to true if you want to use pullup logic
boolean inputActiveState;       // is HIGH or LOW (pullup) the active state?

void setup() {
  
  Serial.begin(9600);           // start serial communication
  Serial.println ("Serial available!");
  
    // using the internal pullup resistor is the
    // easiest way to build a button:
    // just connect a pin to GND to make it change
    // the state from HIGH to LOW (PULLUP means: logic is reverted!)

  if (pullupPinMode) {
    inputActiveState = LOW;
    pinMode (signalPlayer1, INPUT_PULLUP);
    pinMode (signalPlayer2, INPUT_PULLUP);
  } else {
    // OR use normal INPUT mode to read out sensor modules
    inputActiveState = HIGH;
    pinMode (signalPlayer1, INPUT);
    pinMode (signalPlayer2, INPUT);
  }
 
  Keyboard.begin();             // start the keyboard

  if (analogInput) {
    //Mouse.begin();            // if you have an analog sensor input you could move the mouse
  }
  
}

void loop() {

  if (analogInput) {
    readAnalogInput ();
  } else {
    readDigitalInput ();
  }

}

void readDigitalInput () {

  // read out the pins and press the key

  int pin1 = digitalRead (signalPlayer1);
  int pin2 = digitalRead (signalPlayer2);

  Serial.println (pin1);

  if (pin1 == inputActiveState) {
    Keyboard.press(keyPlayer1);
  } else {
    Keyboard.release(keyPlayer1);
  }

  if (pin2 == inputActiveState) {
    Keyboard.press(keyPlayer2);
  } else {
     Keyboard.release(keyPlayer2);
  }

}


void readAnalogInput() {  

  // not tested

  int pin1 = digitalRead (signalPlayer1);
  int pin2 = digitalRead (signalPlayer2);

  pin1 = map (pin1, 0, 1023, -10,10);
  pin2 = map (pin2, 0, 1023, -10,10);

  Mouse.move(pin1, pin2, 0);

}


// when using delay() the whole program stops for the given miliseconds
// so you probably should not use tapKey() in a multiplayer game!
void tapKey (char theKey) {
  Keyboard.press(theKey);
  delay(100);
  Keyboard.release(theKey);
}







