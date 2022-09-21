#pragma once
#include<GLLibrary.h>

enum {	// 列挙型
	eType_Player,
	eType_Enemy,
	eType_Bullet,
	eType_Bullet_E,
	eType_Effect,
	eType_UI,
	eType_Scene,
	eType_Hp,
};

class Base {
public:
	int m_hp;
	bool m_kill;
	float m_rad;
	int m_type;
	CVector2D m_pos;
	static std::list<Base*> m_list;
	//矩形
	CRect m_rect;
public:
	//×Base;　←タイプを設定しているのに入力しないとエラーの原因になる
	Base(int type);						// (引数付きの)コンストラクタ
	virtual ~Base();					// デストラクタ
	Base* Base::FindObject(int type);

	virtual void Update();		
	virtual void Draw();
	virtual void Collision(Base* b);	// 当たり判定
	void SetKill() { m_kill = true; }

	static void UpdateAll();
	static void DrowAll();
	// 全てのオブジェクトの当たり判定
	static void CollisionAll();
	// オブジェクトの追加
	static void Add(Base* b);
	static void KillAll();
	// 円同士の衝突
	static bool CollisionCircle(Base* b1,Base* b2);
	static void CheckKillAll();
	static std::list<Base*>FindObjects(int type);
	//矩形同士の判定
	static bool CollisionRect(Base* b1, Base* b2);
	//矩形表示
	void DrawRect();
};

