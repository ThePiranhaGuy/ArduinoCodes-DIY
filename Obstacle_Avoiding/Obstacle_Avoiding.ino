#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h> 

//defining pins and variables
#define TRIG_PIN A4 
#define ECHO_PIN A5 
#define MAX_DISTANCE 200
#define MAX_SPEED 200 // sets max speed of DC  motors
#define MAX_SPEED_OFFSET -2 //for right

#define turn_delay 600  //need to test

//defining motors,servo,sensor
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 
AF_DCMotor motorL(1, MOTOR12_8KHZ); 
AF_DCMotor motorR(2, MOTOR12_8KHZ);
Servo myservo; 
  
//defining global variables
boolean goesForward=false;
int distance = 100;
int speedSet = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(10);  
  myservo.write(90);  
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
 distance = readPing();
 int distanceR = 0;
 int distanceL =  0;
 delay(40);
 Serial.println(distance);
 
 if(distance<=30)
 {
  Serial.println("Object Detected");
  moveStop();
  delay(100);
  moveBackward();
  delay(100);
  moveStop();
  delay(200);
  distanceR = lookRight();
  Serial.print("Distance Right = ");
  Serial.println(distanceR);
  delay(200);
  distanceL = lookLeft();
  Serial.print("Distance Left = ");
  Serial.println(distanceL);
  delay(200);
  if(distanceR>=30 || distanceL>=30)
  {
    if(distanceR>=distanceL)
    {
      turnRight();
      moveStop();
    }
    else if(distanceR<distanceL)
    {
      turnLeft();
      moveStop();
    }
  }
  else
  {
    turn180();
    moveStop();
  }
 }
 else
 {
  moveForward();
 }
 //reseting the variable after the operations
 
}

int lookRight()
{
    myservo.write(0); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(90); 
    return distance;
}

int lookLeft()
{
    myservo.write(180); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(90); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop() {
  motorL.run(RELEASE); 
  motorR.run(RELEASE);
  } 
  
void moveForward() {

 if(!goesForward)
  {
    goesForward=true;
    motorL.run(FORWARD);      
    motorR.run(FORWARD);      
   for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
   {
    motorL.setSpeed(speedSet);
    motorR.setSpeed(speedSet+MAX_SPEED_OFFSET);
    delay(5);
   }
  }
}

void moveBackward() {
    goesForward=false;
    motorL.run(BACKWARD);      
    motorR.run(BACKWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    motorL.setSpeed(speedSet);
    motorR.setSpeed(speedSet+MAX_SPEED_OFFSET);
    delay(5);
  }
}  

void turnRight() {
  Serial.println("Turning Right");
  motorL.run(FORWARD);
  motorR.run(BACKWARD);     
  delay(turn_delay);
  motorL.run(FORWARD);      
  motorR.run(FORWARD);      
} 
 
void turnLeft() {
  Serial.println("Turning Left");
  motorL.run(BACKWARD);     
  motorR.run(FORWARD);     
  delay(turn_delay);
  motorL.run(FORWARD);     
  motorR.run(FORWARD);
}  
void turn180(){
  Serial.println("Commencing U turn");
  motorL.run(BACKWARD);
  motorR.run(FORWARD);
  delay(2*turn_delay);
  motorL.run(FORWARD);
  motorR.run(FORWARD);
}
