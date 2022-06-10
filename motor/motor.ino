#define E1 3  // Enable Pin for motor 1

 
#define I1 9  // Control pin 1 for motor 1
#define I2 8  // Control pin 2 for motor 1
int i;
 
void setup() {
 
    pinMode(E1, OUTPUT);
  
 
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);

}
 
void loop() {

motor_pattern_wall();
   
}

void motor_pattern_pit()
{
   for(i=255;i>0;i--)
  {
    analogWrite(E1, i); // Run in half speed

    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);   
    delay(2);
  }
}

void motor_pattern_wall()
{
   for(i=255;i>0;i--)
  {
    analogWrite(E1, i); // Run in half speed

    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);   
    delay(10);
   
  }
  analogWrite(E1, 255);
   digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);   
    delay(500);
    digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);   
    delay(500);
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);   
    delay(500);
    digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);   
    delay(500);
}
