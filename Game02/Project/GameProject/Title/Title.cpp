#include"Title.h"
#include"../Game/Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64), m_title2_text("C:\\Windows\\Fonts\\msgothic.ttc", 32)
{
	
	m_img = COPY_RESOURCE("Title", CImage);
}




Title::~Title()
{
	//全てのオブジェクトを破棄
	Base::KillAll();
	//ゲームシーンへ移行
	Base::Add(new Game());
}

void Title::Update()
{
	//ボタン１でタイトル破棄
	if (PUSH(CInput::eButton1)) {
		SetKill();
	}
}

void Title::Draw()
{
	m_img.Draw();
	//文字表示
	
	m_title2_text.Draw(10, 700, 1, 0, 0, "Eチーム　市原　伊藤　高尾");
	m_title_text.Draw(1000/2, 514, 1, 0, 0, "Push [Z]");
}
