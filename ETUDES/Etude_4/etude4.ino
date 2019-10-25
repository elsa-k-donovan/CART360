#include <Keyboard.h>;

#define PUSH_PIN A4
int scale = 3;
float mouseSpeed = 20.0;



/* KEY arrow variables for windows and linux*/

/**
    char keyLeft = KEY_LEFT_ARROW;
    char keyRight = KEY_RIGHT_ARROW;
    char keyUp = KEY_UP_ARROW;
    char keyDown = KEY_DOWN_ARROW;
*/

/* KEY arrow variables for OS X*/
    char keyLeft = KEY_LEFT_ARROW;
    char keyRight = KEY_RIGHT_ARROW;
    char keyUp = KEY_UP_ARROW;
    char keyDown = KEY_DOWN_ARROW;
  

void setup()
{

  //Serial.begin(9600); 
  Keyboard.begin();

  
}

void loop()
{

 
  int val = analogRead(PUSH_PIN);
  Serial.println(val);
     
  // Get raw accelerometer data for each axis
  int rawX = analogRead(A0);
  int rawY = analogRead(A1);                                                   
  // int rawZ = analogRead(A2);
   

  
  float scaledX, scaledY, scaledZ; // Scaled values for each axis
  scaledX = mapf(rawX, 0, 675, -scale, scale); // 3.3/5 * 1023 =~ 675
  scaledY = mapf(rawY, 0, 675, -scale, scale);
  
  delay(20); // Minimum delay of 2 milliseconds between sensor reads (500 Hz)


   

              if (scaledX < 0.2 && scaledX > -0.2){
                scaledX = 0;
              }
              if (scaledY < 0.2 && scaledY > -0.2){
                scaledY = 0;
              }
            
            
                if(scaledX > 0 && scaledX < 0.6){
         
                  if (val > 600) { 
                  Keyboard.press(keyRight);
                  //Serial.println("Right");
                  }
        
                }


                
                else if(scaledX < 0 && scaledX > -0.6){
                    
                    if (val > 600) {
                    Keyboard.press(keyLeft);
                     //Serial.println("Left");
                    }
        
                }
                else {
                  //Serial.print("no X coordinate.");
                }
            
            
            
                if(scaledY > 0 && scaledY < 0.6){
                    if (val > 600) {
                     Keyboard.press(keyUp); 
                      // Serial.println("Up");
                      }
                }
               else if (scaledY < 0 && scaledY > -0.8) {
                    if (val > 600) {
                     Keyboard.press(keyDown);
                     //Serial.println("Down");
                     }
                }
                else {
                   //Serial.print("no valid Y coordinates.");
                }


    
    // delay(600);
    // if (analog threshold it at a certain threshold) then release the key
    //(0 - 1023)


    while (val > 600){
     delay(30);
     val = analogRead(PUSH_PIN);
      }


        
  Keyboard.releaseAll();  //release all keys

    //change this so that it triggers an arrow key instead
}


// Same functionality as Arduino's standard map function, except using floats
float mapf(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
