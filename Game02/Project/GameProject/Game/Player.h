#pragma once
#include "../Base/Base.h"

// Base.h‚Íˆê‚Âã‚ÌƒtƒHƒ‹ƒ_(..)
class Player : public Base{
public:
	CImage m_img;
	
public:
	
	Player(const CVector2D& pos);
	
	void Update();
	void Draw();
	void Collision(Base* b);
};
