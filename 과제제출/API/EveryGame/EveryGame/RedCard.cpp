#include "RedCard.h"
#include "GameManager.h"

RedCard::RedCard()
{

}

//�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)(override)
void RedCard::Init(int _x, int _y)
{
	//���� ī��
	m_RedCard = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\ColoredPaperRed.bmp");
	pos_x = _x;
	pos_y = _y;
	size_x = m_RedCard->get_Width();
	size_y = m_RedCard->get_Height();
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;

	isBonus = false;
	m_Bonus = NULL;
}

//Ű�Է�(override)
bool RedCard::Input(int _state)
{
	/*
		RedCard�� �����ʿ� ��ġ�ϱ� ������ �������� Ŭ���� ���� ó��
		���� �������� �ƴ� �ٸ� ����Ű�� �����ٸ�, Falló��
	*/
	if (!isBefore)
	{
		isBefore = true;
		if (_state == RIGHT)
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
void RedCard::Update(float _fETime)
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
		if (pos_x + size_x < LIMIT_RED)
		{
			pos_x += curTime * CARD_SPEED;
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
void RedCard::Draw()
{
	//ī�带 �׸���.
	m_RedCard->Draw(pos_x, pos_y);
	//���� ���ʽ� ī�尡 �����ϸ� ���ʽ� �׸��� �׸���.
	if (m_Bonus != NULL)
	{
		m_Bonus->Draw(pos_x + 20, pos_y + 20);
	}
}

//Draw �Լ�(override)
void RedCard::Draw(int _x, int _y)
{

}

//Release() �Լ�(override)
void RedCard::Release()
{
	//�����Ҷ� �ʱⰪ���� ��� �ʱ�ȭ��Ų��.
	size_x = 0;
	size_y = 0;
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;
}

RedCard::~RedCard()
{

}