


// defines pins numbers
#include <LiquidCrystal.h>

// For LED and Buzzer
const int Red = 10;
const int Yellow =9;
const int Green = 7;
const int Buzzer = A4;

// For Ultrasonic
const int trigPin = 13;
const int echoPin = 8;


// defines variables
long duration;
double cm;
double pers1,pers2;

// To specific the wires from Arduino to LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//###################################################################################################
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication

pinMode(Red,OUTPUT); //Sets the Red as an Output
pinMode(Yellow,OUTPUT); //Sets the Yellow as an Output
pinMode(Green,OUTPUT); //Sets the Green as an Output
pinMode(Buzzer,OUTPUT); //Sets the Buzzer as an Output

lcd.begin(16, 2); // LCD has 16 Columes and 2 Row

  // Print a message to the LCD.
  lcd.print("The Percentage");  // print "The Percentage" one row 1 and takes 14 Colume
  lcd.setCursor(0, 1); // mean next word will begin on First colume of row 2
  lcd.print("of water:");
}
//###################################################################################################
void loop() {

//////////////////////////////////////////////////////////////////////////////
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH,30000);
// Calculate the cm , translate from second to cm 
cm = (duration/2) / 29.1;

pers1 =(cm/30)*100;
pers2 = 100-pers1;

//Serial.println(duration);
//
if (pers2 <0)
pers2=0;
lcd.setCursor(10, 1);
lcd.print(pers2);
lcd.setCursor(15, 1);
lcd.print("%");
//Serial.println(duration);
Serial.println(cm);
// Serial.println(pers2);

if (pers2 <= 33.33){
analogWrite(Red,51*(3));
analogWrite(Yellow,51*(0));
analogWrite(Green,51*(0));
analogWrite(Buzzer,0);
if (pers2 <= 2)
analogWrite(Buzzer,51*(6)) ;
}

else if (pers2 < 66.66 && pers2 > 33.33 ){
analogWrite(Yellow,51*(3));
analogWrite(Red,51*(0));
analogWrite(Green,51*(0));
analogWrite(Buzzer,0);
}

else {
analogWrite(Green,51*(3));
analogWrite(Yellow,51*(0));
analogWrite(Red,51*(0));
analogWrite(Buzzer,51*(0));
if (pers2 >= 98)
analogWrite(Buzzer,51*(6));

}



delay(1000);
}
