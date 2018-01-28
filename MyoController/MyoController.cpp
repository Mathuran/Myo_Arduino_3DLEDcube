#include "MyoController.h"
/**
 * @brief Constructor - Instantiates MyoController object
 */
MyoController::MyoController()
{
	msgChar=String("");
}

/**
 * @brief Destructor
 */
MyoController::~MyoController()
{

}
bool MyoController::initMyo(){
	Serial.begin(9600);
	return true;	
}

bool MyoController::updatePose(){
	if (Serial.available())
	{
		storageStr = String("");
		while(Serial.available())
		{
			storageStr = storageStr + char(Serial.read());
			delay(1);
		}

		msgChar = storageStr;
		//Serial.print(msgChar);

	}

	if(msgChar.indexOf("rest")>=0)
	{
		current_pose_=rest;
	}
	else if (msgChar.indexOf("fist")>=0)
	{
		current_pose_=fist;
	}
	else if (msgChar.indexOf("waveIn")>=0)
	{
		current_pose_=waveIn;
	} 
	else if (msgChar.indexOf("waveOut")>=0)
	{
		current_pose_=waveOut;
	} 
	else if (msgChar.indexOf("fingersSpread")>=0)
	{
		current_pose_=fingersSpread;
	} 
	else if (msgChar.indexOf("doubleTap")>=0)
	{
		current_pose_=doubleTap;
	} 
	else
	{
		current_pose_=unknown;
	}
}
Poses MyoController::getCurrentPose(){
	return current_pose_;
}
int MyoController::getCurrentPoseInt(){
	switch ( current_pose_ ) {
	    case rest:
	      return 0; 
	      break;
	    case fist:
	      return 1;
	      break;
	    case waveIn:
	      return 2;
	      break;
	    case waveOut:
	      return 3;
	      break;
	    case fingersSpread:
	      return 4;
	      break;
	    case doubleTap:
	      return 5;
	      break;
	    case unknown:
	      return 6;
	      break;
	 }
}
void MyoController::setCurrentPose(int x){
	switch (x){
		case 0:
			current_pose_=rest;
		break;
		case 1:
			current_pose_=fist;
		break;
		case 2:
			current_pose_=waveIn;
		break;
		case 3:
			current_pose_=waveOut;
		break;
		case 4:
			current_pose_=fingersSpread;
		break;
		case 5:
			current_pose_=doubleTap;
		break;
		case 6:
			current_pose_=unknown;
		break;
		
	}
}
