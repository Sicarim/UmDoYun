#include "YellowCard.h"
#include "GameManager.h"

YellowCard::YellowCard()
{

}

//초기화(시작 위치 초기화 가능)(override)
void YellowCard::Init(int _x, int _y)
{
	//노랑 카드
	m_YellowCard = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\ColoredPaperYellow.bmp");
	pos_x = _x;
	pos_y = _y;
	size_x = m_YellowCard->get_Width();
	size_y = m_YellowCard->get_Height();
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;

	m_Bonus = NULL;
	isBonus = false;
}

//키입력(override)
bool YellowCard::Input(int _state)
{
	/*
		YellowCard는 아랫쪽에 위치하기 때문에 아랫쪽을 클릭시 정답 처리
		만약 아랫쪽이 아닌 다른 방향키를 눌렀다면, Fall처리
	*/
	if (!isBefore)
	{
		isBefore = true;
		if (_state == DOWN)
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
void YellowCard::Update(float _fETime)
{
	/*
		정답을 5번 맞추면 BonusCard(Star 이미지)를 True로 바꾼다
	*/
	if (!isBonus)
	{
		m_Bonus = GameManager::get_Instance()->Bonus_Card();
		isBonus = true;
	}
	/*
		만약 정답이라면....
	*/
	if (isAnswer == ANSWER)
	{
		curTime += _fETime;
		if (pos_y + size_y < LIMIT_YELLOW)
		{
			pos_y += curTime * CARD_SPEED;
		}
		/*
			카드가 지정된 위치에 도달했다면...
		*/
		else
		{
			/*
				정답과 FeverTime을 위해 각각의 Count(Card, Fever)를 증가시키고, 점수를 증가시킨다
			*/
			GameManager::get_Instance()->add_CardCount();
			GameManager::get_Instance()->add_FeverCount();
			GameManager::get_Instance()->set_Score(CARD_SCORE);
			if (m_Bonus != NULL)
			{
				GameManager::get_Instance()->add_BonusScore();
			}
			//다시 정답상태를 대기로 바꾼다.
			isAnswer = STAND;
		}
	}
	/*
		만약 정답이 아니라면
	*/

	else if (isAnswer == FAIL)
	{
		//vibe카운트를 증가시킨다.
		vibe++;
		curTime += _fETime;
		//시간에 맞춰서 진동한다.
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
			//시간이 다끝나면 다시 원위치하며 값을 초기한다.	
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
void YellowCard::Draw()
{
	//카드를 그린다.
	m_YellowCard->Draw(pos_x, pos_y);
	//만약 보너스 카드가 존재하면 보너스 그림도 그린다.

	if (m_Bonus != NULL)
	{
		m_Bonus->Draw(pos_x + 20, pos_y + 20);
	}
}

//Draw 함수(override)
void YellowCard::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void YellowCard::Release()
{
	//삭제할때 초기값들을 모두 초기화시킨다.
	size_x = 0;
	size_y = 0;
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;
}

YellowCard::~YellowCard()
{

}