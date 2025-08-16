#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //Change the HEX address

int IRSensor = 10;
int IRSensor1 = 11;
int count =0;
int count1 =0;
Servo servo;
Servo servo1;
int val =0;
void setup() {


 lcd.begin(16,2);
 lcd.backlight();

 lcd.setCursor (0,0);
lcd.print("     ARDUINO    ");
lcd.setCursor (0,1);
lcd.print(" PARKING SYSTEM ");
delay (2000);
lcd.clear();  
  
// put your setup code here, to run once:
servo.attach(8);
servo1.attach(9);

Serial.begin(9600);
servo.write(90);
servo1.write(90);
pinMode(IRSensor, INPUT);
pinMode(IRSensor1, INPUT);
delay(2000);
}
void loop() {
// put your main code here, to run repeatedly:
int sensorStatus = digitalRead(IRSensor); // Set the GPIO as Input

int sensorStatus1 = digitalRead(IRSensor1);

 if (sensorStatus != 0) // Check if the pin high or not
  {
    
    Serial.println(count); // print Motion Detected! on the serial monitor window

    count++;

    if (count==500)
    {
    servo.write(0);
    delay(2000);
    servo.write(90);
    count=0;
    }
    
  }


   if (sensorStatus1 != 0) // Check if the pin high or not
  {
    
    Serial.println(count1); // print Motion Detected! on the serial monitor window

    count1++;

    if (count1==500)
    {
    servo.write(0);
    delay(2000);
    servo.write(90);
    count1=0;
    }
    
  }

if (Serial.available() > 0) {
    String str = Serial.readString();
    str.trim();
    Serial.println(str);

if(str.equals("B"))
{
  count=0;
servo.write(180);
delay(2000);
servo.write(90);
delay(2000);
servo1.write(180);
delay(500);
servo1.write(90);
count=0;
}
else if(str.equals("W"))
{

}


}

    
  }
