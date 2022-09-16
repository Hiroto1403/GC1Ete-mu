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
	// if(�A�C�e���������){
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
		// �Ώۂ̃I�u�W�F�N�g�ɂ���ĕ���
	case eType_Player:
		// �v���C���[�̏ꍇ
		if (Base::CollisionCircle(this, b)) {
			// �~���m�̔���
			b->m_hp -= 1;
			// �e��������x��HP���P���炷
			if (b->m_hp <= 0) {
				// HP��0�ȉ��Ȃ�|��
				b->SetKill();
				SetKill();
				Base::Add(new Effect(b->m_pos));
			}
			SetKill();
		}
		break;
	}
}
