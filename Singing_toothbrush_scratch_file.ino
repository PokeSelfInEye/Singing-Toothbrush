#include <MIDI.h>


//pin variables
int const motorPin1 = 7; //digital motor control pins
int const aReadPin1 = 14; //analog read pin
int const aWritePin1 = 6;

//temporary testing variables
int potInput = 0; //potentiometer input 
int frequencyDelayMs = 1; //the delay in milliseconds to give the frequency
int frequencyDelayUs = 1000; //the delay in microseconds to make a frequency

//not frequency variables
float const noteC4 = 261.262; //C4
float const noteD4 = 293.665; //D4
float const noteE4 = 329.628; //E4
float const noteF4 = 349.228; //F4
float const noteG4 = 391.995; //G4
float const noteA4 = 440.000; //A4
float const noteB4 = 493.883; //B4

int const beatsPerMinute = 120;
int beatDurationMs;

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
  pinMode(motorPin1, OUTPUT);
  //beatDurationMs = 60000/beatsPerMinute;
}

void loop() {
  /*digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH); //DIGITAL ALTERNATING PINS
  delayMicroseconds(frequencyDelayUs);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  Serial.println(frequencyDelayUs);
  delayMicroseconds(frequencyDelayUs);
  potInput = analogRead(aReadPin1);
  frequencyDelayUs = (potInput*4) + 1000;*/
  playNote(noteE4, beatDurationMs);
  playNote(noteD4, beatDurationMs);
  playNote(noteC4, beatDurationMs);
  playNote(noteD4, beatDurationMs);
  
  playNote(noteE4, beatDurationMs);
  playNote(noteE4, beatDurationMs);   
  playNote(noteE4, beatDurationMs*2); 
                                       
  playNote(noteD4, beatDurationMs);   
  playNote(noteD4, beatDurationMs);   
  playNote(noteD4, beatDurationMs*2); 
                                      
  playNote(noteE4, beatDurationMs);  
  playNote(noteG4, beatDurationMs);    
  playNote(noteG4, beatDurationMs*2); 
  
  
  
}

void playNote(float noteFrequencyHz,int noteDurationMs) {
  int noteDelayUs = 1000000/noteFrequencyHz; //converts frequency to period
  int timerStart = millis();
  int timerTracker = millis();
  Serial.println(noteFrequencyHz);
  while (timerTracker - timerStart < noteDurationMs) {
    timerTracker = millis();
    digitalWrite(motorPin1, LOW);
    delayMicroseconds(noteDelayUs);
    digitalWrite(motorPin1, HIGH);
    //Serial.println(timerTracker-timerStart);
    delayMicroseconds(noteDelayUs);
  }
}
