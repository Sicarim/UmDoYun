#include "GreenCard.h"
#include "GameManager.h"

GreenCard::GreenCard()
{

}

//�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)(override)
void GreenCard::Init(int _x, int _y)
{
	//�ʷ� ī��
	m_GreenCard = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\ColoredPaperGreen.bmp");
	pos_x = _x;
	pos_y = _y;
	size_x = m_GreenCard->get_Width();
	size_y = m_GreenCard->get_Height();
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;

	isBonus = false;
	m_Bonus = NULL;
}

//Ű�Է�(override)
bool GreenCard::Input(int _state)
{
	/*
		GreenCard�� ���ʿ� ��ġ�ϱ� ������ ������ Ŭ���� ���� ó��
		���� ������ �ƴ� �ٸ� ����Ű�� �����ٸ�, Falló��
	*/
	if (!isBefore)
	{
		isBefore = true;
		if (_state == UP)
		{
			isAnswer = ANSWER;
		}
		else
		{
			isAnswer = FAIL;
		}
	}

	return false;
}

//Update�Լ�(override)
void GreenCard::Update(float _fETime)
{
	/*
		������ 5�� ���߸� BonusCard(Star �̹���)�� True�� �ٲ۴�
	*/
	if (!isBonus)
	{
		m_Bonus = GameManager::get_Instance()->Bonus_Card();
		isBonus = true;
	}
	/*
		���� �����̶��....
	*/
	if (isAnswer == ANSWER)
	{
		/*
			�ð��� �����ؼ� ī�带 �ش� ��ġ�� �ű��.
		*/
		curTime += _fETime;
		if (pos_y > LIMIT_GREEN)
		{
			pos_y -= curTime * CARD_SPEED;
		}
		/*
			ī�尡 ������ ��ġ�� �����ߴٸ�...
		*/
		else
		{
			/*
				����� FeverTime�� ���� ������ Count(Card, Fever)�� ������Ű��, ������ ������Ų��
			*/
			GameManager::get_Instance()->add_CardCount();
			GameManager::get_Instance()->add_FeverCount();
			GameManager::get_Instance()->set_Score(CARD_SCORE);
			if (m_Bonus != NULL)
			{
				GameManager::get_Instance()->add_BonusScore();
			}
			//�ٽ� ������¸� ���� �ٲ۴�.
			isAnswer = STAND;
		}
	}

	/*
		���� ������ �ƴ϶��
	*/
	else if (isAnswer == FAIL)
	{
		//vibeī��Ʈ�� ������Ų��.
		vibe++;
		curTime += _fETime;

		//�ð��� ���缭 �����Ѵ�.
		if (curTime < 0.15f)
		{
			if (vibe % 2 == 0)
			{
				pos_x += 10;
			}
			else if (vibe % 2 == 1)
			{
				pos_x -= 10;
			}
		}
		else
		{
			//�ð��� �ٳ����� �ٽ� ����ġ�ϸ� ���� �ʱ��Ѵ�.
			pos_x = CARD_X;
			pos_y = CARD_Y;
			isAnswer = STAND;
			isBefore = false;
			curTime = 0.0f;
			vibe = 0;
			GameManager::get_Instance()->Down_FeverBar();
		}
	}
}

//Draw �Լ�(overloding)(override)
void GreenCard::Draw()
{
	//ī�带 �׸���.
	m_GreenCard->Draw(pos_x, pos_y);
	//���� ���ʽ� ī�尡 �����ϸ� ���ʽ� �׸��� �׸���.
	if (m_Bonus != NULL)
	{
		m_Bonus->Draw(pos_x + 20, pos_y + 20);
	}
}

//Draw �Լ�(override)
void GreenCard::Draw(int _x, int _y)
{

}

//Release() �Լ�(override)
void GreenCard::Release()
{
	//�����Ҷ� �ʱⰪ���� ��� �ʱ�ȭ��Ų��.
	size_x = 0;
	size_y = 0;
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;
}

GreenCard::~GreenCard()
{

}