#include <SPI.h>
#include <Ethernet.h>
#include "demo.h"

void setup() {
  pinMode(8, OUTPUT); 
}

void loop() {
  if (analogRead(A0) < 300) {
    digitalWrite(8, !digitalRead(8));
    sendToExosite(1,analogRead(A0));
    sendToExosite(2,digitalRead(8));
  }  
  delay(1000);          
}
