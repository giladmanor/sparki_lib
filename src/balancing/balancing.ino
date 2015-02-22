/*******************************************
 Basic Accelerometer Sensor test
 
 Sparki has a 3-Axis accelerometer. It is 
 used to detect the acceleration Sparki is 
 experiencing. Usually, this mostly means the
 force of gravity. It can do this in all 
 3 XYZ axis, which are left/right (X), 
 forward/backwards (Y), and up/down (Z). This 
 is the same part that smartphones use to tell
 how you’re tilting them.
 
 This program shows how to read the sensor
 and display the information on the LCD.
 
 http://arcbotics.com/products/sparki/parts/accelerometer/
********************************************/
#include <Sparki.h> // include the sparki library

void setup() 
{
}

void loop() {
  sparki.clearLCD(); // wipe the screen
  sparki.moveStop();
  float y  = sparki.accelY();   // measure the accelerometer y-axis
  
  // write the measurements to the screen
  
  //sparki.print("Accel Y: "); 
  //sparki.println(y);
  
  if(y<-0.1){
    sparki.moveBackward();

    sparki.println("-");
  }
  if(y>0.1){
    sparki.moveForward();    
    sparki.println("+");
  }
  
  sparki.updateLCD(); // display all of the information written to the screen
  delay(10);
}
