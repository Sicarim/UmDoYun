#include "RedCard.h"
#include "GameManager.h"

RedCard::RedCard()
{

}

//초기화(시작 위치 초기화 가능)(override)
void RedCard::Init(int _x, int _y)
{
	//빨간 카드
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

//키입력(override)
bool RedCard::Input(int _state)
{
	/*
		RedCard는 오른쪽에 위치하기 때문에 오른쪽을 클릭시 정답 처리
		만약 오른쪽이 아닌 다른 방향키를 눌렀다면, Fall처리
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

//Update함수(override)
void RedCard::Update(float _fETime)
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
		/*
			시간을 저장해서 카드를 해당 위치로 옮긴다.
		*/
		curTime += _fETime;
		if (pos_x + size_x < LIMIT_RED)
		{
			pos_x += curTime * CARD_SPEED;
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
void RedCard::Draw()
{
	//카드를 그린다.
	m_RedCard->Draw(pos_x, pos_y);
	//만약 보너스 카드가 존재하면 보너스 그림도 그린다.
	if (m_Bonus != NULL)
	{
		m_Bonus->Draw(pos_x + 20, pos_y + 20);
	}
}

//Draw 함수(override)
void RedCard::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void RedCard::Release()
{
	//삭제할때 초기값들을 모두 초기화시킨다.
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