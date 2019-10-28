#include <VirtualWire.h>
#include <VirtualWire_Config.h>
void setup(){
Serial.begin(9600);
vw_set_ptt_inverted(true); // Required for DR3100
vw_set_rx_pin(5);
vw_setup(1000); // Bits per sec
pinMode(13, OUTPUT);
pinMode(3, OUTPUT);
vw_rx_start(); // Start the receiver PLL running
}
void loop(){
syyde();
starter();
}
void syyde(){
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
Serial.println(buf[0]);
if (vw_get_message(buf, &buflen)) // Non-blocking
{
if(buf[0]==49){
digitalWrite(13,1);
}
if(buf[0]==50){
digitalWrite(13,0);
}
}
}
void starter(){
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
Serial.println(buf[0]);
if (vw_get_message(buf, &buflen)) // Non-blocking
{
if(buf[0]==51){
digitalWrite(3,1);
}
if(buf[0]==52){
digitalWrite(3,0);
}
}
}
