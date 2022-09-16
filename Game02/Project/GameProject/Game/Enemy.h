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

	int m_cnt;		// 動き制御用のカウンター
	int m_cnt_bullet[3];	// 弾の制御用,,

public:
	Enemy(const CVector2D& pos);
	void Update();
	void Draw();
};

