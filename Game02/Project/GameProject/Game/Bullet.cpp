#include "Bullet.h"
#include "Effect.h"
#include "GameData.h"

Bullet::Bullet(const CVector2D& pos):Base(eType_Bullet)
{
	m_img.Load("Image/Bullet.png");
	m_pos = pos;
	m_rad = 12;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
}

void Bullet::Update()
{
	const int move_supeed = 4;
	m_pos.y -= move_supeed;
}

void Bullet::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Bullet::Collision(Base* b)
{
	switch(b->m_type){
	// 対象のオブジェクトによって分岐
	case eType_Enemy:
	// 敵の場合
		if (Base::CollisionCircle(this, b)) {
		// 円同士の判定(自分,対象b)
			b->SetKill();
			SetKill();
			//printf("Hit\n");
			Base::Add(new Effect(b->m_pos));
			GameData::s_score += 100;
			// 敵を倒す度にスコアを100追加
		}
		break;
	}
}
