

































class Cstage{
public:
	Cstage(void);
	void clear(void);
	//~Cstage(void);
	bool proc(void);//trueÇÃéûèIóπ
private:
	int count;
};

Cstage::Cstage(void){
	count=0;
	return;
}

void Cstage::clear(void){
	count=0;
	return;
}

bool Cstage::proc(void){
	count++;
	if(count==60) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(0,100),To_C_2d_vector(5,0)));
	if(count==60) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(800,200),To_C_2d_vector(-5,0)));
	if(count==120) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(0,100),To_C_2d_vector(5,0)));
	if(count==120) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(800,200),To_C_2d_vector(-5,0)));
	if(count==180) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(0,100),To_C_2d_vector(5,0)));
	if(count==180) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(800,200),To_C_2d_vector(-5,0)));
	if(count==240) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(0,100),To_C_2d_vector(5,0)));
	if(count==240) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(800,200),To_C_2d_vector(-5,0)));
	if(count==300) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(0,100),To_C_2d_vector(5,0)));
	if(count==300) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(800,200),To_C_2d_vector(-5,0)));
	if(count==360) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(0,100),To_C_2d_vector(5,0)));
	if(count==360) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(800,200),To_C_2d_vector(-5,0)));
	if(count==600) Ctask_Control_ins.add_task(new Ctask_enemy_fixed(To_C_2d_vector(400,0),To_C_2d_vector(0,5),20));
	if(count==720) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(0,100),To_C_2d_vector(5,0)));
	if(count==720) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(800,200),To_C_2d_vector(-5,0)));
	if(count==780) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(0,100),To_C_2d_vector(5,0)));
	if(count==780) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(800,200),To_C_2d_vector(-5,0)));
	if(count==840) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(0,100),To_C_2d_vector(5,0)));
	if(count==840) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(800,200),To_C_2d_vector(-5,0)));
	if(count==900) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(0,100),To_C_2d_vector(5,0)));
	if(count==900) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(800,200),To_C_2d_vector(-5,0)));
	if(count==960) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(0,100),To_C_2d_vector(5,0)));
	if(count==960) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(800,200),To_C_2d_vector(-5,0)));
	if(count==1020) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(0,100),To_C_2d_vector(5,0)));
	if(count==1020) Ctask_Control_ins.add_task(new Ctask_enemynormal(To_C_2d_vector(800,200),To_C_2d_vector(-5,0)));
	if(count==2000){
		count=0;
		return true;
	}
	return false;
}