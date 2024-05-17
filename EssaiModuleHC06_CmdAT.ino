#include <SoftwareSerial.h>

/* Turn an LED on/off based on a command send via BlueTooth
**
** Credit: The following example was used as a reference
** Rui Santos: http://randomnerdtutorials.wordpress.com
*/

SoftwareSerial SerialHC06(10,11); // RX, Tx
//SoftwareSerial SerialHC06(A1,A5); // RX, Tx
int ledPin = 12;  // use the built in LED on pin 12 of the Uno
int ledPinLedV = 13;  // use the built in LED on pin 13 of the Uno
int ledPinLedR = 8;  // use the built in LED on pin 8 of the Uno
int state = 0;
int flag = 0;        // make sure that you return the state only once
char ValComm = -2;
int MemState = 0;
void setup() {
    // sets the pins as outputs:
    pinMode(2, INPUT);
//    digitalWrite(2,HIGH);
    pinMode(3, OUTPUT);
 
 


    
    Serial.begin(9600); // Default connection rate for my BT module
    Serial.println("Demarrage");
    SerialHC06.begin(9600); // Default connection rate for my BT module
    SerialHC06.println("Hello");
   }

void loop() {
    //if some data is sent, read it and save it in the state variable
    //ValComm = SerialHC06.available();

    if(Serial.available()>0)
    {
      ValComm = Serial.read();
      SerialHC06.write(ValComm); 
    }
    if(SerialHC06.available()>0)
    {
      ValComm = SerialHC06.read();
      Serial.write(ValComm); 
    }
    

}
