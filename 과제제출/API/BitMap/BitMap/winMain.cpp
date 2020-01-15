#include "Mecro.h"
#include "Animal.h"
#include "BitMapManager.h"
#define _USE_MATH_DEFINES
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("BitMap");

//마우스 클릭값 초기화
int x = 0;
int y = 0;

//BitMap 선언
Animal m_Ani;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	// HWND hWnd2;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;
	//WndClass는 기본 윈도우환경을 만드는 구조체다. 맴버변수는 밑에와 같다.
	WndClass.cbClsExtra = 0; //예약영역
	WndClass.cbWndExtra = 0; //예약영역 (신경x)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); //배경색
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); //커서
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //아이콘 모양
	WndClass.hInstance = hInstance; //(프로그램 핸들값(번호)등록)
	WndClass.lpfnWndProc = WndProc; //프로세스 함수 호출
	WndClass.lpszClassName = lpszClass; //클레스 이름
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW; //윈도우의 수직과 수평이 변경 시 다시 그린다.
	RegisterClass(&WndClass); //만들어진 WidClass를 등록
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,
		(HMENU)NULL, hInstance, NULL); //창 크기 설정
	ShowWindow(hWnd, nCmdShow);

	/*
	hWnd2 = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,
		(HMENU)NULL, hInstance, NULL); //창 크기 설정
	ShowWindow(hWnd2, nCmdShow);
	*/
	//헐 이게 되네
	


	while (GetMessage(&Message, NULL, 0, 0)) //사용자에게 메시지를 받아오는 함수(WM_QUIT 메시지 받을 시 종료), 메시지가 오기까지 대기를 하고있다가 오면 작동.
	{
		TranslateMessage(&Message); // 키보드 입력 메시지 처리함수
		DispatchMessage(&Message); //받은 메시지를 WndProc에 전달하는 함수
	}
	return (int)Message.wParam;
}

/*
☆☆☆☆☆☆☆☆☆☆☆☆
강사님....보지말라고 말씀하셨는데...저번 주말동안 공부한다고 미리 봣버렸어요....
대신 코드 다시 짜보고, 코드분석 철저히 했습니다...ㅎㅎ^^7
☆☆☆☆☆☆☆☆☆☆☆☆☆☆

질문 목록
메시지 박스는 별도의 윈도우 창이 아닌것인가?
HINSTANCE는 프로그램의 핸들러 값이라면 두개 이상은 당연히 못가지는것인가?
그렇다면 쓰레드를 사용하더라도, 당연히 HINTEANCE값은 하나인가?
다른 윈도우를 사용하고 싶다면 그냥 다른 hwnd2 <--이런식으로 선언하면 되는것인가-> 확인 완료
*/

/*
HWND: 윈도우 핸들러, 파일에 접근하기 위해선 이를 이용해 접근해야함.
DC: 출력에 필요한 정보를 가지는 데이터 구조체, 좌표, 색, 굵기 등 출력에 필요한 모든 정보를 담고있다.
->결국 HDC란 DC의 정보를 저장하는 데이터 구조체의 위치를 알기 위함.

HINSTENCE: 핸들 인스턴스, 프로그램의 인스턴스 식별자, 프로그램 자체의 실체화된 주소
-> 프로그램 자체의 핸들
*/

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, MemDC;
	PAINTSTRUCT ps; //그리기 전용 구조체 BeginPaint

	switch (iMessage)
	{
	case WM_CREATE:
		/*
		윈도우가 생성되면 받게 되는 메시지
		윈도우가 생성 되어서 보이기 전 초기화가 필요하다면 사용 가능.
		*/

		//윈도우가 시작 되기 전에 BitMap관련 정보를 초기화한다. 
		//Init함수라 최초의 프로그램 식별자를 매개변수로 넘겨주는듯 하다.
		BitMapManager::get_Instence()->Init(hWnd, g_hInst);
		return 0;

	case WM_LBUTTONDOWN:
		m_Ani.Send_Message(hWnd, LOWORD(lParam), HIWORD(lParam));
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		m_Ani.All_Draw(hdc);
		
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}