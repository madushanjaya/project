#define E1 10  // Enable Pin for motor 1

 
#define I1 9  // Control pin 1 for motor 1
#define I2 8  // Control pin 2 for motor 1

 
void setup() {
 
    pinMode(E1, OUTPUT);
  
 
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);

}
 
void loop() {
 
    analogWrite(E1, 255); // Run in half speed

    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);   
    delay(4000);
    digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);  
    delay(2000);
   
   
}
