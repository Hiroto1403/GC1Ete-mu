#include "Hp.h"
#include"Player.h"

Hp::Hp():Base(eType_Hp)
{
	m_img.Load("image/Player残機.png");
}
void Hp::Draw()
{
	
	/*m_img.SetRect(0, 0, 32 * b->m_hp, 32);
	m_img.SetSize(16, 16);				// サイズ
	m_img.SetPos(600, 600);		// 座標データ
	m_img.Draw();*/
	if (Base* b = Base::FindObject(eType_Player)) {
		if (b->m_hp == 3) {
			m_img.SetRect(0, 0, 96, 32);
			m_img.SetSize(32 * 3, 32);
			m_img.SetPos(220, 0);
			m_img.Draw();

		}
		else if (b->m_hp == 2) {
			m_img.SetRect(0, 0, 64, 32);
			m_img.SetSize(32 * 2, 32);
			m_img.SetPos(220, 0);
			m_img.Draw();
		}
		else if (b->m_hp == 1) {
			m_img.SetRect(0, 0, 32, 32);
			m_img.SetSize(32, 32);
			m_img.SetPos(220, 0);
			m_img.Draw();
		}
	}
}
