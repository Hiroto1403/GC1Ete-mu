#include "Bullet_E.h"
#include "Effect.h"
#include "GameData.h"

Bullet_E::Bullet_E(const CVector2D& pos) :Base(eType_Bullet_E)
{
	m_img.Load("Image/Bullet.png");
	m_pos = pos;
	m_rad = 12;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
}

void Bullet_E::Update()
{
	// if(アイテム取ったら){
	//		
	const int move_supeed = 3;
	m_pos.y += move_supeed;
}

void Bullet_E::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Bullet_E::Collision(Base* b)
{
	switch (b->m_type) {
		// 対象のオブジェクトによって分岐
	case eType_Player:
		// プレイヤーの場合
		if (Base::CollisionCircle(this, b)) {
			// 円同士の判定
			b->m_hp -= 1;
			// 弾が当たる度にHPを１減らす
			if (b->m_hp <= 0) {
				// HPが0以下なら倒す
				b->SetKill();
				SetKill();
				Base::Add(new Effect(b->m_pos));
			}
			SetKill();
		}
		break;
	}
}
