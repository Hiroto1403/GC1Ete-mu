#pragma once
#include "../Base/Base.h"

class Enemy : public Base{
public:
	CImage m_img;

	int m_cnt;		// 動き制御用のカウンター
public:
	Enemy(const CVector2D& pos);
	void Update();
	void Draw();
};

