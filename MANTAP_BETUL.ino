#include <PinChangeInt.h>
#include <Servo.h>

#define AUX1 A0 //1
#define AUX2 A1 //2
#define AUX3 A2 //4
#define AUX4 A3 //3
#define AUX5 A4 //5
#define AUX6 A5 //6


#define servosatu 3
#define servocamera 4
#define Relay 9
#define leda 6 //merahputih
#define ledb 7 //hijauputih
#define ledc 8 //putihdua

Servo servodropsatu;
Servo servocamera1;



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Relay, OUTPUT);
pinMode(leda,OUTPUT);
pinMode(ledb, OUTPUT);
pinMode(ledc, OUTPUT);
pinMode(AUX1, INPUT); digitalWrite(AUX1, HIGH);
pinMode(AUX2, INPUT); digitalWrite(AUX2, HIGH);
pinMode(AUX3, INPUT); digitalWrite(AUX3, HIGH);
pinMode(AUX4, INPUT);
pinMode(AUX5, INPUT);
pinMode(AUX6, INPUT);
//PCintPort::attachInterrupt(AUX1, &risingAUX1, RISING);
//PCintPort::attachInterrupt(AUX2, &risingAUX2, RISING);
servodropsatu.attach(servosatu);
servocamera1.attach(servocamera);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(AUX4)==HIGH){Serial.print("HIGH");}
  else{
    Serial.print(LOW);}
digitalWrite(leda,HIGH);
digitalWrite(ledb,HIGH);
digitalWrite(ledc,HIGH);
delay(100);
digitalWrite(leda,LOW);
digitalWrite(ledb,LOW);
digitalWrite(ledc,LOW);
delay(1000);

if(digitalRead(AUX5) == HIGH)
{
servodropsatu.write(90);
servocamera1.write(90);
delay(500);
}
else{
servodropsatu.write(0);
servocamera1.write(0);
delay(500);
}
if(digitalRead(AUX4) == HIGH)
{
 digitalWrite(Relay,HIGH);

}
else
{
 digitalWrite(Relay,LOW);
 
}
if(digitalRead(AUX6) == HIGH)
{
 digitalWrite(ledc,HIGH);
}else{
 digitalWrite(ledc,LOW); 
  }


}
