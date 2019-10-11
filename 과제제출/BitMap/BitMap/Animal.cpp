#include "Animal.h"
#include "BitMapManager.h"

//생성자
Animal::Animal()
{
	x = 30;
	y = 30;
}

//모든 그림 초기화
/*
윈도우 핸들 정보를 저장하고, 프로그램의 인스턴스 식별자를 넘겨 받는다.
같은 윈도우, 같은 프로그램에서 돌아가기 때문인듯
Init에 윈도우 핸들러, 프로그램 인스턴스 식별자가 들어간다는것에 유의(HWND, HIMSTAME)
*/

/*
같은 HWND를 사용하는것은 같은 윈도우 창에서 일어나는 일인듯하다.

결국 HINSTANCE는 프로그램 자체의 핸들이며, HWND는 프로그램안의 윈도우창의 번호인것같다.
그럼 HINSTANCE는 프로그램이 하나라면 유일한 하나고, HWND는 여러개가 될수 있는것있나?
쓰래드를 돌리면 인스텐스값은 혹시 달라지나? 아닌가? 같은 프로그램이니까..?
*/
void Animal::All_Init(HWND hWnd, HINSTANCE _hInst)
{
	//GetDC로 DC의 정보에 핸들 윈도우 값을 받아 온다. 
	//HDC hdc = GetDC(hWnd);

	//GetDC로 받아온 DC는 반드시 해제를 해주어야 하는데 ReleaseDC를 통해 해제를 한다.
	//ReleaseDC(hWnd, hdc);
}

/*
그림등의 각종 표현(출력)을 하기 위해선 hdc가 필요하다는걸 다시 명심하자
왜냐면 DC가 출력에 필요한 모든 정보를 가지는 데이터 구조체이기 때문이다.
결국 HDC란 DC의 정보를 저장하는 데이터 구조체의 위치를 알기 위함이란걸 명심하자
*/
//모든 그림 그리기
void Animal::All_Draw(HDC hdc)
{
	int Count = 1;
	bit = BitMapManager::get_Instence()->get_Bit();
	//x축 간격: 170

	for (auto iter = bit.begin(); iter != bit.end(); iter++)
	{				
		if(Count == 5)
		{
			(*iter).Draw(hdc, x, y);
			y = 300;
			x = 30;
			Count = 0;
		}
		(*iter).Draw(hdc, x, y);
		x += 170;
		Count++;
	}
}

//메시지 전송
/*
메시지 박스는 같은 윈도우 값을 받는듯 하다.
*/
void Animal::Send_Message(HWND hWnd, int _mouseX, int _mouseY)
{
	if (_mouseY > 30 && _mouseY < 280)
	{
		if (_mouseX > 30 && _mouseX < bit[0].get_Width() + 30)
		{
			(MessageBox(hWnd, "댕댕이", "동물", MB_OK));
		}
		else if (_mouseX > 200 && _mouseX < bit[1].get_Width() + 200)
		{
			(MessageBox(hWnd, "호랑이(유사 고양이)", "동물", MB_OK));
		}
		else if (_mouseX > 370 && _mouseX < bit[2].get_Width() + 370)
		{
			(MessageBox(hWnd, "오리고기", "동물", MB_OK));
		}
		else if (_mouseX > 540 && _mouseX < bit[3].get_Width() + 540)
		{
			(MessageBox(hWnd, "코끼리", "동물", MB_OK));
		}
		else if (_mouseX > 710 && _mouseX < bit[4].get_Width() + 710)
		{
			(MessageBox(hWnd, "흑우", "동물", MB_OK));
		}
	}

	if (_mouseY > 200 && _mouseY < 450)
	{
		if (_mouseX > 30 && _mouseX < bit[5].get_Width() + 30)
		{
			(MessageBox(hWnd, "말(히이잉)", "동물", MB_OK));
		}
		else if (_mouseX > 200 && _mouseX < bit[6].get_Width() + 200)
		{
			(MessageBox(hWnd, "고양이(때껄룩)", "동물", MB_OK));
		}
		else if (_mouseX > 370 && _mouseX < bit[7].get_Width() + 370)
		{
			(MessageBox(hWnd, "원숭이", "동물", MB_OK));
		}
		else if (_mouseX > 540 && _mouseX < bit[8].get_Width() + 540)
		{
			(MessageBox(hWnd, "개구리", "동물", MB_OK));
		}
		else if (_mouseX > 710 && _mouseX < bit[9].get_Width() + 710)
		{
			(MessageBox(hWnd, "치킨", "동물", MB_OK));
		}
	}
}

//생성자
Animal::~Animal()
{

}