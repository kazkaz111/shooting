#pragma once
extern Cpicture enemy_pic;
extern Cpicture enemyfixed_pic;


Ctask_enemynormal::Ctask_enemynormal(const C_2d_vector& in_pos,const C_2d_vector& in_vec){
	cir.pos=in_pos;
	cir.r=15;
	vec=in_vec;
	hp=1;
	timer=0;
	return;
}

bool Ctask_enemynormal::proc(){
	if(Cplayer_ins.hitchk_playerbullet(cir)) hp--;
	if(hp<0) return true;
	cir.pos+=vec;
	timer++;
	if(timer>30){
		timer=0;
		C_2d_vector bullet_vec=Cplayer_ins.get_circle().pos-cir.pos;
		bullet_vec/=bullet_vec.get_length();
		Ctask_Control_ins.add_task(new Ctask_enemybullet_normal(cir.pos,bullet_vec*5));
	}

	return !(chk_in_view(cir));
}

bool Ctask_enemynormal::hitchk(const C_2d_circle& in_cir){
	return hitchk_circle_circle(cir,in_cir);
}

void Ctask_enemynormal::draw(){
	enemy_pic.center_draw(cir.pos);
	return;
}

Ctask_enemy_fixed::Ctask_enemy_fixed(const C_2d_vector& in_pos,const C_2d_vector& in_vec,int in_move_timer){
	cir.pos=in_pos;
	cir.r=40;
	vec=in_vec;
	bullet_timer=0;
	bullet_pattern_timer=0;
	move_timer=in_move_timer;
	hp=100;
	return;
}

bool Ctask_enemy_fixed::proc(void){
	if(Cplayer_ins.hitchk_playerbullet(cir)) hp--;
	if(hp<0) return true;
	if(move_timer>0){
		cir.pos+=vec;
		move_timer--;
	}else{
		bullet_timer++;
		if(bullet_timer>30){
			bullet_timer=0;
			for(int i=0;i<20;i++){
				bullet_pattern_timer++;
				float r=((i*pie)/10)+(bullet_pattern_timer*0.05);
				C_2d_vector bullet_vec;
				bullet_vec.x=sin(r);
				bullet_vec.y=cos(r);
				Ctask_Control_ins.add_task(new Ctask_enemybullet_normal(cir.pos,bullet_vec*5));
			}
		}
	}
	return !(chk_in_view(cir));
}

bool Ctask_enemy_fixed::hitchk(const C_2d_circle& in_cir){
	return hitchk_circle_circle(cir,in_cir);
}

void Ctask_enemy_fixed::draw(void){
	enemyfixed_pic.center_draw(cir.pos);
	return;
}


Ctask_enemybullet_normal::Ctask_enemybullet_normal(const C_2d_vector& in_pos,const C_2d_vector& in_vec){
	cir.r=7;
	cir.pos=in_pos;
	vec=in_vec;
	return;
}

bool Ctask_enemybullet_normal::proc(){
	cir.pos+=vec;
	return !(chk_in_view(cir));
}

bool Ctask_enemybullet_normal::hitchk(const C_2d_circle& in_cir){
	return hitchk_circle_circle(cir,in_cir);
}

void Ctask_enemybullet_normal::draw(void){
	cir.draw(COLOR_RED,TRUE);
	return;
}


Ctask_Control::~Ctask_Control(){
	auto itr=p_task_list.begin();
	while(itr!=p_task_list.end()){
		delete (*itr);
		itr=p_task_list.erase(itr);
	}
	return;
}

void Ctask_Control::clear(){
	auto itr=p_task_list.begin();
	while(itr!=p_task_list.end()){
		delete (*itr);
		itr=p_task_list.erase(itr);
	}
	return;
}

void Ctask_Control::proc(){
	auto itr=p_task_list.begin();
	while(itr!=p_task_list.end()){
		if((*(*itr)).proc()){
			delete (*itr);
			itr=p_task_list.erase(itr);
		}else{
			itr++;
		}
	}
	return;
}

bool Ctask_Control::hitchk_all(const C_2d_circle& in_cir){
	auto itr=p_task_list.begin();
	while(itr!=p_task_list.end()){
		if((*(*itr)).hitchk(in_cir)){
			//delete (*itr);
			//itr=p_task_list.erase(itr);
			itr++;
			return true;
		}else{
			itr++;
		}
	}
	return false;
}

void  Ctask_Control::draw(){
	auto itr=p_task_list.begin();
	while(itr!=p_task_list.end()){
		(*(*itr)).draw();
		itr++;
	}
}

void Ctask_Control::add_task(Ctask* new_pointer){
	p_task_list.push_front(new_pointer);
	return;
}

int Ctask_Control::show_number(){
	return p_task_list.size();
}