#pragma once
#include "C_2d_data.h"

class C_2d_vector_datas{
public:
	C_2d_vector_datas(void);
	C_2d_vector_datas(C_2d_vector in_pos,C_2d_vector in_vec,C_2d_vector in_acc);
	void add_proc(void);
	C_2d_vector pos;
	C_2d_vector vec;
	C_2d_vector acc;
};

C_2d_vector_datas::C_2d_vector_datas(void){
	return;
}

C_2d_vector_datas::C_2d_vector_datas(C_2d_vector in_pos,C_2d_vector in_vec,C_2d_vector in_acc){
	pos=in_pos;
	vec=in_vec;
	acc=in_acc;
	return;
}

void C_2d_vector_datas::add_proc(void){
	pos+=vec;
	vec+=acc;
	return;
}

C_2d_vector_datas To_C_2d_vector_datas(C_2d_vector pos , C_2d_vector vec , C_2d_vector acc){
	C_2d_vector_datas tmp;
	tmp.pos=pos;
	tmp.vec=vec;
	tmp.acc=acc;
	return tmp;
}

