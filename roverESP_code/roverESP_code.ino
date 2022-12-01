#include<PS4Controller.h>
#include "driver/gpio.h"//<-- THIS IS IMPORTANT; IT ALLOWS US TO ACTUALLY USE THE PINS ON THE ESP32 FOR IO
//#include<Servo.h>


unsigned long lastTimeStamp = 0;

//Servo
//Servo goatedServo;

// int RECV_PIN = ; <- might not need this idk -\_(o.o)_/-
int LINP_1_PIN = 26;
int LINP_2_PIN = 27;
int LPWMA = 13;

int RINP_1_PIN = 19;
int RINP_2_PIN = 18;
int RPWMA = 4;



void setup() {

  //BT(S) Stuff lol
  Serial.begin(115200);
  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisconnect);
  PS4.begin("ec:2e:98:45:88:c2");

  Serial.println("Initialization Ready!");

  pinMode(LINP_1_PIN, OUTPUT);
  pinMode(LINP_2_PIN, OUTPUT);
  pinMode(RINP_1_PIN, OUTPUT);
  pinMode(RINP_2_PIN, OUTPUT);
  pinMode(LPWMA, OUTPUT);
  pinMode(RPWMA, OUTPUT);

}

void loop() {


}

void notify(){




  int LY = PS4.LStickY();
  int RY = PS4.RStickY();

  leftMotor(LY);
  rightMotor(RY);

  Serial.printf("LEFT: %4d\tRIGHT: %4d\n", LY, RY);


}

void onConnect(){Serial.println("Controller Connected.");}
void onDisconnect(){Serial.println("Controller Disconnected.");}


//CODE FOR THE MOTORS


void leftMotor(int LY){
  if(LY > 100){
    digitalWrite(LINP_1_PIN, HIGH);
    digitalWrite(LINP_2_PIN, LOW); 
    digitalWrite(LPWMA, HIGH);
  }else if(LY < -100){
    digitalWrite(LINP_1_PIN, LOW);
    digitalWrite(LINP_2_PIN, HIGH); 
    digitalWrite(LPWMA, HIGH);
  }else{
    digitalWrite(LINP_1_PIN, LOW);
    digitalWrite(LINP_2_PIN, LOW); 
    digitalWrite(LPWMA, LOW);
  }
}
void rightMotor(int RY){
  if(RY > 100){
    digitalWrite(RINP_1_PIN, HIGH);
    digitalWrite(RINP_2_PIN, LOW); 
    digitalWrite(RPWMA, HIGH);
  }else if(RY < -100){
    digitalWrite(RINP_1_PIN, LOW);
    digitalWrite(RINP_2_PIN, HIGH); 
    digitalWrite(RPWMA, HIGH);
  }else{
    digitalWrite(RINP_1_PIN, LOW);
    digitalWrite(RINP_2_PIN, LOW); 
    digitalWrite(RPWMA, LOW);
  }

}
/*
void moveForward(){
  digitalWrite(INP_1_PIN, HIGH);
  digitalWrite(INP_2_PIN, LOW); 
  digitalWrite(PWMA, HIGH);

  //Serial.printf("GPIO 16: %d\n", digitalRead(x));
  //Serial.printf("GPIO 17: %d\n", digitalRead(y));
  //Serial.printf("GPIO 4: %d\n", digitalRead(z));
}
void stop(){
  digitalWrite(INP_1_PIN, LOW);
  digitalWrite(INP_2_PIN, LOW); 
  digitalWrite(PWMA, LOW);


  //Serial.printf("GPIO 16: %d\n", digitalRead(x));
  //Serial.printf("GPIO 17: %d\n", digitalRead(y));
  //Serial.printf("GPIO 4: %d\n", digitalRead(z));
}
*/
void turnServo(){return;}
