#include "Enemy.h"

Enemy::Enemy(const CVector2D& pos):Base(eType_Enemy)
{
	m_img.Load("Image/Enemy.png");
	m_pos = pos;
	m_rad = 16;
	m_img.SetSize(64, 64);
	m_img.SetCenter(16, 16);
}

void Enemy::Update()
{
	const int move_speed = 32;
	m_cnt++;						// �J�E���g�A�b�v
	if (m_cnt >= 60) {				// 60�J�E���g(1�b)�ȏ�Ȃ�
		m_pos.y += move_speed;		//	���ړ�
		m_cnt = 0;					//	�J�E���^�[���Z�b�g
	}
}

void Enemy::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}
