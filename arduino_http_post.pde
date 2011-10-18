#include <SPI.h>
#include <Ethernet.h>
#include "arduino_http_post.h"

void setup() {
  pinMode(7, OUTPUT); 
}

void loop() {
  digitalWrite(7, !digitalRead(7));
  sendToExosite(1,analogRead(A0));
  sendToExosite(2,digitalRead(7));
  delay(1000);          
}
