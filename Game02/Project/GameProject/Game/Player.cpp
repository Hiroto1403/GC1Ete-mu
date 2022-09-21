#include "Player.h"
#include "Bullet.h"				//include�Y�ꂸ��
#include"Effect.h"

Player::Player(const CVector2D& pos):Base(eType_Player)
{
	
	m_img.Load("Image/Player.png");
	m_pos = pos;
	m_rad = 12;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
	m_hp = 3;
	//�����蔻���`�ݒ�
	m_rect = CRect(-32, -128, 32, 0);
	
}

void Player::Update()
{
	
	const int move_speed = 4;	// �萔���g�����ق����킩��₷��
	
	// �L�[����ɂ��ړ�
	if (HOLD(CInput::eRight))
		m_pos.x += move_speed;	// �E�ړ�
	if (HOLD(CInput::eLeft))
		m_pos.x -= move_speed;	// ���ړ�
	//�����蔻����������邽�߂ɂ������炢��Ȃ�����������Ă�����
	if (HOLD(CInput::eUp))
		m_pos.y -= move_speed;
	if (HOLD(CInput::eDown))
		m_pos.y += move_speed;
	if (PUSH(CInput::eButton1)) {
		Base::Add(new Bullet(m_pos));
	}
}

void Player::Draw()
{
	
	m_img.SetPos(m_pos);
	m_img.Draw();
	DrawRect();
	
}

void Player::Collision(Base* b)
{
	switch (b->m_type) {
		// �Ώۂ̃I�u�W�F�N�g�ɂ���ĕ���
	case eType_Enemy:
		// �G�̏ꍇ
		if (Base::CollisionCircle(this, b)) {
			// �~���m�̔���(����,�Ώ�b)
			b->m_hp -= 1;
			b->SetKill();
			SetKill();
			//printf("Hit\n");
			Base::Add(new Effect(b->m_pos));
			

		}
		break;
	}
}
