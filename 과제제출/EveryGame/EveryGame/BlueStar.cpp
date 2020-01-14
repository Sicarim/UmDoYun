#include "BlueStar.h"
#include "GameManager.h"

//������
BlueStar::BlueStar()
{
	//���ʿ��� �����ȴ�.
}

//�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)(override)
void BlueStar::Init(int _x, int _y)
{
	BlueStar_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\FlightGameStar3.bmp");
	m_tag = "BlueStar";
	pos_x = _x;
	pos_y = _y;
	size_x = BlueStar_Bit->get_Width();
	size_y = BlueStar_Bit->get_Height();
	curTime = 0.0f;
	isDestroy = false;
	Random = rand() % 10 + 1;

	//������ ������ �������� ����
	if (Random % 2 == 0)
	{
		Birth_dir = 1;
	}
	else
	{
		Birth_dir = -1;
	}
}

//Ű�Է�(override)
bool BlueStar::Input(int _state)
{
	if (isDestroy)
	{
		return false;
	}
	else
	{
		/*
			Fever���°� �ƴ� �� ������ �̵��ϸ�, 
			Fever���¶�� �� �� ������ �̵��Ѵ�.
		*/
		if (!GameManager::get_Instance()->get_isFever())
		{
			pos_x += 0.3 * Random * Birth_dir;
			pos_y += curTime * STAR_SPEED;
		}
		else
		{
			pos_x += 0.3 * Random * Birth_dir;
			pos_y += curTime * FSTAR_SPEED;
		}
	}
}

//Update�Լ�(override)
void BlueStar::Update(float _fETime)
{
	m_Coll.Init_Collider(m_tag, pos_x, pos_y, size_x, size_y);
	curTime = _fETime;

	/*
		Flight��� �̸��� ���� Collider�� �浹�ϸ� �ı��ȴ�.
		�ı��Ǹ鼭 ������ Feverī��Ʈ�� ������Ų��
	*/
	if (m_Coll.isCollider("Flight"))
	{
		isDestroy = true;
		GameManager::get_Instance()->set_Score(BLUE_SCORE);
		GameManager::get_Instance()->add_FeverCount();
	}

	//���� ������ �ı�
	if (m_Coll.get_Collider("BackGround").top > pos_y || m_Coll.get_Collider("BackGround").bottom < pos_y + size_y || m_Coll.get_Collider("BackGround").left > pos_x || m_Coll.get_Collider("BackGround").right < pos_x + size_y)
	{
		isDestroy = true;
	}
}

//Draw �Լ�(overloding)(override)
void BlueStar::Draw()
{
	//�ı����� �ʴ´ٸ� �׸��� �ݶ��̴��� �׸���.
	if (!isDestroy)
	{
		BlueStar_Bit->Draw(pos_x, pos_y);
		m_Coll.Draw_Collider();
	}
}

//Draw �Լ�(override)
void BlueStar::Draw(int _x, int _y)
{

}

//Release() �Լ�(override)
void BlueStar::Release()
{
	isDestroy = false;
}

//�Ҹ���
BlueStar::~BlueStar()
{

}