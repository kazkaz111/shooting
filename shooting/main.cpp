#include"DxLib.h"

#include <string>
#include <list>
#include <cmath>

using namespace std;


#include "fps.h"
#include "C_2d_data.h"
#include "Cpicture.h"

#include "color_def.h"


int key;
#include"prottype.h"

Cplayer Cplayer_ins;
Ctask_Control Ctask_Control_ins;


#include"Cplayer.h"
#include"Ctask.h"

#include"stage1.h"

Cstage Cstage_ins;

#include"playgame.h"
#include"gamemain.h"






extern Cpicture back_ground;

int WINAPI WinMain(HINSTANCE hI,HINSTANCE hP,LPSTR lpC,int nC){
	int window_mode=MessageBox(NULL,"�t���X�N���[���ŋN�����܂����H","�N�����[�h",MB_YESNO);
	switch(window_mode){
	case 0:
		return 0;
		break;
	case IDYES:
		if((ChangeWindowMode(FALSE)!=DX_CHANGESCREEN_OK)||SetGraphMode(800,600,32)!=DX_CHANGESCREEN_OK){
			MessageBox(NULL,"�X�N���[�����[�h�̕ύX�Ɏ��s���܂���","�X�N���[�����[�h�ύX���s",MB_OK);
			return 0;
		}
		break;
	case IDNO:
		if((ChangeWindowMode(TRUE)!=DX_CHANGESCREEN_OK)||(SetGraphMode(800,600,32)!=DX_CHANGESCREEN_OK)){
			MessageBox(NULL,"�X�N���[�����[�h�̕ύX�Ɏ��s���܂���","�X�N���[�����[�h�ύX���s",MB_OK);
			return 0;
		}
		break;
	}


	if(DxLib_Init()==-1){
		MessageBox(NULL,"DX���C�u�����̏������Ɏ��s���܂����B","���������s",MB_OK);
		return -1;
	}
	picload();
	SetDrawScreen(DX_SCREEN_BACK);
	key=GetJoypadInputState(DX_INPUT_KEY_PAD1);

	bool end_flag=false;

	while(ProcessMessage()==0&&(!end_flag)&&((key&PAD_INPUT_9)==0)){
		ClsDrawScreen();
		key=GetJoypadInputState(DX_INPUT_KEY_PAD1);
		gamemain_proc();
		bool draw_flag=fps_wait();
		if(draw_flag){
			gamemain_draw();
			draw_fps(0,0);
			ScreenFlip();
		}

	}

	DxLib_End();

	return 0;
}

