#include <Arduino.h>
#include <HardwareSerial.h>

HardwareSerial SerialPort(2);

int GREEN_LED_PIN = 22;
int BLUE_LED_PIN = 23;

void setup()  
{ 
  Serial.begin(115200);
  SerialPort.begin(115200, SERIAL_8N1, 16, 17);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
   
} 
void loop() {

  
  if (SerialPort.available() > 0) {
  String message = SerialPort.readString();

    if (message == "MARTIN"){
      Serial.println(message);
      
    }
     SerialPort.print("DONE!");

     for (int i = 0; i < 5; i++) {
    digitalWrite(BLUE_LED_PIN, HIGH);
    delay(100);
    digitalWrite(BLUE_LED_PIN, LOW);
    delay(100);
    }
     digitalWrite(GREEN_LED_PIN, HIGH);
    delay(5000);
    digitalWrite(GREEN_LED_PIN, LOW);
    delay(5000);
 
  }  
  
}
  