#pragma once
class Cpicture{
public:
	Cpicture(void);
	Cpicture(char* filename);
	~Cpicture(void);
	bool load(char* filenme);
	bool loaded(void);
	bool clear(void);
	void draw(int pos_x , int pos_y);
	void draw(C_2d_vector pos);
	void center_draw(int pos_x , int pos_y);
	void center_draw(C_2d_vector pos);
	void GetSize(int* Xbuf , int* Ybuf);
private:
	int picsize_x;
	int picsize_y;
	int gh;
};

Cpicture::Cpicture(void){
	gh=-1;
}
Cpicture::Cpicture(char* filename){
	gh=LoadGraph(filename);
	if(gh==-1) return;
	GetGraphSize(gh,&picsize_x,&picsize_y);
	return;
}
Cpicture::~Cpicture(){
	DeleteGraph(gh);
	return;
}
bool Cpicture::load(char* filename){
	if(gh!=-1) DeleteGraph(gh);
	gh=LoadGraph(filename);
	if(gh==-1) return false;
	GetGraphSize(gh,&picsize_x,&picsize_y);
	return true;
}

bool Cpicture::loaded(void){
	if(gh==-1) return false;
	return true;
}

bool Cpicture::clear(void){
	if(DeleteGraph(gh)==-1) return false;
	gh=-1;
	return true;
}
void Cpicture::draw(int pos_x,int pos_y){
	DrawGraph( pos_x , pos_y , gh , TRUE);
	return;
}

void Cpicture::draw(C_2d_vector pos){
	DrawGraph( (int)pos.x , (int)pos.y , gh , TRUE);
	return;
}

void Cpicture::center_draw(int pos_x,int pos_y){
	DrawGraph( (int)pos_x-(picsize_x/2),(int)pos_y-(picsize_y/2),gh,TRUE);
}

void Cpicture::center_draw(C_2d_vector pos){
	DrawGraph( (int)pos.x-(picsize_x/2),(int)pos.y-(picsize_y/2),gh,TRUE);
	return;
}

void Cpicture::GetSize(int *Xbuf, int *Ybuf){
	*Xbuf=picsize_x;
	*Ybuf=picsize_y;
	return;
}
