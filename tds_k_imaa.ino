#include <VirtualWire.h>
char *controller;
int starter = 6;
int syyde = 5;
int val = 0;
int sal = 3;
void setup() {
  Serial.begin(9600);
vw_set_ptt_inverted(true); //
vw_set_tx_pin(12);
vw_setup(1000);// speed of data transfer Kbps
pinMode(starter, INPUT);
pinMode(syyde, INPUT);
}

void loop(){
 // Wait until the whole message is gone
Serial.println("1");
val = digitalRead(starter);
sal = digitalRead(syyde);
if (val == HIGH){
controller="1"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx();
}
else {
controller="2"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx();
}
if (sal == HIGH){
controller="3"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx();
}
else {
controller="4"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx();
}

Serial.println("2");

}
