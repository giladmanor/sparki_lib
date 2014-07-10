#include <Sparki.h> // include the sparki library

void setup()
{
}

void loop()
{
    sparki.clearLCD();
    sparki.moveForward();
    int cm = sparki.ping(); // measures the distance with Sparki's eyes
    
    sparki.print("Distance: "); 
    sparki.print(cm); // tells the distance to the computer
    sparki.println(" cm"); 
    
    if(cm != -1) // make sure its not too close or too far
    { 
        if(cm < 30) // if the distance measured is less than 10 centimeters
        {
            sparki.moveStop();
            sparki.servo(SERVO_LEFT);
            delay(1000);
            int maxDist = 0;
            int maxIndex = 0;
            for (int i = 0; i < 6; i=i+1){
              cm=sparki.ping();
              if(cm!=-1){
                sparki.beep(cm*10);
                if(maxDist<cm){
                  maxDist = cm;
                  maxIndex = i;
                }
              }
              
              sparki.servo(i*30);
              sparki.noBeep();
              delay(1000);
            }
            sparki.servo(0);
            
            
            
        }
        
    }
    
    sparki.updateLCD();
    delay(100); // wait 0.1 seconds (100 milliseconds)
}


