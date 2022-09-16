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
	// �Ώۂ̃I�u�W�F�N�g�ɂ���ĕ���
	case eType_Enemy:
	// �G�̏ꍇ
		if (Base::CollisionCircle(this, b)) {
		// �~���m�̔���(����,�Ώ�b)
			b->SetKill();
			SetKill();
			//printf("Hit\n");
			Base::Add(new Effect(b->m_pos));
			GameData::s_score += 100;
			// �G��|���x�ɃX�R�A��100�ǉ�
		}
		break;
	}
}
