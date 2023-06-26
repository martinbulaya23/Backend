#include <Arduino.h>
#include <HardwareSerial.h>

HardwareSerial SerialPort(2);

void setup()  
{ 
  Serial.begin(115200);
  SerialPort.begin(115200, SERIAL_8N1, 16, 17);
 
} 

void loop() {

  if (SerialPort.available() > 0) {
    String message = SerialPort.readString();
    if (message == "MARTIN"){
       Serial.println(message);
       

    }
    SerialPort.print("DONE!");
    
   }  
}