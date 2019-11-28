#include "Character.h"
#include "BitMapManager.h"

//������
Character::Character()
{
	m_pState = IDLE;
	pCur_x = 0.0f;
	pCur_y = 0.0f;
	isMoving = IDLE;
}

//ĳ���� �����̱�
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
			// Ű �ٿ�
			m_pState = JUMP;

			//���� ������ ����ϱ� ���� ������ ������ġ�� �������ش�.
			m_fJumpX = pCur_x ;
			m_fJumpY = pCur_y;
		}
	}

	if (m_pState == JUMP)
	{
		p_CurJumpTime += _dftime;

		//���׸��� �� �̰��� �����ϰ� �����ϸ� ������ �ȴ�.
		//���� ���ӽð��� üũ�ؼ� ��ġ�� ���¸� �ʱ�ȭ ���ش�.

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

		//���� ���ӽð� üũ�� �ʱ�ȭ.
		if (p_CurJumpTime > JUMP_TIME)
		{
			p_CurJumpTime = 0.0f;
			pCur_y = 0.0f;
			m_pState = IDLE;
		}
	}
}

//x��ǥ ��ȯ
float Character::get_charX()
{
	return pCur_x;
}

//y��ǥ ��ȯ
float Character::get_charY()
{
	return pCur_y;
}

STATE Character::get_isMoving()
{
	return isMoving;
}

//�Ҹ���
Character::~Character()
{

}