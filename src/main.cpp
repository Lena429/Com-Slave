#include <Arduino.h>
#include <Wire.h>

#define ADDRESS 0x12        // slave address

void action(int numBytes);

void setup(){
    Wire.begin(ADDRESS);

    Wire.onReceive(action);

    Serial.begin(115200);
}

void loop(){
  
}

void action(int numBytes){
    int bytes;

    while(Wire.available()){
        bytes = Wire.read();
        Serial.println(bytes);
    }

}