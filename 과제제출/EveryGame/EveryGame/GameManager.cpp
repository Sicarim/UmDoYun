#include "GameManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "TitleScene.h"
#include "SelectScene.h"
#include "FlightScene.h"
#include "CardScene.h"
#include "UIManager.h"
#include "ResourcesManager.h"

//생성자
GameManager::GameManager()
{

}

//초기화 함수
void GameManager::Init()
{
	TotalScore = 0;
	FeverAlpa = 0;
	UltraAlpa = 0;
	FeverCount = 0;
	curTime = 1.0f;
	FeverTime = 0.0f;
	FeverPuple_Count = 0.0f;
	FeverRed_Count = 0.0f;
	FeverYellow_Count = 0.0f;

	isGameOver = false;
	isUltr = false;
	isFever = false;

	//Fever Effect
	Fever_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\FeverEffect3.bmp");
	//Fever 게이지
	m_vFeverBar[FEVER_PUPLE] = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\Fever1.bmp");
	m_vFeverBar[FEVER_RED] = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\Fever2.bmp");
	m_vFeverBar[FEVER_YELLOW] = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\Fever3.bmp");
	//시간 바
	Time_Bar = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\ColoredPaperTimeBar.bmp");
	//보너스 별
	for (int i = 1; i <= 3; i++)
	{
		wsprintf(buf, "RES\\FlightGameStar%d.bmp", i);
		tmp_Bonus = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vBonus.push_back(tmp_Bonus);
	}
	//로딩
	//로딩화면 비트
	Load_BackBit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\LoadingBack.bmp");
	//로딩아이콘 비트
	Load_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\Loading.bmp");
}

//카드게임 초기화
void GameManager::CardGame_Init()
{
	Card_Count = 0;
	Bonus_Score = 0;
	AnswerCount = 0;
}

//비행기 게임 초기화
void GameManager::FlightGame_Init()
{

}

//Scene등록
void GameManager::Regist_Scene()
{
	//TitleScene등록
	DoEngine::SceneManager::get_Instance()->RegistScene(new TitleScene);
	//SelectScene등록
	DoEngine::SceneManager::get_Instance()->RegistScene(new SelectScene);
	//FlightScene등록
	DoEngine::SceneManager::get_Instance()->RegistScene(new FlightScene);
	//CardScene등록
	DoEngine::SceneManager::get_Instance()->RegistScene(new CardScene);
}

//Update
void GameManager::Update(float _fETime)
{
	curTime -= 0.0005f;
	//curTime -= 0.01f;

	if (curTime <= 0.0f)
	{
		isGameOver = true;
	}

	if (isFever)
	{
		FeverTime += _fETime;

		if (FeverTime > 15.0f)
		{
			isUltr = false;
			isFever = false;
			FeverTime = 0.0f;
			FeverCount = 0;
			AnswerCount = 0;
			FeverPuple_Count = 0.0f;
			FeverRed_Count = 0.0f;
			FeverYellow_Count = 0.0f;
		}
	}
}

//키 등록
void GameManager::Key_Init()
{
	//키 비우기
	DoEngine::InputManager::get_Instance()->Clear();
	//시작버튼 등록
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_S);
	//공격버튼 등록
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_X);
	//방향키 (왼)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_LEFT);
	//방향키 (오)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_RIGHT);
	//방향키 (위)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_UP);
	//방향키 (아래)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_DOWN);
	//게임 종료
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_ESCAPE);
	//엔터키
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_RETURN);
	//마우스 좌클릭
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_LBUTTON);
}

//삭제 함수
void GameManager::Release()
{
	TotalScore = 0;
	FeverAlpa = 0;
	UltraAlpa = 0;
	FeverTime = 0.0f;
	FeverCount = 0;
	isUltr = false;
	isFever = false;
	isGameOver = false;
	FeverPuple_Count = 0.0f;
	FeverRed_Count = 0.0f;
	FeverYellow_Count = 0.0f;
	curTime = 1.0f;
}

//카드게임 삭제 함수
void GameManager::CardGame_Release()
{
	Card_Count = 0;
	Bonus_Score = 0;
	AnswerCount = 0;
}

//비행기 삭제 함수
void GameManager::FlightGame_Release()
{

}

