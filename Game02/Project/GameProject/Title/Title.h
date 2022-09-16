#pragma once
#include"../Base/Base.h"

class Title :public Base {
	//画像サイズ
	CImage SetSize;
	//画像オブジェクト
	CImage m_img;
	
	//文字表示オブジェクト
	CFont m_title_text;
	CFont m_title2_text;
public:
	Title();
	~Title();
	void Update();
	void Draw();
};