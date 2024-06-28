//  this module interacts with the hardware on lower level
#include <MD_MAX72xx.h>

//  this module helps to display patterns and animations easily
#include <MD_Parola.h>
#include <SPI.h>

const byte clock_pin = 13;
const byte data_pin = 11;
const byte chip_select_pin = 10;
const byte max_devices = 4;

/* creating instance of MD_Parola class : 
Hardware type : PAROLA_HW
Max devices : number of devices we are using */
MD_Parola matrix = MD_Parola(MD_MAX72XX::PAROLA_HW, chip_select_pin, max_devices);

void setup(){

  Serial.begin(9600);
  matrix.begin();  //  initialise the module
  matrix.displayClear();  //  clear, if there is anything
}

void loop(){

  //  displayAnimate returns true when animation is finished
  //  we then reset the animation
  if (matrix.displayAnimate()){
    matrix.displayText("Daisy", PA_CENTER, 50, 2000, PA_RANDOM, PA_RANDOM);
  }

}