//Intelligent Assisting Stick for Visual Impaired
// ---------------------------------------------------------------- //

#define echoPin1 A0 //Sensor 01 Echo pin  
#define trigPin1 A1 //Sensor 01 Trig pin - US sensor 1
#define echoPin2 A2 // Sensor 02 Echo pin 
#define trigPin2 A3 //Sensor 02 Trig pin - US sensor 2
#define echoPin3 A4 // Sensor 03 Echo pin 
#define trigPin3 A5 //Sensor 03 Trig pin - US sensor 3

#define enable 3  // Enable Pin for motor

#define motor_1 9  // Control pin 1 for motor
#define motor_2 8  // Control pin 2 for motor


//---------------------defines variables-------------------------//
long duration1; //(sensor 01) variable for the duration of sound wave travel
int distance1; //(sensor 01) variable for the distance measurement

long duration2; //(sensor 02) variable for the duration of sound wave travel
int distance2; // (sensor 02)variable for the distance measurement

long duration3; //(sensor 03) variable for the duration of sound wave travel
int distance3; // (sensor 03)variable for the distance measurement


void setup() {
    pinMode(enable, OUTPUT);
    pinMode(motor_1, OUTPUT);
    pinMode(motor_2, OUTPUT);
    
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT

  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin2, INPUT); // Sets the echoPin as an INPUT
  
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin3, INPUT); // Sets the echoPin as an INPUT
 
  Serial.begin(9600); 

}
void loop() {
  
  //US SENSOR 01
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  //US SENSOR 02
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microsecon
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  
  //US SENSOR3
  // Clears the trigPin condition
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration3 = pulseIn(echoPin3, HIGH);
  // Calculating the distance
  distance3 = duration3 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
 
 GoUP_stairCase();
 GoDOWN_stairCase();
 small_pit();
 large_pit();
 small_elevation();
 large_elevation();
 stairCase_obstacle();
 clean_Wall();
 

//  Serial.print("  Distance1: ");
//  Serial.print(distance1);
//  Serial.print(" cm  ");
//  
/*  Serial.print("  Distance2: ");
  Serial.print(distance2);
  Serial.print(" cm  ");*/
//  
//  Serial.print("Distance3: ");
//  Serial.print(distance3);
//  Serial.println(" cm  ");
  

}

//-----------------Ultra Sonic sensor Limitations------------------------//

void GoUP_stairCase() // To climb a staircase
{
  int q; // Number of times on motor pattern
  if(distance3<20 && distance1 <58 && 23<distance2<35 ){
    Serial.print("GO_UP ST_CASE!! ");
    for(q=3;q>0;q++) // Vibration motor vibrate 
    {
      p1();
    }
    delay(100);
  }
  
  Serial.print("S1"); Serial.print(distance1);
  Serial.print("S2"); Serial.print(distance2);
  Serial.print("S3"); Serial.println(distance3); 
}

void GoDOWN_stairCase() // To going down a staircase
{
  int q; // Number of times on motor pattern
  if(53<distance2<60){
    Serial.println("GO_DOWN ST_CASE!! ");
    for(q=3;q>0;q++) // Vibration motor vibrate 
    {
      p2();
    }
     delay(100);
  }
   Serial.print("S2"); Serial.println(distance2);
}

void small_pit() // A pit less than a ascesnt of a stair
{
  int q; // Number of times on motor pattern
  if(46<distance2<53){
    Serial.print("SMALL PIT !! ");  
    for(q=3;q>0;q++) // Vibration motor vibrate 
    {
      p3();
    }  
     delay(100);
  }
  Serial.print("S2"); Serial.println(distance2);
}

void large_pit() // A pit more than a ascesnt of a stair
{
  int q; // Number of times on motor pattern
  if(60<distance2<100){
    Serial.print("LARGE PIT !! "); 
    for(q=3;q>0;q++) // Vibration motor vibrate 
    {
      p3();
    }   
     delay(100);
  }
  Serial.print("S2"); Serial.println(distance2);
}

void small_elevation() // Slightly elevated from ground level, less than a stair
{
  int q; // Number of times on motor pattern
  if(35<distance2<40){
    Serial.print("Small_Elevation !! ");
    for(q=3;q>0;q++) // Vibration motor vibrate 
    {
      p4();
    }    
     delay(100);
  }
  Serial.print("S2"); Serial.println(distance2);
}

void large_elevation() // Rapid elevated from ground level, more than a stair
{
  int q; // Number of times on motor pattern
  if(0<distance2<20){
    Serial.print("Small_Elevation !! ");
    for(q=3;q>0;q++) // Vibration motor vibrate 
    {
      p4();
    }    
     delay(100);
  }
  Serial.print("S2"); Serial.println(distance2);
}

void stairCase_obstacle() // Go down starcase with front obstacle
{
  int q; // Number of times on motor pattern
  if(23<distance2<35 && distance3<12){
    Serial.print("Front_Obstacle & Down_Stair !! "); 
    for(q=3;q>0;q++) // Vibration motor vibrate 
    {
      p7();
    }   
     delay(100);
  }
  Serial.print("S2"); Serial.println(distance2);
}

 void clean_Wall() // Large obstale infront
 {
  int q; // Number of times on motor pattern
  int y; // US 3 distance
  int x; // US 1 distance
 
  if(y<1500)
  {
    if(y=x+22) // Both of US1 & US2 are take same distance from US1
    {
      Serial.print("Clean_Wall");
      Serial.print("S1"); Serial.print(distance1);
      Serial.print("S3"); Serial.print(distance3);
      for(q=3;q>0;q++) // Vibration motor vibrate 
    {
      p5();
    }
      delay(100);
    }   
  }
  if(x!=y && distance1<20 && distance3<58) // For bend of a staircase
  {
    Serial.print("Stare Or Obstacle");
    Serial.print("S1"); Serial.print(distance1);
    Serial.print("S3"); Serial.print(distance3);
    for(q=3;q>0;q++) // Vibration motor vibrate 
    {
      p6();
    }
    delay(100);
  }
 }

//------------------------Vibration motor patterns----------------------------//

void p1() // Pattern for for climb a staircase  
{
   int i=0;
   for(i=255;i>0;i--)
  {
    analogWrite(enable, i); 

    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(2);
  }
    delay(100);
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(100);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(100);
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(100);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(100);
}

void p2() // Pattern for To going down a staircase  
{
   int i=0;
   for(i=255;i>0;i--)
  {
    analogWrite(enable, i); 

    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(2);
  }
    delay(400);
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(400);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(400);
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(400);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(400);
}

void p3() // Pattern for A pit less than a ascesnt of a stair & A pit more than a ascesnt of a stair 
{    
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(200);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(200);
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(200);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(200);
}

void p4() // Pattern for Slightly elevated from ground level, less than a stair & Rapid elevated from ground level, more than a stair
{    
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(500);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(300);
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(500);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(300);
}

void p5() // Pattern for Large obstale infront (Clean wall)
{    
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(2000);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(500);
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(2000);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(500);
}

void p6() // Pattern for For bend of a staircase
{    
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(500);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(100);
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(100);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(100);
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(100);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(100);
}

void p7() // Pattern for Go down starcase with front obstacle
{    
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(500);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(100);
    digitalWrite(motor_1, HIGH);
    digitalWrite(motor_2, LOW);   
    delay(500);
    digitalWrite(motor_1, LOW);
    digitalWrite(motor_2, LOW);   
    delay(100);
}
