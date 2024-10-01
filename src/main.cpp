#include <Arduino.h>
#include <Wire.h>

#define ADDRESS 0x12        // slave address
const int BUFFER_SIZE = 16;
char buffer[BUFFER_SIZE];

void action(int numBytes);
void reply();

void setup(){
    Wire.begin(ADDRESS);

    Wire.onReceive(action);
    Wire.onRequest(reply);

    Serial.begin(115200);
}

void loop(){
}

void action(int numBytes){
    int index = 0;

    memset(buffer, 0, BUFFER_SIZE);

    while(Wire.available() && index < BUFFER_SIZE - 1){
      buffer[index] = Wire.read();
      index++;
    }
    buffer[index] = '\0';

    String message = buffer;
    Serial.println("Received: " + message);

} 

void reply(){
    Wire.write((uint8_t*)buffer, strlen(buffer)); 
    Serial.println("Sent: " + String((char*)buffer));
    // Clear the buffer after sending
    memset(buffer, 0, BUFFER_SIZE);
}