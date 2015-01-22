#pragma once
extern int key;
extern Cpicture player_pic;
extern Cpicture player_bullet_pic;
inline bool chk_in_view(C_2d_circle in_cir);

extern Ctask_Control Ctask_Control_ins;

Cplayer_normalbullet::Cplayer_normalbullet(const C_2d_vector& in_pos,const C_2d_vector& in_vec){
	cir.pos=in_pos;
	cir.r=7;
	vec=in_vec;
	return;
}

bool Cplayer_normalbullet::proc(void){
	cir.pos+=vec;
	if(chk_in_view(cir)) return false;
	return true;
}

bool Cplayer_normalbullet::hitchk(const C_2d_circle& in_cir){
	if(hitchk_circle_circle(cir,in_cir)) return true;
	return false;
}

void Cplayer_normalbullet::draw(void){
	player_bullet_pic.center_draw(cir.pos);
	return;
}



Cplayer::Cplayer(){
	cir.pos=To_C_2d_vector(400,500);
	cir.r=10;
	bullet_timer=0;
	reborn_timer=0;
	hp=3;
	//pic=player_pic;
	return;
}

Cplayer::~Cplayer(){
	auto itr=p_bullet_list.begin();
	while(itr!=p_bullet_list.end()){
			delete (*itr);
			itr=p_bullet_list.erase(itr);
	}
	return;
}

void Cplayer::clear(){
	auto itr=p_bullet_list.begin();
	while(itr!=p_bullet_list.end()){
			delete (*itr);
			itr=p_bullet_list.erase(itr);
	}
	cir.pos=To_C_2d_vector(400,500);
	cir.r=10;
	bullet_timer=0;
	reborn_timer=0;
	hp=3;
	return;
}


bool Cplayer::proc(void){
	C_2d_vector mov;
	bool x_flag=false,y_flag=false;
	if(key&PAD_INPUT_UP){
		mov.y-=7;
		y_flag=true;
	}
	if(key&PAD_INPUT_DOWN){
		mov.y+=7;
		y_flag=true;
	}
	if(key&PAD_INPUT_RIGHT){
		mov.x+=7;
		x_flag=true;
	}
	if(key&PAD_INPUT_LEFT){
		mov.x-=7;
		x_flag=true;
	}
	if(x_flag&&y_flag) mov/=sqrt_2;
	C_2d_vector before_pos=cir.pos;
	cir.pos+=mov;
	if(((cir.pos.x<cir.r)||(cir.pos.x>scr_x-cir.r)||(cir.pos.y<cir.r)||(cir.pos.y>scr_y-cir.r))) cir.pos=before_pos;
	bullet_timer++;
	if((key&PAD_INPUT_1)&&(bullet_timer>5)){
		p_bullet_list.push_front(new Cplayer_normalbullet(To_C_2d_vector(cir.pos.x+10,cir.pos.y),To_C_2d_vector(0,-15)));
		p_bullet_list.push_front(new Cplayer_normalbullet(To_C_2d_vector(cir.pos.x-10,cir.pos.y),To_C_2d_vector(0,-15)));
		bullet_timer=0;
	}

	auto itr=p_bullet_list.begin();

	while(itr!=p_bullet_list.end()){
		if((*(*itr)).proc()){
			delete (*itr);
			itr=p_bullet_list.erase(itr);
		}else{
			itr++;
		}
	}
	if(Ctask_Control_ins.hitchk_all(cir)&&reborn_timer>=0){
		reborn_timer=-120;
		hp--;
		cir.pos=To_C_2d_vector(400,500);
	}
	if(reborn_timer<=0) reborn_timer++;
	return (hp<0);
}

void Cplayer::draw(void){
	auto itr=p_bullet_list.begin();
	while(itr!=p_bullet_list.end()){
		(*(*itr)).draw();
		itr++;
	}
	if(reborn_timer<=0&&(-reborn_timer%14)>7) return;
		player_pic.center_draw(cir.pos);
	return;
}

C_2d_circle Cplayer::get_circle(void){
	return cir;
}

bool Cplayer::hitchk_playerbullet(const C_2d_circle& in_cir){
	auto itr=p_bullet_list.begin();
	while(itr!=p_bullet_list.end()){
		if((*(*itr)).hitchk(in_cir)){
			delete (*itr);
			p_bullet_list.erase(itr);
			return true;
		}else{
			itr++;
		}

	}
	return false;
}

int Cplayer::show_bullet_number(void){
	return p_bullet_list.size();
}

int Cplayer::show_hp(){
	return hp;
}