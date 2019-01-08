//Library written by Marvin M. Vargas. 01/21019.
//MicroRobot is a library used to move a a robot with two Pololu´s micromotors by rotations.

#ifndef microRobot
#define microRobot
#define a1 2
#define a2 3
#define ENCODER_TICKS 6

#include<Arduino.h>
#include<Wconstants.h>

class microRobot(){
	public:
		bool microRobot(uint8_t b1,uint8_t b2,uint8_t M1,uint8_t M2,uint8_t M3,uint8_t M4, uint32_t gearRel);
		void moveRot(int rot,char dir);
	private:
		float count();
		uint8_t b1,b2,M1,M2,M3,M4;
		uint64_t counter1,counter2;
		float r1,r2;
}