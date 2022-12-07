// Based off code found here: https://codebender.cc/sketch:273092#Useless_Machine_Final.ino by fritend1, Thanks!

#include <Servo.h>
Servo lidservo;
Servo armservo; 
Servo flag;

int switchpin = 2;
int ledRed = 12;
int ledGreen = 11;
int ledBlue = 10;
int motor = 13;
int action = 1;

int pos = 0;
int armUp = 55;
int armDown = 155;
int lidUp = 125;
int lidDown = 77;
int flagUp = 0;
int flagDown = 90;
int flagMiddle = 50;

void setup() {
pinMode(switchpin,INPUT);
pinMode(ledRed,OUTPUT);
pinMode(ledGreen,OUTPUT);
pinMode(ledBlue,OUTPUT);
pinMode(motor,OUTPUT);
lidservo.attach(3);
armservo.attach(4);
flag.attach(5);

// Servo Default Starting Position

armservo.write(armDown);
flag.write(flagDown);
lidservo.write(lidDown);
}

void loop() {

// Action Selection starting with 1

  if (digitalRead(switchpin) == HIGH)
  {
  if (action > 9) {
    action = 1;
  }  
    if (action == 1) {
    action1();
    }
    else if (action == 2) {
    action2();
    }
    else if (action == 3) {
    action3();
    }
    else if (action == 4) {
    action4();
    }
    else if (action == 5) {
    action5();
    }
    else if (action == 6) {
    action6();
    }
    else if (action == 7) {
    action7();
    }
    else if (action == 8) {
    action8();
    }
    else if (action == 9) {
    action9();
    }

    action += 1;
    
  }
}

//The Following are actions that are chosen chronologically

void action1() {
//  blinkgreen(1);
  lidservo.write(lidUp - 20);
  delay(1000);
  armservo.write(armUp);
  delay(500); 
  armservo.write(armDown);
  delay(1000);
  lidservo.write(lidDown);
  delay(1000);
}

void action2() {
//  blinkgreen(2);
  lidservo.write(lidUp);
  delay(100);
  armservo.write(armUp);
  delay(250);
  armservo.write(armDown);
  delay(100);
  lidservo.write(lidDown);
}

void action3() {
//  blinkgreen(3);
  for(pos = lidDown; pos < (lidUp - 20); pos +=1)
  {
    lidservo.write(pos);
    delay(50);
  }
  armservo.write(armUp);
  delay(250);
  armservo.write(armDown);
  delay(100);
  lidservo.write(lidDown);
}

void action4() {
//  blinkgreen(4);
  delay(250);
  lidservo.write(lidUp);
  delay(100);
  armservo.write(armUp);
  delay(2500);
for(pos = armUp; pos < armDown; pos +=1)
  {
    armservo.write(pos);
    delay(50);
  }
  lidservo.write(lidDown);
  armservo.write(armDown);
}

void action5() {
//  blinkgreen(5);
  lidservo.write(lidUp);
  delay(500);
  lidservo.write(lidDown);
  delay(500);
  lidservo.write(lidUp);
  delay(500);
  lidservo.write(lidDown);
  delay(500);
  lidservo.write(lidUp);
  delay(500);
  lidservo.write(lidDown);
  delay(2500);
  lidservo.write(lidUp);
  delay(100);
  armservo.write(armUp);
  delay(250);
  armservo.write(armDown);
  delay(100);
  lidservo.write(lidDown);
}

void action6() {
//  blinkgreen(6);
  lidservo.write(lidUp);
  delay(100);
  armservo.write(armUp + 20);
  delay(250);
  armservo.write(armDown);
  delay(100);
  lidservo.write(lidDown);
  delay(250);
  lidservo.write(lidUp);
  delay(100);
  armservo.write(armUp + 20);
  delay(250);
  armservo.write(armDown);
  delay(100);
  lidservo.write(lidDown);
  delay(250);
  lidservo.write(lidUp);
  delay(100);
  armservo.write(armUp + 20);
  delay(250);
  armservo.write(armDown);
  delay(100);
  lidservo.write(lidDown);
  delay(250);  
  lidservo.write(lidUp);
  delay(100);
  armservo.write(armUp);
  delay(250);
  armservo.write(armDown);
  delay(100);
  lidservo.write(lidDown);
}

void action7() {
//  blinkgreen(7);
  for(pos = lidDown; pos < lidUp; pos +=2)
  {
    lidservo.write(pos);
    delay(50);
  }
  for(pos = armDown; pos < (armUp + 30); pos -=2)
  {
    armservo.write(pos);
    delay(100);
  }
  armservo.write(armUp);
  for(pos = armUp; pos < armDown; pos +=2)
  {
    armservo.write(pos);
    delay(100);
  }
  for(pos = lidUp; pos < lidDown; pos +=2)
  {
    lidservo.write(pos);
    delay(50);
  }
  lidservo.write(lidDown);
}

void action8() {
//  blinkgreen(8);
  digitalWrite(ledRed, HIGH);
  digitalWrite(motor, HIGH);
  lidservo.write(lidUp);
  delay(3000);
  armservo.write(armUp);
  delay(250);
  armservo.write(armDown);
  delay(100);
  lidservo.write(lidDown);
  digitalWrite(motor, LOW);
  digitalWrite(ledRed, LOW);
}

void action9() {
//  blinkgreen(9);
  if (digitalRead(switchpin) == HIGH)
  {
    delay(1000);
  for(pos = lidDown; pos < lidUp; pos +=2)
  {
    lidservo.write(pos);
    delay(50);
  }
  for(pos = flagDown; pos > flagUp; pos -=10)
  {
    flag.write(pos);
    delay(50);
  }
  delay(250);
  for(pos = flagUp; pos < flagMiddle; pos +=10)
  {
    flag.write(pos);
    delay(50);
  }
  for(pos = flagMiddle; pos > flagUp; pos -=10)
  {
    flag.write(pos);
    delay(50);
  }
  for(pos = flagUp; pos < flagMiddle; pos +=10)
  {
    flag.write(pos);
    delay(50);
  }
  for(pos = flagMiddle; pos > flagUp; pos -=10)
  {
    flag.write(pos);
    delay(50);
  }
  for(pos = flagUp; pos < flagMiddle; pos +=10)
  {
    flag.write(pos);
    delay(50);
  }
  for(pos = flagMiddle; pos > flagUp; pos -=10)
  {
    flag.write(pos);
    delay(50);
  }
  for(pos = flagUp; pos < flagMiddle; pos +=10)
  {
    flag.write(pos);
    delay(50);
  }
  for(pos = flagMiddle; pos > flagUp; pos -=10)
  {
    flag.write(pos);
    delay(50);
  }
  delay(250);
  for(pos = flagUp; pos < flagDown; pos +=10)
  {
    flag.write(pos);
    delay(50);
  }
  for(pos = lidUp; pos > lidDown; pos -=2)
  {
    lidservo.write(pos);
    delay(50);
  }
  delay(2000);
      lidservo.write(lidUp);
  delay(100);
  armservo.write(armUp);
  delay(250);
  armservo.write(armDown);
  delay(100);
  lidservo.write(lidDown);
  }
}

void blinkgreen(int x){
  while (x > 0){
    digitalWrite(ledGreen, HIGH);
    delay(350);
    digitalWrite(ledGreen, LOW);
    delay(350);
    x -= 1;
  }
}
