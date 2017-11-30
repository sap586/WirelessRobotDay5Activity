#include <VirtualWire.h>
char *controller;
char *data;
String leftRight;
String upDown;
char temp[5];
char temp2[5];

void setup() {
  pinMode(13,OUTPUT);
  pinMode(7,INPUT);
  Serial.begin(9600);
  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(12);
  vw_setup(4000);
}

void loop(){
  sendA0();
  delay(50);
}

void sendA0() {
  char mss[1];
  mss[0] = condition(analogRead(A0), analogRead(A1));
  Serial.println(mss[0]);
  vw_send((uint8_t *)mss, strlen(mss));
  vw_wait_tx();
}
/*
char abcd(int analog) {
  char result;
  if (analog < 250) {
    result = 'a';
  } else if (analog >= 250 && analog <= 500) {
    result = 'b';
  } else if (analog >= 500 && analog <= 750) {
    result = 'c';
  } else if (analog >= 750 && analog <= 1000) {
    result = 'd';
  } else {
    result = 'e';
  }
  return result;
}
*/

char condition(int valueLR, int valueUD){
  char c;
  if(valueLR >= 0 && valueLR < 201) {
    if(valueUD > 525 && valueUD < 751){
      return  c = 'A';
    }
     if(valueUD > 750 && valueUD < 1024){
      return  c = 'B';
    }
    else{
      return  c = 'C';
    }
  }
  if(valueLR > 200 && valueLR < 501) {
    if(valueUD > 525 && valueUD < 751){
      return  c = 'D';
    }
     if(valueUD > 750 && valueUD < 1024){
      return  c = 'E';
    }
    else{
      return  c = 'C';
    }
  }
  if(valueLR > 520  && valueLR < 825) {
    if(valueUD > 525 && valueUD < 751){
      return  c = 'H';
    }
     if(valueUD > 750 && valueUD < 1024){
      return  c = 'I';
    }
    else{
      return  c = 'J';
    }
  }
  if(valueLR > 824  && valueLR < 1024) {
    if(valueUD > 525 && valueUD < 751){
      return  c = 'K';
    }
     if(valueUD > 750 && valueUD < 1024){
      return  c = 'L';
    }
    else{
      return  c = 'J';
    }
  }
  if(valueUD > 525 && valueUD < 751 && valueLR > 500 && valueLR < 521 ){
      return  c = 'M';
    }
  if(valueUD > 750 && valueUD < 1024 && valueLR > 500 && valueLR < 521){
      return  c = 'N';
    }
  else{
    return c = 'Z';
  }
  
}
