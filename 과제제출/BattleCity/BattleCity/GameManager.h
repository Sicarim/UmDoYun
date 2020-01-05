#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "Enemy.h"

class GameManager : public Singleton<GameManager>
{
private:
	int Bullet_dir;
	int Broken_Count, Water_Count, Bush_Count, Still_Count;

	vector<DoEngine::Object*> tmp_vEnemy; //�� vector
	DoEngine::Object* tmp_Player; //Player Object
	int Health_Count;
	int Enemy_Count;





	int test_x;
	int test_y;

	int Real_x;
	int Real_y;

public:
	GameManager(); //������

	void Init(); //�ʱ�ȭ
	void Key_Init(); //Ű ���
	void Regist_Scene(); //�� ���
	vector<DoEngine::Object*> Make_Enemy(); //���� �����
	void All_Draw(); //��� �ݶ��̴� �׸���
	void set_BulletDir(int _dir); //ź�� ���� ����
	int get_BulletDir(); //ź�� ���� ����

	void set_BrokenCount(int _count); //�ı��Ǵ� ��� ���� ����
	void set_WaterCount(int _count); //�� ��� ���� ����
	void set_BushCount(int _count); //�ν� �� ���� ����
	void set_StillCount(int _count); //��ö �� ���� ����

	int get_BrokenCount(); //�ı��Ǵ� ��� ����
	int get_WaterCount(); //�� ��� ����
	int get_BushCount(); //�ν� �� ����
	int get_StillCount(); //��ö �� ����
	void set_HealthCount(int _num); //�� ���� ����
	int get_HealthCount(); //�� ���� ����

	void set_EnemyCount(int _num); //���� �ʿ� �ִ� ���� ���� ����
	int get_EnemyCount(); //���� �ʿ� �ִ� ���� ���� ����



	//test�Լ�
	void set_CurrentX(int _x, int _rx);
	void set_CurrentY(int _y, int _ry);

	int get_CurrentX();
	int get_CurrentY();

	int get_RealX();
	int get_RealY();

	~GameManager(); //�Ҹ���
};