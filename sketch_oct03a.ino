
#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX plwase remove the any jumper cable attached to 0 and 1 port before uploading the code

String BT_input;                          // to store input character received via BT.
                             // device to control

// Define Motor Pin
# define LEFT_A 5  //if your bot isn’t moving in the correct direction please change this numbers according how u made it//
# define LEFT_B 7
# define RIGHT_A 2
# define RIGHT_B 4
# define enA 3 //pwm pins to control speed of the motor
#define enB 6

void setup()  
{  
  Serial.begin(9600);                      //default baud rate of module
  mySerial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(LEFT_A,OUTPUT);
  pinMode(LEFT_B,OUTPUT);
  pinMode(RIGHT_A,OUTPUT);
  pinMode(RIGHT_B,OUTPUT);
  while (!Serial) 
  {
     
  }
}

void loop() 

 { 
  if (mySerial.available())
    {   
        BT_input = mySerial.read();   // read input string from bluetooth 
        Serial.println(BT_input);
        if (BT_input=="1")                
        {
          forward();
        }
        if (BT_input=="2")                
        {
          right();
        }
        if (BT_input=="3")                
        {
          left();
        }
        if (BT_input=="4")                
        {
          back();
        }
        
        if (BT_input=="5")                
        {
          stop();
        }
        

    }
 
}
void forward()//making a robot car move forward
{
  digitalWrite(LEFT_A,LOW);
  digitalWrite(LEFT_B,HIGH);
  digitalWrite(RIGHT_A,HIGH);
  digitalWrite(RIGHT_B,LOW);
}

void back()//making a robot car moce backward
{
  digitalWrite(LEFT_A,HIGH);
  digitalWrite(LEFT_B,LOW);
  digitalWrite(RIGHT_A,LOW);
  digitalWrite(RIGHT_B,HIGH);
}

void left()//making my robot car rotate left direction
{
  digitalWrite(LEFT_A,LOW);
  digitalWrite(LEFT_B,HIGH);
  digitalWrite(RIGHT_A,LOW);
  digitalWrite(RIGHT_B,HIGH);
}
void right()//making my robot car rotate in right direction
{
  digitalWrite(LEFT_A,HIGH);
  digitalWrite(LEFT_B,LOW);
  digitalWrite(RIGHT_A,HIGH);
  digitalWrite(RIGHT_B,LOW);
}
void stop()//to stop the robot from moving
{
  digitalWrite(LEFT_A,LOW);
  digitalWrite(LEFT_B,LOW);
  digitalWrite(RIGHT_A,LOW);
  digitalWrite(RIGHT_B,LOW);
}
