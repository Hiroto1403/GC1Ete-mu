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
	m_cnt++;						// カウントアップ
	if (m_cnt >= 60) {				// 60カウント(1秒)以上なら
		m_pos.y += move_speed;		//	下移動
		m_cnt = 0;					//	カウンターリセット
	}
}

void Enemy::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}
