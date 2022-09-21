#include "Enemy.h"
#include "Bullet_E.h"
#include"Player.h"
#include"Effect.h"

Enemy::Enemy(const CVector2D& pos):Base(eType_Enemy)
{
	m_img.Load("Image/Enemy.png");
	m_pos = pos;
	m_rad = 16;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
	m_hp = 1;						// ������ύX�����HP���ς��

}

void Enemy::Update()
{
	const int move_speed = 32;
	m_cnt++;						// �J�E���g�A�b�v
	m_cnt_bullet[yowa_E]++;
	if (m_cnt >= 60) {				// 60�J�E���g(1�b)�ȏ�Ȃ�
		m_pos.y += move_speed;		//	���ړ�
		m_cnt = 0;					//	�J�E���^�[���Z�b�g
	}
	
	if (m_pos.y >= 720) {
		Base* b = Base::FindObject(eType_Player);
		// �v���C���[�����݂��Ă��鎞�̂�
		if (b) {
			b->m_hp -= 1;
			// ��ʊO�ɓG���o��������HP���炷

			if (b->m_hp <= 0) {
				// HP��0�ȉ��Ȃ�|��
				b->SetKill();
				Base::Add(new Effect(b->m_pos));
			}
		}
		SetKill();
	}
	
	//switch (�G�̃^�C�v){
	//case ��G�Ȃ�:
	if (m_cnt_bullet[yowa_E] >= 120) {			// 120�J�E���g(2�b)�ȏ�Ȃ�
		Base::Add(new Bullet_E(m_pos));	// �v���C���[���U��
		m_cnt_bullet[yowa_E] = 0;				//	�J�E���^�[���Z�b�g
	}
	//break;
	// 
	//case ���G�Ȃ�:
	//	if (m_cnt_bullet[tyuu_E] >= 60){
	//		Base::Add(new Bullet_E(m_pos));
	//		m_cnt_bullet[tyuu_E] = 0;
	//	}
	//break;
	// 
	//case ���G�Ȃ�:
	//	if (m_cnt_bullet[tuyo_E] >= 60){
	//		Base::Add(new Bullet_E(m_pos));
	//		m_cnt_bullet[tuyo_E] = 0;
	//	}
	//break;

}

void Enemy::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Enemy::Collision(Base* b)
{
	switch (b->m_type) {
		// �Ώۂ̃I�u�W�F�N�g�ɂ���ĕ���
	case eType_Player:
		// �v���C���[�̏ꍇ
		if (Base::CollisionCircle(this, b)) {
			// �~���m�̔���
			b->m_hp -= 1;
			
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
