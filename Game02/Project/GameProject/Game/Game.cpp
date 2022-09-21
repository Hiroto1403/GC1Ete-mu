#include "Game.h"
#include"Player.h"
#include"Enemy.h"
#include"../Title/Title.h"
#include"UI.h"
#include"Hp.h"

Game::Game():Base(eType_Scene)
{
	Base::Add(new Hp());
	Base::Add(new Player(CVector2D(1280 / 2, 600)));
	int x = 100, y = 200;
	while (x <= 600) {//&&y <= 500) {
		Base::Add(new Enemy(CVector2D(x, y)));
		Base::Add(new Enemy(CVector2D(x, y + 100)));
		x += 100;;
		//y += 100;
		//y += 100;
	}
	
	//Base::Add(new Enemy(CVector2D(300, 100)));
	Base::Add(new UI());
}

Game::~Game()
{//全てのオブジェクト破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game::Update()
{
	
	//プレイヤー死亡時　Zボタンでタイトルへ戻る
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}
	if (!Base::FindObject(eType_Enemy) && PUSH(CInput::eButton1)) {
		SetKill();
	}
	/*if (Base::FindObject(eType_Enemy).m_pos.y>720 && PUSH(CInput::eButton1)) {
		SetKill();
	}*/
}
