/* ----------------------------------------------------------------------------

File:	RootsAGV.cpp
Author:	Guiilherme Gomes & Lorenzo Giordano
Date:	07/Oct/2016

Description:
  An API to drive a two-wheel differential mobile robot.


Commands:


---------------------------------------------------------------------------- */

#include <RootsAGV.h>
#include <Arduino.h>


RootsAGV::RootsAGV(byte p_leftPWM, byte p_left1, byte p_left2, byte p_rightPWM, byte p_right1, byte p_right2) {

    this->leftPWM = p_leftPWM;
    this->left1 = p_left1;
    this->left2 = p_left2;
    this->rightPWM = p_rightPWM;
    this->right1 = p_right1;
    this->right2 = p_right2;
    
    pinMode(this->leftPWM, OUTPUT);
    pinMode(this->left1, OUTPUT);
    pinMode(this->left2, OUTPUT);
    pinMode(this->rightPWM, OUTPUT);
    pinMode(this->right1, OUTPUT);
    pinMode(this->right2, OUTPUT);
  
}

void RootsAGV::rightWhellFront() {
    digitalWrite(this->right1, LOW);
    digitalWrite(this->right2, HIGH);  
}

void RootsAGV::rightWhellReverse() {
    digitalWrite(this->right1, HIGH);
    digitalWrite(this->right2, LOW);  
}

void RootsAGV::leftWhellFront() {
    digitalWrite(this->left1, LOW);
    digitalWrite(this->left2, HIGH);  
}

void RootsAGV::leftWhellReverse() {
    digitalWrite(this->left1, HIGH);
    digitalWrite(this->left2, LOW);  
}

void RootsAGV::setOffset(byte value) {
    this->offset = value;
}

void RootsAGV::setLimit(byte value) {
    this->limit = value;
}

void RootsAGV::moveRobot(int speed, int wheel) {
  
    int leftSpeed, rightSpeed;
    
    leftSpeed = speed + wheel;
    rightSpeed = speed - wheel;
    
    // left whell
    if(leftSpeed > 0) {
	  leftWhellFront();
    }
    else {
	  leftWhellReverse();
	  leftSpeed = abs(leftSpeed);
    }
    
    if(leftSpeed > 0) {
        leftSpeed += offset;
    }
    
    if(leftSpeed > this->limit) {
	  leftSpeed = this->limit;
    }
    // left whell - end
    
    // right whell
    if(rightSpeed > 0) {
	  rightWhellFront();  
    }
    else {
	  
	  rightWhellReverse();
	  rightSpeed = abs(rightSpeed);
    }
    
    if(rightSpeed > 0) {
        rightSpeed += offset;
    }
    
    if(rightSpeed > this->limit) {
	  rightSpeed = this->limit;
    }
    // right whell - end
    
    analogWrite(this->leftPWM, leftSpeed);
    analogWrite(this->rightPWM, rightSpeed);
}
