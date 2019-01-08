//Library written by Marvin M. Vargas. 01/2019.
//microRobot is a library used to move a a robot with two Pololu´s micromotors by rotations.

#include<Arduino.h>
#include<microRobot.h>

microRobot::microRobot(uint8_t b1,uint8_t b2,uint8_t M1,uint8_t M2,uint8_t M3,uint8_t M4, uint16_t gearRel){
	_gearRel = gearRel;
	_b1 = b1;
	_b2 = b2;
	_M1 = M1;
	_M2 = M2;
	_M3 = M3;
	_M4 = M4;
	pinMode(a1,INPUT_PULLUP);
	pinMode(b1,INPUT);
	pinMode(a2,INPUT_PULLUP);
	pinMode(b2,INPUT);
	pinMode(M1,OUTPUT);
	pinMode(M2,OUTPUT);
	pinMode(M3,OUTPUT);
	pinMode(M4,OUTPUT);
	attachInterrupt(digitalPinToInterrupt(a1),_count1,CHANGE);
	attachInterrupt(digitalPinToInterrupt(a2),_count2,CHANGE);
}

microRobot::_count1(){
	int fcount=0;
	if(digitalRead(a1) == digitalRead(b1))
		_counter1--;
	else
		_counter1++;
	fcount = counter1/(_gearRel*ENCODER_TICKS);
	_r1 = fcount;
}

microRobot::_count2(){
	int fcount=0;
	if(digitalRead(a2) == digitalRead(b2))
		_counter2--;
	else
		_counter2++;
	fcount = counter1/(_gearRel*ENCODER_TICKS);
	_r2 = fcount;
}

microRobot::moveRot(int rot,char dir){
	_counter1 = 0;
	_counter2 = 0;
	_r1 = 0;
	_r2 = 0;
	if(dir == 'f'){
		while(_r1 <= rot && _r2 <= rot){
			digitalWrite(M1,HIGH);
			digitalWrite(M2,LOW);
			digitalWrite(M3,HIGH);
			digitalWrite(M4,LOW);
		}
		digitalWrite(M1,LOW);
		digitalWrite(M2,LOW);
		digitalWrite(M3,LOW);
		digitalWrite(M4,LOW);
	}
	if(dir == 'b'){
		while(_r1 >= rot*-1 && _r2 >= rot*-1){
			digitalWrite(M1,LOW);
			digitalWrite(M2,HIGH);
			digitalWrite(M3,LOW);
			digitalWrite(M4,HIGH);
		}
		digitalWrite(M1,LOW);
		digitalWrite(M2,LOW);
		digitalWrite(M3,LOW);
		digitalWrite(M4,LOW);
	}
	if(dir == 'l'){
		while(_r1 <= rot && _r2 >= rot*-1){
			digitalWrite(M1,HIGH);
			digitalWrite(M2,LOW);
			digitalWrite(M3,LOW);
			digitalWrite(M4,HIGH);
		}
		digitalWrite(M1,LOW);
		digitalWrite(M2,LOW);
		digitalWrite(M3,LOW);
		digitalWrite(M4,LOW);
	}
	if(dir == 'r'){
		while(_r1 <= rot && _r2 >= rot*-1){
			digitalWrite(M1,LOW);
			digitalWrite(M2,HIGH);
			digitalWrite(M3,HIGH);
			digitalWrite(M4,LOW);
		}
		digitalWrite(M1,LOW);
		digitalWrite(M2,LOW);
		digitalWrite(M3,LOW);
		digitalWrite(M4,LOW);
	}
}
			

	



