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
	
	if (m_pos.y >= 720) {
		Base* b = Base::FindObject(eType_Player);
		// プレイヤーが存在している時のみ
		if (b) {
			b->m_hp -= 1;
			// 画面外に敵が出た数だけHP減らす

			if (b->m_hp <= 0) {
				// HPが0以下なら倒す
				b->SetKill();
				Base::Add(new Effect(b->m_pos));
			}
		}
		SetKill();
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

void Enemy::Collision(Base* b)
{
	switch (b->m_type) {
		// 対象のオブジェクトによって分岐
	case eType_Player:
		// プレイヤーの場合
		if (Base::CollisionCircle(this, b)) {
			// 円同士の判定
			b->m_hp -= 1;
			
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
