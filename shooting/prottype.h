#pragma once

class Cplayer_bullet{
public:
	virtual bool proc(void)=0;//ï‘ÇËíltrueÇÃéûçÌèú
	virtual bool hitchk(const C_2d_circle& in_cir)=0;
	virtual void draw(void)=0;
};

class Cplayer_normalbullet : public Cplayer_bullet{
public:
	Cplayer_normalbullet(const C_2d_vector& in_pos,const C_2d_vector& in_vec);
	bool proc(void);
	bool hitchk(const C_2d_circle& in_cir);
	void draw(void);
private:
	C_2d_circle cir;
	C_2d_vector vec;
};


class Cplayer{
public:
	Cplayer();
	~Cplayer();
	void clear();
	bool proc();//trueÇ»ÇÁèIóπ
	void draw();
	C_2d_circle get_circle();
	bool hitchk_playerbullet(const C_2d_circle& in_cir);
	int show_bullet_number(void);
	int show_hp();
private:
	C_2d_circle cir;
	list<Cplayer_bullet*> p_bullet_list;
	int bullet_timer;
	int reborn_timer;
	int hp;
};





class Ctask{
public:
	virtual bool proc()=0;//trueÇÃéûçÌèú
	virtual bool hitchk(const C_2d_circle& in_cir)=0;
	virtual void draw()=0;
};

class Ctask_enemynormal : public Ctask{
public:
	Ctask_enemynormal(const C_2d_vector& in_pos,const C_2d_vector& in_vec);
	bool proc();
	bool hitchk(const C_2d_circle& in_cir);
	void draw();
private:
	C_2d_circle cir;
	C_2d_vector vec;
	int hp;
	int timer;
};

class Ctask_enemy_fixed : public Ctask{
public:
	Ctask_enemy_fixed(const C_2d_vector& in_pos,const C_2d_vector& in_vec,int in_move_timer);
	bool proc();
	bool hitchk(const C_2d_circle& in_cir);
	void draw();
private:
	C_2d_circle cir;
	C_2d_vector vec;
	int bullet_timer;
	int bullet_pattern_timer;
	int move_timer;
	int hp;
};


class Ctask_enemybullet_normal : public Ctask{
public:
	Ctask_enemybullet_normal(const C_2d_vector& in_pos,const C_2d_vector& vec);
	bool proc();
	bool hitchk(const C_2d_circle& in_cir);
	void draw();
private:
	C_2d_circle cir;
	C_2d_vector vec;
};


class Ctask_Control{
public:
	//Ctask_Control();
	~Ctask_Control();
	void clear();
	void proc();
	bool hitchk_all(const C_2d_circle& in_cir);
	void draw();
	void add_task(Ctask* new_pointer);
	int show_number();
private:
	list<Ctask*> p_task_list;
};