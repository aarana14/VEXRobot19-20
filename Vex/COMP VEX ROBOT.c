#pragma config(Motor,  port2,           rightF,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightB,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftF,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftB,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rampMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           upArmMotorR,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           upArmMotorL,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           armMotor,      tmotorVex393_MC29, openLoop)

#pragma platform(VEX2)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"

//User Fuctions
void rampMove(){
	if (vexRT[Btn7U] == 1){
		motor[rampMotor] = 100;
	}
	else if (vexRT[Btn7D] == 1){
		motor[rampMotor] = -100;
	}

	else{
		motor[rampMotor] = 0;
	}
}

void armMovement(){
	if (vexRT[Btn6U] == 1){
		motor[armMotor] = 80;
	}
	else if (vexRT[Btn6D] == 1){
		motor[armMotor] = -80;
	}
	else {
		motor[armMotor] = 0;
	}
}

void armMoveBox(){
	if (vexRT[Btn5U] == 1){
		motor[upArmMotorR] = 120;
		motor[upArmMotorL] = 120;
	}
	else if (vexRT[Btn5D] == 1){
		motor[upArmMotorR] = -120;
		motor[upArmMotorL] = -120;
	}
	else {
		motor[upArmMotorR] = 0;
		motor[upArmMotorL] = 0;
	}
}

void stopMove(){
	motor[rightF] = 0;
	motor[rightB] = 0;
	motor[leftF] = 0;
	motor[leftB] = 0;
	wait1Msec(100);
}

void fMove(){
	motor[rightF] = 120;
	motor[rightB] = 120;
	motor[leftF] = 120;
	motor[leftB] = 120;
}

void lMove(){
	motor[rightF] = 120;
	motor[rightB] = 120;
	motor[leftF] = -120;
	motor[leftB] = -120;
}

void rMove(){
	motor[rightF] = -120;
	motor[rightB] = -120;
	motor[leftF] = 120;
	motor[leftB] = 120;
}

//Competition Functions

void pre_auton()
{
  bStopTasksBetweenModes = true;
}

task autonomous()
{
		fMove();
		wait1Msec(150);
		lMove();
		wait1Msec(782);
		stopMove();
	  fMove();
		wait1Msec(1900);
		stopMove();
		rMove();
		wait1Msec(782);
		stopMove();
		fMove();
		motor[upArmMotorR] = 120;
		motor[upArmMotorL] = 120;
		wait1Msec(2300); //2300
		stopMove();
		lMove();
		wait1Msec(782);
		stopMove();
		fMove();
		wait1Msec(830);
		stopMove();
		lMove();
		wait1Msec(782);
		stopMove();
		fMove();
		wait1Msec(2300);
		stopMove();
		motor[rampMotor] = 60;
		wait1Msec(1200);
}

task usercontrol(){
  while (true){
    //Movement Control
		motor[rightF] = vexRT[Ch2];
		motor[rightB] = vexRT[Ch2];
		motor[leftF] = vexRT[Ch3];
		motor[leftB] = vexRT[Ch3];

		//Control the 2 arm motors
		armMoveBox();

		//Control the arm up and down
		armMovement();

		//Ramp Thrust
		rampMove();
  }
}
