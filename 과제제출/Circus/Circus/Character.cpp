#include "Character.h"
#include "BitMapManager.h"

//생성자
Character::Character()
{
	m_pState = IDLE;
	pCur_x = 0.0f;
	pCur_y = 0.0f;
	isMoving = IDLE;
}

//캐릭터 움직이기
void Character::Move(HWND hWnd,  float _dftime)
{

	if (m_pState != JUMP)
	{
		if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			isMoving = RIGHT;
			if (pCur_x  < 9999)
			{
				pCur_x  += SPEED * _dftime;
			}
		}

		if (GetKeyState(VK_LEFT) & 0x8000)
		{
			isMoving = LEFT;
			if (pCur_x  > 0)
			{
				pCur_x  -= SPEED * _dftime;
			}

		}

		if (!(GetKeyState(VK_LEFT) & 0x8000) && !(GetKeyState(VK_RIGHT) & 0x8000))
		{
			isMoving = IDLE;
		}
	}

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (m_pState == IDLE)
		{
			// 키 다운
			m_pState = JUMP;

			//다음 점프를 계산하기 위해 현재의 현재위치를 저장해준다.
			m_fJumpX = pCur_x ;
			m_fJumpY = pCur_y;
		}
	}

	if (m_pState == JUMP)
	{
		p_CurJumpTime += _dftime;

		//원그리는 것 이것을 적절하게 조합하면 점프가 된다.
		//점프 지속시간을 체크해서 위치나 상태를 초기화 해준다.

		if (isMoving == RIGHT)
		{
			pCur_x  += 250 * _dftime;
			pCur_y = m_fJumpY - sinf(p_CurJumpTime * PI) * JUMP_POWER;
		}

		if (isMoving == LEFT)
		{
			pCur_x  -= 250 * _dftime;
			pCur_y = m_fJumpY - sinf(p_CurJumpTime * PI) * JUMP_POWER;
		}

		if (isMoving == IDLE)
		{
			pCur_y = m_fJumpY - sinf(p_CurJumpTime * PI) * JUMP_POWER;
		}

		//점프 지속시간 체크용 초기화.
		if (p_CurJumpTime > JUMP_TIME)
		{
			p_CurJumpTime = 0.0f;
			pCur_y = 0.0f;
			m_pState = IDLE;
		}
	}
}

//x좌표 반환
float Character::get_charX()
{
	return pCur_x;
}

//y좌표 반환
float Character::get_charY()
{
	return pCur_y;
}

STATE Character::get_isMoving()
{
	return isMoving;
}

//소멸자
Character::~Character()
{

}