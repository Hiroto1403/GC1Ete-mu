#pragma once
#include "../Base/Base.h"
// �G�p�̒e�N���X
class Bullet_E : public Base {
public:
	CImage m_img;
public:
	Bullet_E(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
