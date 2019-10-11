#include "BitMap.h"

//생성자
BitMap::BitMap()
{

}

//비트맵 선언
/*
윈도우 핸들 정보를 저장하고, 프로그램의 인스턴스 식별자를 넘겨 받는다.
같은 윈도우, 같은 프로그램에서 돌아가기 때문인듯, 그럼 다른 식별자(HINSTENCE)는 언제 사용하는것인가?
Init에 윈도우 핸들러, 프로그램 인스턴스 식별자가 들어간다는것에 유의(HWND, HIMSTAME)
*/
void BitMap::Init(HDC hdc, HINSTANCE _hInst, int _id)
{
	//Dc와 동일한 정보의 DC를 메모리상에 만들어 준댜.
	//메모리 DC를 이용하여 그리기 준비를 하기 위함이다.
	MemDC = CreateCompatibleDC(hdc); //받아온 hdc와 동일한 DC를 MemDC에 만들어준다.
	//받아온 비트맵 아이디를 통해 해당 프로그램(HINSTANCE0)에 불러온다. 이를 myBitMap에 넣는다.
	myBitmap = LoadBitmap(_hInst, MAKEINTRESOURCE(_id));
	//myBitmap과 동일한 DC를 oldBitmap에 저장!(반드시 삭제를 해주는게 원칙이라 이렇게 하지 않으면 다시 그려주질 않는다.)
	oldBitmap = (HBITMAP)SelectObject(MemDC, myBitmap);

	/*
	중요!!!!!!! BITMAP클래스를 이용하여 받아온 Bitmap의 정보를 불러온다!@!!!!!
	*/
	BITMAP bit_Info;

	//GDI오브젝트의 핸들(myBitMap)값을 받아온다. 그후, 버퍼에 저장할 크기, 버퍼에 정보를 리턴받을 구조체의 포인터를 적어준다)
	//GetObject(myBitmap, ->조사하고자하는 GDI 오브젝트의 핸들
	//sizeof(bit_Info), ->버퍼에 저장할 정보의 크기
	//&bit_Info); ->오브젝트의 정보를 리턴받을 구조체의 포인터(마지막 인수를 NULL로 하면 필요한 버퍼의 크기를 리턴, 실패시 0을 리턴한다.)
	GetObject(myBitmap, sizeof(bit_Info), &bit_Info);

	//오브젝트의 사이즈를 저장
	size.cx = bit_Info.bmWidth;
	size.cy = bit_Info.bmHeight;
}

void BitMap::Draw(HDC hdc, int x, int y, int _bitsizeW, int _bitsizeH)
{
	/*
	BitBlt: 원형 그래도 그림
	StretchBit: 크기를 변경 가능
	6번째 인수 부턴 직접 그려질(눈에 보여질)크기를 설정한다.
	*/
	StretchBlt(hdc, x, y, _bitsizeW * size.cx, _bitsizeH * size.cy, MemDC, 0, 0, size.cx, size.cy, SRCCOPY);
}

//소멸자
BitMap::~BitMap()
{
	/*
	GDI오브젝트는 메모리를 사용하기 때문에 사용 후 반드시 삭제해야한다.
	이때 주의할점은 DC에 현재 선택되어있는 GDI오브젝트는 삭제할 수 없다.
	그래서 삭제하기 전에 DC에 선택된 객체를 해제해야한다.
	*/

	//현재 myBitMap이 선택 되어 있으므로, 같은 종류의 오브잭트 핸들(oldBitMap)을 선택한다.
	SelectObject(MemDC, oldBitmap);
	//선택해줫으니 삭제
	DeleteObject(myBitmap);
	//너도 삭제
	DeleteDC(MemDC);
}