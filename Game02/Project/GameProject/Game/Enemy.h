#pragma once
#include "../Base/Base.h"

enum {
	yowa_E,
	tyuu_E,
	tuyo_E,
};

class Enemy : public Base{
public:
	CImage m_img;

	int m_cnt;		// ��������p�̃J�E���^�[
	int m_cnt_bullet[3];	// �e�̐���p,,

public:
	Enemy(const CVector2D& pos);
	void Update();
	void Draw();
};

