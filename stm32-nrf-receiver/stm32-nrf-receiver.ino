#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
RF24 radio(PB0, PA4); // CE, CSN on Blue Pill
const uint64_t address = 0xF0F0F0F0E1LL;

void setup(){
  Serial.begin(9600);
  Serial.println("Starting...");
  radio.begin();
  Serial.print("ADDRESS :");
  radio.openReadingPipe(0, address);   //Setting the address at which we will receive the data
  radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.startListening();              //This sets the module as receiver
}
void loop(){
  if (radio.available()){
    Serial.println("Radio is sniffing");
    byte recv;                 //Saving the incoming data
    radio.read(&recv, sizeof(recv));    //Reading the data
    Serial.println(recv);
  }
}