//Fever 이펙트 그리기
void GameManager::ManagerUI_Draw()
{
	//FeverEffect
	if (isFever)
	{
		FeverAlpa++;

		if (FeverAlpa > 3 && FeverAlpa <= 10)
		{
			Fever_Bit->Draw(0, 0);
			if (FeverAlpa == 10)
			{
				FeverAlpa = 0;
			}
		}
	}

	//FeverBar
	m_vFeverBar[FEVER_PUPLE]->Draw(FEVER_X, FEVER_Y, FeverPuple_Count);
	m_vFeverBar[FEVER_RED]->Draw(FEVER_X, FEVER_Y, FeverRed_Count);
	m_vFeverBar[FEVER_YELLOW]->Draw(FEVER_X, FEVER_Y, FeverYellow_Count);

	if (isUltr)
	{
		UltraAlpa++;
		if (UltraAlpa % 4 == 0 || UltraAlpa % 4 == 1)
		{
			m_vFeverBar[FEVER_RED]->Draw(FEVER_X, FEVER_Y, FeverRed_Count);
		}
		else
		{
			m_vFeverBar[FEVER_YELLOW]->Draw(FEVER_X, FEVER_Y, FeverYellow_Count);
		}
	}

	//TimeBar
	Time_Bar->Draw(TIMEBAR_X, TIMEBAR_Y, curTime);
}

//Fever 이펙트 그리기
void GameManager::Loading_Draw()
{
	Load_BackBit->AlphaDraw(0, 0, 150);
	Load_Bit->Draw(130, 230);
	DoEngine::UIManager::get_Instance()->AddText("Loading...", 150, 370, 40, 255, 255, 255, TRANSPARENT, "맑은 고딕");
}

//게임 오버 리턴
bool GameManager::get_GameOver()
{
	return isGameOver;
}


///////////////////////카드 게임/////////////

//점수 삽입
void GameManager::set_Score(int _score)
{
	if (isFever)
	{
		TotalScore += _score * 2;
	}
	else
	{
		TotalScore += _score;
	}
}

//점수 리턴
int GameManager::get_Score()
{
	return TotalScore;
}

//카드 횟수 증가
void GameManager::add_CardCount()
{
	Card_Count++;
}

//카드 횟수 리턴
int GameManager::get_CardCount()
{
	return Card_Count;
}

//Fever게이지 상승
void GameManager::add_FeverCount()
{
	FeverCount++;
	AnswerCount++;

	if (AnswerCount <= 10)
	{
		FeverPuple_Count = FeverCount * 0.1;
	}
	else if (AnswerCount > 10 && AnswerCount <= 20)
	{
		FeverRed_Count = FeverCount * 0.1;
	}
	else if (AnswerCount > 20 && AnswerCount <= 30)
	{
		FeverYellow_Count = FeverCount * 0.1;
	}

	if (AnswerCount == 10 || AnswerCount == 20)
	{
		if (AnswerCount == 10)
		{
			isFever = true;
		}
		FeverCount = 0;
	}

	if (AnswerCount > 30)
	{
		isUltr = true;
	}
}

//카드 게임
DoEngine::BitMap* GameManager::Bonus_Card()
{
	if (Card_Count % 5 == 0 && Card_Count != 0)
	{
		int Bonus = rand() % 3;
		DoEngine::BitMap* tmp_Bonus = m_vBonus[Bonus];

		if (Bonus == BONUS_YELLOW)
		{
			Bonus_Score = 100;
		}
		else if (Bonus == BONUS_GREEN)
		{
			Bonus_Score = 1400;
		}
		else if (Bonus == BONUS_BLUE)
		{
			Bonus_Score = 1400;
		}

		return tmp_Bonus;
	}
	else
	{
		return NULL;
	}
}

vector<DoEngine::BitMap*> GameManager::get_Bonus()
{
	return m_vBonus;
}

//보너스 점수 리턴
void GameManager::add_BonusScore()
{
	TotalScore += Bonus_Score;
}

//FeverBar감소
void GameManager::Down_FeverBar()
{
	if (!isFever)
	{
		FeverPuple_Count -= 0.1;
	}
}


//모든 콜라이더 그리기
void GameManager::All_Draw()
{

}

//소멸자
GameManager::~GameManager()
{

}