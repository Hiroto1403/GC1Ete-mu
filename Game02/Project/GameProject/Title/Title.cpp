#include"Title.h"
#include"../Game/Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64), m_title2_text("C:\\Windows\\Fonts\\msgothic.ttc", 32)
{
	
	m_img = COPY_RESOURCE("Title", CImage);
}




Title::~Title()
{
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�Q�[���V�[���ֈڍs
	Base::Add(new Game());
}

void Title::Update()
{
	//�{�^���P�Ń^�C�g���j��
	if (PUSH(CInput::eButton1)) {
		SetKill();
	}
}

void Title::Draw()
{
	m_img.Draw();
	//�����\��
	
	m_title2_text.Draw(10, 700, 1, 0, 0, "E�`�[���@�s���@�ɓ��@����");
	m_title_text.Draw(1000/2, 514, 1, 0, 0, "Push [Z]");
}
