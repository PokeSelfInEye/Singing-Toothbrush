#include <MIDI.h>

// Converts the MIDI note number to half the period for the actual note frequency
#define mtop(mid)        round(50000.0/((440.0/32.0)*pow(2,((mid-9.0)/12.0))))

#define CN0           mtop(0)
#define CS0           mtop(1)
#define DN0           mtop(2)
#define DS0           mtop(3)
#define EN0           mtop(4)
#define FN0           mtop(5)
#define FS0           mtop(6)
#define GN0           mtop(7)
#define GS0           mtop(8)
#define AN0           mtop(9)
#define AS0           mtop(10)
#define BN0           mtop(11)

#define CN1           mtop(12)
#define CS1           mtop(13)
#define DN1           mtop(14)
#define DS1           mtop(15)
#define EN1           mtop(16)
#define FN1           mtop(17)
#define FS1           mtop(18)
#define GN1           mtop(19)
#define GS1           mtop(20)
#define AN1           mtop(21)
#define AS1           mtop(22)
#define BN1           mtop(23)

#define CN2           mtop(24)
#define CS2           mtop(25)
#define DN2           mtop(26)
#define DS2           mtop(27)
#define EN2           mtop(28)
#define FN2           mtop(29)
#define FS2           mtop(30)
#define GN2           mtop(31)
#define GS2           mtop(32)
#define AN2           mtop(33)
#define AS2           mtop(34)
#define BN2           mtop(35)

#define CN3           mtop(36)
#define CS3           mtop(37)
#define DN3           mtop(38)
#define DS3           mtop(39)
#define EN3           mtop(40)
#define FN3           mtop(41)
#define FS3           mtop(42)
#define GN3           mtop(43)
#define GS3           mtop(44)
#define AN3           mtop(45)
#define AS3           mtop(46)
#define BN3           mtop(47)

#define CN4           mtop(48)
#define CS4           mtop(49)
#define DN4           mtop(50)
#define DS4           mtop(51)
#define EN4           mtop(52)
#define FN4           mtop(53)
#define FS4           mtop(54)
#define GN4           mtop(55)
#define GS4           mtop(56)
#define AN4           mtop(57)
#define AS4           mtop(58)
#define BN4           mtop(59)

#define CN5           mtop(60)
#define CS5           mtop(61)
#define DN5           mtop(62)
#define DS5           mtop(63)
#define EN5           mtop(64)
#define FN5           mtop(65)
#define FS5           mtop(66)
#define GN5           mtop(67)
#define GS5           mtop(68)
#define AN5           mtop(69)
#define AS5           mtop(70)
#define BN5           mtop(71)

#define CN6           mtop(72)
#define CS6           mtop(73)
#define DN6           mtop(74)
#define DS6           mtop(75)
#define EN6           mtop(76)
#define FN6           mtop(77)
#define FS6           mtop(78)
#define GN6           mtop(79)
#define GS6           mtop(80)
#define AN6           mtop(81)
#define AS6           mtop(82)
#define BN6           mtop(83)

#define CN7           mtop(84)
#define CS7           mtop(85)
#define DN7           mtop(86)
#define DS7           mtop(87)
#define EN7           mtop(88)
#define FN7           mtop(89)
#define FS7           mtop(90)
#define GN7           mtop(91)
#define GS7           mtop(92)
#define AN7           mtop(93)
#define AS7           mtop(94)
#define BN7           mtop(95)

#define CN8           mtop(96)
#define CS8           mtop(97)
#define DN8           mtop(98)
#define DS8           mtop(99)
#define EN8           mtop(100)
#define FN8           mtop(101)
#define FS8           mtop(102)
#define GN8           mtop(103)
#define GS8           mtop(104)
#define AN8           mtop(105)
#define AS8           mtop(106)
#define BN8           mtop(107)

#define CN9           mtop(108)
#define CS9           mtop(109)
#define DN9           mtop(110)
#define DS9           mtop(111)
#define EN9           mtop(112)
#define FN9           mtop(113)
#define FS9           mtop(114)
#define GN9           mtop(115)
#define GS9           mtop(116)
#define AN9           mtop(117)
#define AS9           mtop(118)
#define BN9           mtop(119)

#define CN10          mtop(120)
#define CS10          mtop(121)
#define DN10          mtop(122)
#define DS10          mtop(123)
#define EN10          mtop(124)
#define FN10          mtop(125)
#define FS10          mtop(126)
#define GN10          mtop(127)
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
  Serial.begin(57600);
  pinMode(motorPin1, OUTPUT);

  TCCR2A = 0;
  TCCR2B = (1<<CS20);
  OCR2A = 10;
  TIMSK2 = (1<<OCIE2A);
  sei();

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
