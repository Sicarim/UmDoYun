#include "Character.h"
#include "BitMapManager.h"
#include "GameManager.h"

//������
Character::Character()
{
}

//ĳ���� �ʱ�ȭ
void Character::Char_Init()
{
	m_pState = IDLE;
	pCur_x = 0.0f;
	pCur_y = 0.0f;
	isMoving = IDLE;
	Save_Point = 0.0f;
}

//ĳ���� �����̱�
void Character::Move(HWND hWnd,  float _dftime)
{
	if (m_pState != JUMP)
	{
		if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			isMoving = RIGHT;
			if (pCur_x  < MAX_WITHE)
			{
				pCur_x  += SPEED * _dftime;
			}
		}

		if (GetKeyState(VK_LEFT) & 0x8000)
		{
			isMoving = LEFT;
			if (pCur_x  > MIN_WITHE)
			{
				pCur_x  -= SPEED * _dftime;
			}
		}

		if (!(GetKeyState(VK_LEFT) & 0x8000) && !(GetKeyState(VK_RIGHT) & 0x8000))
		{
			isMoving = IDLE;
		}
		Make_SavePoint();
	}

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (m_pState == IDLE)
		{
			// Ű �ٿ�
			m_pState = JUMP;

			//���� ������ ����ϱ� ���� ������ ������ġ�� �������ش�.
			m_fJumpX = pCur_x;
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
			pCur_x += SPEED * _dftime;
			pCur_y = m_fJumpY - sinf(p_CurJumpTime * PI) * JUMP_POWER;
		}

		if (isMoving == LEFT)
		{
			pCur_x -= SPEED * _dftime;
			pCur_y = m_fJumpY - sinf(p_CurJumpTime * PI) * JUMP_POWER;

			if (pCur_x < MIN_WITHE)
			{
				pCur_x = 0.0f;
			}
		}

		if (isMoving == IDLE)
		{
			pCur_y = m_fJumpY - sinf(p_CurJumpTime * PI) * JUMP_POWER;
		}

		//���� ���ӽð� üũ�� �ʱ�ȭ.
		if (p_CurJumpTime > JUMP_TIME)
		{
			p_CurJumpTime = 0.0f;
			pCur_y = RESET_Y;
			m_pState = IDLE;
		}
	}
}

//���̺� ����Ʈ �����
void Character::Make_SavePoint()
{
	if (pCur_x < SAVE_POINT)
	{
		Save_Point = 250.0f;
	}
	else if (pCur_x > SAVE_POINT&& pCur_x < SAVE_POINT * 2)
	{
		Save_Point = 970.0f;
	}
	else if (pCur_x > SAVE_POINT * 2 && pCur_x < SAVE_POINT * 3)
	{
		Save_Point = 1800.0f;
	}
	else if (pCur_x > SAVE_POINT * 3 && pCur_x < SAVE_POINT * 4)
	{
		Save_Point = 2500.0f;
	}
	else if (pCur_x > SAVE_POINT * 4 && pCur_x < SAVE_POINT * 5)
	{
		Save_Point = 3400.0f;
	}
	else if (pCur_x > SAVE_POINT * 5 && pCur_x < SAVE_POINT * 6)
	{
		Save_Point = 4200.0f;
	}
	else if (pCur_x > SAVE_POINT * 6 && pCur_x < SAVE_POINT * 7)
	{
		Save_Point = 5000.0f;
	}
	else if (pCur_x > SAVE_POINT * 7 && pCur_x < SAVE_POINT * 8)
	{
		Save_Point = 5800.0f;
	}
	else if (pCur_x > SAVE_POINT * 8 && pCur_x < SAVE_POINT * 9)
	{
		Save_Point = 6600.0f;
	}
	else if (pCur_x < SAVE_POINT * 9)
	{
		Save_Point = 7400.0f;
	}
}

//x��ǥ ��ȯ
float Character::get_charX()
{
	if (GameManager::get_Instence()->get_HitCheck())
	{
		pCur_x = Save_Point;
		GameManager::get_Instence()->set_HitCheck(false);
	}
	return pCur_x;
}

//y��ǥ ��ȯ
float Character::get_charY()
{
	if (GameManager::get_Instence()->get_HitCheck())
	{
		pCur_y = RESET_Y;
		GameManager::get_Instence()->set_HitCheck(false);
	}
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