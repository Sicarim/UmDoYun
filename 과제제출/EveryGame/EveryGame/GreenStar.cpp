#include "GreenStar.h"
#include "GameManager.h"

//������
GreenStar::GreenStar()
{
	//���ʿ��� �����ȴ�.
}

//�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)(override)
void GreenStar::Init(int _x, int _y)
{
	GreenStar_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\FlightGameStar2.bmp");
	m_tag = "GreenStar";
	pos_x = _x;
	pos_y = _y;
	size_x = GreenStar_Bit->get_Width();
	size_y = GreenStar_Bit->get_Height();
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
bool GreenStar::Input(int _state)
{
	if (isDestroy)
	{
		return false;
	}
	/*
		Fever���°� �ƴ� �� ������ �̵��ϸ�,
		Fever���¶�� �� �� ������ �̵��Ѵ�.
	*/
	else
	{
		if (!GameManager::get_Instance()->get_isFever())
		{
			pos_x += curTime * STAR_SPEED;
			pos_y += 0.3 * Random * Birth_dir;
		}
		else
		{
			pos_x += curTime * FSTAR_SPEED;
			pos_y += 0.3 * Random * Birth_dir;
		}
	}
}

//Update�Լ�(override)
void GreenStar::Update(float _fETime)
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
		GameManager::get_Instance()->set_Score(GREEN_SCORE);
		GameManager::get_Instance()->add_FeverCount();
	}

	//���� ������ �ı�
	if (m_Coll.get_Collider("BackGround").top > pos_y || m_Coll.get_Collider("BackGround").bottom < pos_y + size_y || m_Coll.get_Collider("BackGround").left > pos_x || m_Coll.get_Collider("BackGround").right < pos_x + size_y)
	{
		isDestroy = true;
	}
}

//Draw �Լ�(overloding)(override)
void GreenStar::Draw()
{
	//�ı����� �ʴ´ٸ� �׸��� �ݶ��̴��� �׸���.
	if (!isDestroy)
	{
		GreenStar_Bit->Draw(pos_x, pos_y);
		m_Coll.Draw_Collider();
	}
}

//Draw �Լ�(override)
void GreenStar::Draw(int _x, int _y)
{

}

//Release() �Լ�(override)
void GreenStar::Release()
{
}

//�Ҹ���
GreenStar::~GreenStar()
{

}