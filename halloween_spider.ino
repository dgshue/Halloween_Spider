#include <Servo.h> 

#define retractPin D4
#define dropPin D3
#define motionPin D2
  
Servo retractServo;  // create servo object to control a servo
Servo dropServo;
  
void setup() {  
  Serial.begin(9600);  
  Serial.println("Enter speed (0 - 180, 0 is fast left, 180 is fast right, 90 = stop)");
  pinMode(motionPin, INPUT);
  dropServo.attach(dropPin);
  dropServo.write(170);
}  
  
void loop() {  

   int val = digitalRead(motionPin);
   if (val == LOW) {
     dropServo.write(60);
     delay(5000);
     dropServo.write(170);
     delay(1000);   
     retractSpider();
     delay(10000);
   }
} 


void retractSpider() {
    Serial.println('Retracting...');
    retractServo.attach(retractPin);  
    retractServo.write(180);  
    delay(20000);  
    retractServo.detach(); 
    Serial.println('Done Retracting');  
}
