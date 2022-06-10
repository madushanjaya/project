//Intelligent Assisting Stick for Visual Impaired
// ---------------------------------------------------------------- //

#define echoPin1 8 //Sensor 01 Echo pin
#define trigPin1 9 //Sensor 01 Trig pin
#define echoPin2 10 // Sensor 02 Echo pin
#define trigPin2 11 //Sensor 02 Trig pin
#define echoPin3 12 // Sensor 03 Echo pin
#define trigPin3 13 //Sensor 03 Trig pin


//---------------------defines variables-------------------------//
long duration1; //(sensor 01) variable for the duration of sound wave travel
int distance1; //(sensor 01) variable for the distance measurement

long duration2; //(sensor 02) variable for the duration of sound wave travel
int distance2; // (sensor 02)variable for the distance measurement

long duration3; //(sensor 03) variable for the duration of sound wave travel
int distance3; // (sensor 03)variable for the distance measurement


void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT

  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin2, INPUT); // Sets the echoPin as an INPUT
  
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin3, INPUT); // Sets the echoPin as an INPUT
 
  Serial.begin(9600); 

}
void loop() {
  
  //SENSOR 01
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  //SENSOR 02
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microsecon
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  
  //FOR SENSOR NO3
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
 
 findFrontDiffennce();
 findFrontStair();
 findFrontWala();

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

void findFrontDiffennce(){
  if(distance3<30 ){
    Serial.println("WALL ");
    delay(1000);
  }

  //Serial.print(distance1);
}

void findFrontStair(){
  if(distance2<35 && distance1<15){
    Serial.println("PADIPELA!!");
     delay(1000);
  }

  //Serial.print(distance1);
}

void findFrontWala(){
  if(40<distance2 ){
    Serial.print(" WALA!!");
    Serial.print(distance2);
    Serial.println(" cm  ");
    
     delay(1000);
  }

  //Serial.print(distance1);
}
//chin
