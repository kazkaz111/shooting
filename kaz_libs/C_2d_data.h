#pragma once
#include <cmath>
#include "DxLib.h"

class C_2d_vector
{
public:
	C_2d_vector(void);
	C_2d_vector(float in_x, float in_y);
	C_2d_vector operator+(const C_2d_vector& obj);
	C_2d_vector operator-(const C_2d_vector& obj);
	C_2d_vector operator*(const float& scaler);
	C_2d_vector operator/(const float& scaler);
	C_2d_vector& operator+=(const C_2d_vector& obj);
	C_2d_vector& operator-=(const C_2d_vector& obj);
	C_2d_vector& operator*=(const float& scaler);
	C_2d_vector& operator/=(const float& scaler);
	float get_length(void);
	void rotate(float rad);
	float x;
	float y;
};

C_2d_vector::C_2d_vector(void){
	this->x=this->y=0;
	return;
}

C_2d_vector::C_2d_vector(float in_x, float in_y){
	this->x=in_x;
	this->y=in_y;
	return;
}

C_2d_vector C_2d_vector::operator+(const C_2d_vector& obj){
	C_2d_vector tmp;
	tmp.x=this->x+obj.x;
	tmp.y=this->y+obj.y;
	return tmp;
}

C_2d_vector C_2d_vector::operator-(const C_2d_vector& obj){
	C_2d_vector tmp;
	tmp.x=this->x-obj.x;
	tmp.y=this->y-obj.y;
	return tmp;
}

C_2d_vector C_2d_vector::operator*(const float& scaler){
	C_2d_vector tmp;
	tmp.x=this->x*scaler;
	tmp.y=this->y*scaler;
	return tmp;
}

C_2d_vector C_2d_vector::operator/(const float& scaler){
	C_2d_vector tmp;
	tmp.x=this->x/scaler;
	tmp.y=this->y/scaler;
	return tmp;
}

C_2d_vector& C_2d_vector::operator+=(const C_2d_vector& obj){
	this->x+=obj.x;
	this->y+=obj.y;
	return *this;
}

C_2d_vector& C_2d_vector::operator-=(const C_2d_vector& obj){
	this->x-=obj.x;
	this->y-=obj.y;
	return *this;
}

C_2d_vector& C_2d_vector::operator*=(const float& scaler){
	this->x*=scaler;
	this->y*=scaler;
	return *this;
}

C_2d_vector& C_2d_vector::operator/=(const float& scaler){
	this->x/=scaler;
	this->y/=scaler;
	return *this;
}

float C_2d_vector::get_length(void){
	return sqrt(pow(this->x,(int)(2))+pow(this->y,(int)(2)));
}

void C_2d_vector::rotate(float rad){
	C_2d_vector tmp;
	tmp.x=-sin(rad)*this->y+cos(rad)*this->x;
	tmp.y=cos(rad)*this->y+sin(rad)*this->x;
	*this=tmp;
	return;
}





C_2d_vector To_C_2d_vector(float x , float y){
	C_2d_vector tmp;
	tmp.x=x;
	tmp.y=y;
	return tmp;
}





class C_2d_box{
public:
	C_2d_box(void);
	C_2d_box(C_2d_vector in_pos , C_2d_vector in_size);
	C_2d_vector pos;
	C_2d_vector size;
	void draw(int color,int fillflag);
};

C_2d_box::C_2d_box(void){
	pos=To_C_2d_vector(0,0);
	size=To_C_2d_vector(0,0);
	return;
}

C_2d_box::C_2d_box(C_2d_vector in_pos , C_2d_vector in_size){
	pos=in_pos;
	size=in_size;
	return;
}


inline void C_2d_box::draw(int color,int fillflag){
	DrawBox(pos.x,pos.y,pos.x+size.x,pos.y+size.y,color,fillflag);
	return;
}

C_2d_box To_C_2d_box(C_2d_vector in_pos , C_2d_vector in_size){
	C_2d_box tmp;
	tmp.pos=in_pos;
	tmp.size=in_size;
	return tmp;
}

inline bool hitchk_box_box(C_2d_box in_1,C_2d_box in_2){
	if(in_1.pos.x < in_2.pos.x+in_2.size.x && in_2.pos.x < in_1.pos.x+in_1.size.x && in_1.pos.y < in_2.pos.y+in_2.size.y && in_2.pos.y < in_1.pos.y+in_1.size.y) return true;
	return false;
}

void hitchk_box_box(C_2d_box in_1,C_2d_box in_2,bool* x_flag,bool*y_flag){
	if(in_1.pos.x < in_2.pos.x+in_2.size.x && in_2.pos.x < in_1.pos.x+in_1.size.x){
		*x_flag=true;
	}else{
		*x_flag=false;
	}
	if(in_1.pos.y < in_2.pos.y+in_2.size.y && in_2.pos.y < in_1.pos.y+in_1.size.y){
		*y_flag=true;
	}else{
		*y_flag=false;
	}
	return;
}

class C_2d_circle{
public:
	C_2d_circle(void);
	C_2d_circle(C_2d_vector in_pos,float in_r);
	C_2d_vector pos;
	float r;
	void draw(int color, int fillflag);
};

C_2d_circle::C_2d_circle(void){
	pos=To_C_2d_vector(0,0);
	r=0;
	return;
}

C_2d_circle::C_2d_circle(C_2d_vector in_pos,float in_r){
	pos=in_pos;
	r=in_r;
	return;
}

inline void C_2d_circle::draw(int color, int fillflag){
	DrawCircle(pos.x,pos.y,r,color,fillflag);
	return;
}

C_2d_circle To_C_2d_circle(C_2d_vector 
	in_pos,float in_r){
	C_2d_circle tmp;
	tmp.pos=in_pos;
	tmp.r=in_r;
	return tmp;
}

inline bool hitchk_circle_circle(C_2d_circle in_1,C_2d_circle in_2){
	if((pow(in_1.pos.x-in_2.pos.x,(int)2)+pow(in_1.pos.y-in_2.pos.y,(int)2))<(pow(in_1.r+in_2.r,(int)2))) return true;
	return false;
}
