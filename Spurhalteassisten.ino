#include<Servo.h>

Servo dir;
Servo myservo;
int led = 7;
const int ldr = A4;                              //The port may varies
int check = 0;
int var = 33;                              //Test: Vars are the variables from the LDRs
int var1 = 30;                             //They have to be replaced with real variables
int var2 = 20;                               
int var3 = 18;

void setup() {
  Serial.begin(9600);
  dir.attach(11);
  myservo.attach(12);
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
 
}


void loop() {
    
if(check = 0) {                          //Checks that the car drives straight forward and accelerates
    check + 1;                               //It add +1 to the check value to show that the car is now ready
    straight();
    acc();
  }

while(check = 1){                      //After the check the car starts with its routine                   

  data();
  
  if (analogRead(ldr) == var) {             // If resistance is like var the ldrs havent crossed any street signs
  vel();                                //so it keeps its velocity
  }
  
  if (analogRead(ldr) == var1) {          // If the resistance is like var1 the car has to move into the right direction
  right();
  vel();
  }
  
  if (analogRead(ldr) == var2) {             // If the resistance is like var2 the car has to move to the left
  left();
  vel();
  }

  if (analogRead(ldr) == var3) {           //Here both LDRs sees a white surface, here our car should stop driving
    off();
    
    }
  
  else {                                   //If that happens there is something wrong: The car will stop!
    off();                                 //The serial monitor will show a problem   
    Serial.print("Fehler!\nDie Checksumme ist nicht mehr im vorhergesehenen Bereich"); 
    }
  
  }
  
}

void off(){                           //Here the Check figure will get replaced by a 0
  check - 1;                          //Next time if the car is on, it will check itself 
  brk();
    
  
  }

void data(){                                                  //Test:Here we should get some data to see if the Arduino sees the LDRs
    int sensor = analogRead(ldr);
    Serial.println(sensor);
  }

void vel() {                                                   //keep velocity
  myservo.write(104);
  delay(250);
  }

void acc()  {
  myservo.write (106);                                        //accelerate
  delay (100);
  myservo.write (105);
  delay (150);
  myservo.write (104);
  }

void brk() {                                                 //breaks the car to 0                                                         
  myservo.write (88);                                                               
  delay(50);
  myservo.write (90);                                                            
  delay(100);
  }

void left() {                                              //car drives left
  dir.write(60);
  delay(500);
  }

void right() {                                            //car drives right
  dir.write(120);
  delay(500);
  }

void straight() {                                        //resets the direction
  dir.write(90);
  }
