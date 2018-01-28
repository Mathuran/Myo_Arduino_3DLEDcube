#include <MyoController.h>


#include "led.h"
#include "cube.h"
//#include "button.h"
//#include "pitches.h"

int inhib = 5;
int inhib2 = 9;
int passed = 0 ;
int start;
int Final;
int Time;

int a = 1;
int faceArray[64];
int faceON[4] = {5, 8, 12, 9};

bool gameover = false;

cube CUBE = cube();
led LED = led();
//button BUTTON = button();

MyoController myo = MyoController(); //myo Controller object
int previous = 6;

void setup() {
  //Set ports [0, 12] as output ports
  for (int port = 0; port <= 12; port++) {
    pinMode(port, OUTPUT);
  }
  //Set ports [A0, A5] as input ports
  for (int port = 14; port <= 19; port++) {
    pinMode(port, INPUT);
  }
  myo.initMyo(); //initialize myo

  Serial.begin(9600);
  //randomSeed(analogRead(0));
  Serial.println("start");

}
///////////////////////////////////////////////////VOID LOOP///////////////////////
void loop() {

  myo.updatePose();
  
  
  myo.updatePose();

  //CUBE.diagonalcube(100, 200);
if (previous == myo.getCurrentPoseInt()) {
    myo.setCurrentPose(0);
  }


  switch ( myo.getCurrentPose() ) {
    case rest:
      //Stuff for rest gesture
      break;
    case fist:
      //Stuff for fist gesture
      if (a - 10 > 0) {
        a -= 10;
      }
      break;
    case waveIn:
      //Stuff for waveIn gesture
      if (a + 1 < 27) {
        a++;
      }
      break;
    case waveOut:
      //Stuff for waveOut gesture
      if (a - 1 > 0) {
        a -= 1;
      }
      break;
    case fingersSpread:
      //Stuff for fingersSpread gesture
      if (a + 10 < 27) {
        a += 10;
      }
      break;
    case doubleTap:
      //Stuff for doubleTap gesture
      //a = 1;
      break;
    default:
      //default action

      break;
  }
  CUBE.twoCUBEtimed(a, 50);
  //delay(5);
}



















