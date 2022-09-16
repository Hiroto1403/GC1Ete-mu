#include "Game.h"
#include"Player.h"
#include"Enemy.h"
#include"../Title/Title.h"
#include"UI.h"

Game::Game():Base(eType_Scene)
{
	Base::Add(new Player(CVector2D(1280 / 2, 600)));
	int x = 100, y = 100;
	while (x <= 600) {//&&y <= 500) {
		Base::Add(new Enemy(CVector2D(x, 300)));
		x += 100;
		//y += 100;
	}
	//Base::Add(new Enemy(CVector2D(300, 100)));
	Base::Add(new UI());
}

Game::~Game()
{//�S�ẴI�u�W�F�N�g�j��
	Base::KillAll();
	//�^�C�g���V�[����
	Base::Add(new Title());
}

void Game::Update()
{
	
	//�v���C���[���S���@Z�{�^���Ń^�C�g���֖߂�
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}
	if (!Base::FindObject(eType_Enemy) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}
