#include "Player.h"
#include "Bullet.h"				//include忘れずに

Player::Player(const CVector2D& pos):Base(eType_Player)
{
	m_img.Load("Image/Player.png");
	m_pos = pos;
	m_rad = 12;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
	m_hp = 3;
}

void Player::Update()
{	
	const int move_speed = 4;	// 定数を使ったほうがわかりやすい
	
	// キー操作による移動
	if (HOLD(CInput::eRight))
		m_pos.x += move_speed;	// 右移動
	if (HOLD(CInput::eLeft))
		m_pos.x -= move_speed;	// 左移動
	if (PUSH(CInput::eButton1)) {
		Base::Add(new Bullet(m_pos));
	}
}

void Player::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}
