#pragma config(Motor,  port1,           rightF,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port2,           rightB,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftF,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftB,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rampMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           upArmMotorR,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           upArmMotorL,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           armMotor,      tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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

void autonomous(){
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

task main(){
		//Auto
		autonomous();
	}
