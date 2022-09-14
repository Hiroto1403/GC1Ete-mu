#include "UI.h"
#include"GameData.h"

UI::UI():Base(eType_UI)
{
	m_img.Load("Image/UI.png");
}

void UI::Draw()
{
	int score = GameData::s_score;
	for (int i = 0; i < 8; i++, score /= 10) {
	// �摜�̐؂蔲��
		int s = score % 10;
		m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
		m_img.SetSize(16, 16);				// �T�C�Y
		m_img.SetPos(200 - 16 * i, 0);		// ���W�f�[�^
		m_img.Draw();
	}

	Base* enemy = Base::FindObject(eType_Enemy);

	if (enemy == nullptr) {
	// �G�����Ȃ����
		// �Q�[���N���A�̕\��
		m_img.SetRect(0,64,0+160,64+32);
		m_img.SetSize(160,32);
		m_img.SetPos(100,200);
		m_img.Draw();
	}
}
