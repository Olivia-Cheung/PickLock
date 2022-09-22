#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
const int closedPosition = 90; 
const int openPosition = 0; 

bool locked = false;


Servo myServo; 
int reader = analogRead(A0); 

void setup()
{
  
  myServo.attach(9);
 // pinMode(poteniometer, INPUT);
  Serial.begin(9600); 
  
  lcd.print("Try to get in"); 
  lcd.setCursor(0,1); 
  
  

}

void loop()
{
  //generate random number and put servo at the "close" angle 
  int randomNumber = random() + 256 - 1;
  myServo.write(closedPosition);
  
 //loop executes while the user has not found the random number  
  while (reader == !randomNumber){
    
    Serial.print("Current number: ");
    Serial.print(reader); 
    delay(100);
    
  }
  
  lcd.print("You were able to get in!"); 
  
  delay(10); // Delay a little bit to improve simulation performance
}
