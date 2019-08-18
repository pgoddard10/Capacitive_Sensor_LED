#include <CapacitiveSensor.h> //library from https://github.com/PaulStoffregen/CapacitiveSensor

CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8); // 1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

void setup()                    
{
   cs_4_8.set_CS_AutocaL_Millis(0xFFFFFFFF);// turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600); //enable output to the console
   pinMode(7,OUTPUT); //enable pin 7
}

void loop() {
  long sensor1 =  cs_4_8.capacitiveSensor(50); //get reading from capacitive touch pin
  
  if(sensor1>=40) //threshold level
     Serial.println(sensor1);  // print sensor output
  
  if(sensor1 >= 60) { //threshold level
    digitalWrite(7,HIGH); //push signal over pin 7. e.g. turn LED on
  }
  else{
    digitalWrite(7,LOW); //turn signal off. e.g. turn LED off
  } 
}
