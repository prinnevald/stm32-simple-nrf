#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
RF24 radio(PB0, PA4); // CE, CSN on Blue Pill 
const uint64_t address = 0xF0F0F0F0E1LL;
 
void setup(){
  
  Serial.begin(9600);
  
  radio.begin();                  //Starting the Wireless communication
  radio.openWritingPipe(address); //Setting the address where we will send the data
  radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.stopListening();          //This sets the module as transmitter
}
 
void loop(){
  byte var[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  radio.write(&var, sizeof(var));
  delay(1000);
}
