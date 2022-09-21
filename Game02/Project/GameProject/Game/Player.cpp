#include "Player.h"
#include "Bullet.h"				//include忘れずに
#include"Effect.h"

Player::Player(const CVector2D& pos):Base(eType_Player)
{
	
	m_img.Load("Image/Player.png");
	m_pos = pos;
	m_rad = 12;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
	m_hp = 3;
	//当たり判定矩形設定
	m_rect = CRect(-32, -128, 32, 0);
	
}

void Player::Update()
{
	
	const int move_speed = 4;	// 定数を使ったほうがわかりやすい
	
	// キー操作による移動
	if (HOLD(CInput::eRight))
		m_pos.x += move_speed;	// 右移動
	if (HOLD(CInput::eLeft))
		m_pos.x -= move_speed;	// 左移動
	//当たり判定をすぐするためにつけたからいらなかったら消していいよ
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
		// 対象のオブジェクトによって分岐
	case eType_Enemy:
		// 敵の場合
		if (Base::CollisionCircle(this, b)) {
			// 円同士の判定(自分,対象b)
			b->m_hp -= 1;
			b->SetKill();
			SetKill();
			//printf("Hit\n");
			Base::Add(new Effect(b->m_pos));
			

		}
		break;
	}
}
