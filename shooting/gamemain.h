#pragma once
#include"playgame.h"

extern int key;

extern game_status now_status;


extern Cpicture back_ground;
extern Cpicture player_pic;
extern Cpicture start_button_pic;
extern Cpicture option_button_pic;
extern Cpicture quit_button_pic;
extern Cpicture black_hool_pic;
extern Cpicture player_bullet_pic;
extern Cpicture enemybullet_pic;
extern Cpicture enemyfixed_pic;
extern int menu_sound;
extern int game_sound;


void picload(void){
	back_ground.load("date\\pic\\宇宙背景.png");
	player_pic.load("date\\pic\\player_pic.bmp");
	start_button_pic.load("date\\pic\\スタートボタン.bmp");
	option_button_pic.load("date\\pic\\オプションボタン.bmp");
	quit_button_pic.load("date\\pic\\クイットボタン.bmp");
	black_hool_pic.load("date\\pic\\ブラックホール.png");
	player_bullet_pic.load("date\\pic\\自機弾.bmp");
	enemy_pic.load("date\\pic\\zako.bmp");
	enemyfixed_pic.load("date\\pic\\enemypic.bmp");
	enemybullet_pic.load("date\\pic\\enemybulletpic.bmp");
	
	menu_sound=LoadSoundMem("date\\sound\\castle_defense.mp3");
	game_sound=LoadSoundMem("date\\sound\\the_escapers_fly_into_the_sky.mp3");


}

void menu_draw(void);
void menu_proc(void);

int now_playing_sound=-2;

void gamemain_proc(void){
	switch(now_status){
	case st_menu:
		menu_proc();
		if(now_playing_sound!=menu_sound){
			StopSoundMem(now_playing_sound);
			now_playing_sound=menu_sound;
			PlaySoundMem(menu_sound,DX_PLAYTYPE_LOOP,TRUE);
		}
		break;
	case st_game:
		game_proc();
		if(now_playing_sound!=game_sound){
			StopSoundMem(now_playing_sound);
			now_playing_sound=game_sound;
			PlaySoundMem(game_sound,DX_PLAYTYPE_LOOP,TRUE);
		}
		break;
	}
	return;
}

void gamemain_draw(void){
	switch(now_status){
	case st_menu:
		menu_draw();
		break;
	case st_game:
		game_draw();
		break;
	}
}

void menu_proc(void){
	back_ground.draw(0,0);
	static int now_point;
	if(now_point==0){
		start_button_pic.draw(800-160,600-80*3);
	}
	if(now_point==1){
		option_button_pic.draw(800-160,600-80*2);
	}
	if(now_point==2){
		quit_button_pic.draw(800-160,600-80*1);
	}
	static int before_key;
	if(before_key==0){
		if(key&PAD_INPUT_DOWN) now_point++;
		if(key&PAD_INPUT_UP) now_point--;
	}
	if(now_point<0) now_point=2;
	if(now_point>2) now_point=0;
	before_key=key;
	if(key&PAD_INPUT_1){
		switch(now_point){
		case 0:
			now_status=st_game;
			break;
		case 1:
			now_status=st_option;
			break;
		case 2:
			exit(EXIT_SUCCESS);
			break;
		}
		}
	

	return;
}

void menu_draw(void){
	return;
}