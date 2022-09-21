   #include "Enemy.h"
#include "Bullet_E.h"

Enemy::Enemy(const CVector2D& pos):Base(eType_Enemy)
{
	m_img.Load("Image/Enemy.png");
	m_pos = pos;
	m_rad = 16;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
	m_hp = 1;						// ここを変更すればHPが変わる

}

void Enemy::Update()
{
	const int move_speed = 32;
	m_cnt++;						// カウントアップ
	m_cnt_bullet[yowa_E]++;
	if (m_cnt >= 60) {				// 60カウント(1秒)以上なら
		m_pos.y += move_speed;		//	下移動
		m_cnt = 0;					//	カウンターリセット
	}
	//switch (敵のタイプ){
	//case 弱敵なら:
	if (m_cnt_bullet[yowa_E] >= 120) {			// 120カウント(2秒)以上なら
		Base::Add(new Bullet_E(m_pos));	// プレイヤーを攻撃
		m_cnt_bullet[yowa_E] = 0;				//	カウンターリセット
	}
	//break;
	// 
	//case 中敵なら:
	//	if (m_cnt_bullet[tyuu_E] >= 60){
	//		Base::Add(new Bullet_E(m_pos));
	//		m_cnt_bullet[tyuu_E] = 0;
	//	}
	//break;
	// 
	//case 強敵なら:
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
