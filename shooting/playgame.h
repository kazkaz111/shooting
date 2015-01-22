#pragma once
#include"Cplayer.h"
extern int key;
extern Cpicture player_pic;
extern Cpicture black_hool_pic;
extern Cstage Cstage_ins;

extern Cplayer Cplayer_ins;
enum game_status{
	st_menu,
	st_option,
	st_game
}now_status=st_menu;


void game_proc(void);

void game_draw(void);

void game_proc(void){
	if(Cplayer_ins.proc()){
		Cstage_ins.clear();
		Cplayer_ins.clear();
		Ctask_Control_ins.clear();
		now_status=st_menu;
		MessageBox(NULL,"You are lose","You are lose",MB_OK);
	}
	if(Cstage_ins.proc()){
		Cplayer_ins.clear();
		Ctask_Control_ins.clear();
		now_status=st_menu;
		MessageBox(NULL,"You are win","You are win",MB_OK);
	}
	Ctask_Control_ins.proc();
	return;
}

void game_draw(void){
	black_hool_pic.draw(0,0);
	Cplayer_ins.draw();
	Ctask_Control_ins.draw();
	DrawFormatString(0, 15,GetColor(255,255,255),"playerbullt_task:%d",Cplayer_ins.show_bullet_number());
	DrawFormatString(0, 30,GetColor(255,255,255),"task:%d",Ctask_Control_ins.show_number());
	DrawFormatString(0, 45,GetColor(255,255,255),"HP:%d",Cplayer_ins.show_hp());
	return;
}

inline bool chk_in_view(C_2d_circle in_cir){
	if((in_cir.pos.x<-in_cir.r)||(in_cir.pos.x>scr_x+in_cir.r)||(in_cir.pos.y<-in_cir.r)||(in_cir.pos.y>scr_y+in_cir.r)) return false;
	return true;
}

