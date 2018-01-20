/* ----------------------------------------------------------------------------

File:	RootsAGV.h
Author:	Guilherme Gomes & Lorenzo Giordano
Date:	07/Oct/2016

Description:
  An API to drive a two-wheel differential mobile robot.


Constructor paramters:
 - byte p_leftPWM: pin for pwm modulation of left wheel.
 - byte p_left1: pin for signal 1 of left wheel's bridge.
 - byte p_left2: pin for signal 2 of left wheel's bridge.
 - byte p_rightPWM: pin for pwm modulation of right wheel.
 - byte p_right1: pin for signal 1 of right wheel's bridge.
 - byte p_right2: pin for signal 2 of right wheel's bridge.

---------------------------------------------------------------------------- */

#ifndef __ROOTS_AGV
#define __ROOTS_AGV

// Board Type
#define __ARDUINO_UNO
//#define __ARDUINO_MEGA

// Settings
#define __MAX_SPEED 254


#include <Arduino.h>

class RootsAGV {
	
	public:
	  RootsAGV(byte p_leftPWM, byte p_left1, byte p_left2, byte p_rightPWM, byte p_right1, byte p_right2);
      void setOffset(byte value);
	  void setLimit(byte value);
	  void moveRobot(int speed, int wheel);
	  
	private:
	  byte leftPWM, left1, left2, rightPWM, right1, right2, speed, deltaSpeed, offset, limit;
	  void rightWhellFront();
	  void rightWhellReverse();
      void leftWhellFront();
	  void leftWhellReverse();
};

#endif
