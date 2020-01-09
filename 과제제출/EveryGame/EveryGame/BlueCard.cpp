#include "BlueCard.h"
#include "GameManager.h"

BlueCard::BlueCard()
{

}

//초기화(시작 위치 초기화 가능)(override)
void BlueCard::Init(int _x, int _y)
{
	//퍼런 카드
	m_BlueCard = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\ColoredPaperBlue.bmp");
	pos_x = _x;
	pos_y = _y;
	size_x = m_BlueCard->get_Width();
	size_y = m_BlueCard->get_Height();
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;

	isBonus = false;
	m_Bonus = NULL;
}

//키입력(override)
bool BlueCard::Input(int _state)
{
	if (!isBefore)
	{
		isBefore = true;
		if (_state == LEFT)
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

//Update함수(override)
void BlueCard::Update(float _fETime)
{
	if (!isBonus)
	{
		m_Bonus = GameManager::get_Instance()->Bonus_Card();
		isBonus = true;
	}

	if (isAnswer == ANSWER)
	{
		curTime += _fETime;
		if (pos_x > LIMIT_BLUE)
		{
			pos_x -= curTime * CARD_SPEED;
		}
		else
		{
			GameManager::get_Instance()->add_CardCount();
			GameManager::get_Instance()->add_FeverCount();
			GameManager::get_Instance()->set_Score(CARD_SCORE);
			if (m_Bonus != NULL)
			{
				GameManager::get_Instance()->add_BonusScore();
			}
			isAnswer = STAND;
		}
	}

	else if (isAnswer == FAIL)
	{
		vibe++;
		curTime += _fETime;

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

//Draw 함수(overloding)(override)
void BlueCard::Draw()
{
	m_BlueCard->Draw(pos_x, pos_y);

	if (m_Bonus != NULL)
	{
		m_Bonus->Draw(pos_x + 20, pos_y + 20);
	}
}

//Draw 함수(override)
void BlueCard::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void BlueCard::Release()
{
	size_x = 0;
	size_y = 0;
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;
}

BlueCard::~BlueCard()
{

}