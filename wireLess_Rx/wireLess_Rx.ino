#include <VirtualWire.h>
#include <ServoTimer2.h>

ServoTimer2 leftMotor;
ServoTimer2 rightMotor;


void setup() {
  Serial.begin(9600);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_set_rx_pin(12);
    vw_setup(4000);  // Bits per sec
    pinMode(13, OUTPUT);

    vw_rx_start();       // Start the receiver PLL running
}

void loop() {
  char buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  int intVal;
  char recData;
  char *ptrrecData;
  String dummy;
  char retVal;

  if (vw_get_message(buf, &buflen)) {

    for(int i=0; i<buflen; i++) {
//      Serial.println(buf[i]);
      if (buf[i] != 'C' && buf[i] != 'J' && buf[i] != 'Z') {
        Serial.println(buf[i]);
        if (buf[i] == 'M') {
          moveMotor(1560,1560);
        } else if (buf[i] == 'N') {
          moveMotor(1600,1600);
        }
      } else {
        stopMotor();
        Serial.println("No Operation");
      }
    }
    
  }


}
/*
void rec() {
    char buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    int intVal;
    char recData;
    char *ptrrecData;
    String dummy;
    char retVal;

    if (vw_get_message(buf, &buflen)) {

      for(int i=0; i<buflen; i++) {
        Serial.println(buf[i]);
      }
    }
}*/

void moveMotor (int leftSpeed, int rightSpeed){
  rightMotor.attach(8);
  leftMotor.attach(9);
  rightMotor.write(rightSpeed);
  leftMotor.write(leftSpeed);
}

void stopMotor() {
  leftMotor.detach();
  rightMotor.detach();
}

