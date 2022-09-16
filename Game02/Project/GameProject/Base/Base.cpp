#include "Base.h"

std::list<Base*> Base::m_list;
Base::Base(int type) : m_type(type),m_pos(0,0),m_rad(0),m_kill(false)	// タイプ選択,初期化
{
}

Base::~Base()
{
}

Base* Base::FindObject(int type)
{
	auto it = m_list.begin();
	// 先頭の要素
	auto last = m_list.end();
	// 末尾の要素
	while (it != last) {
	// itが末尾でなければ
		if ((*it)->m_type == type) {
			return (*it);
			// 見つけたオブジェクトの返却
		}
		it++;
	}
	return nullptr;
}

void Base::Update()
{
}

void Base::Draw()
{
}

void Base::Collision(Base* b)	//引数は衝突対象のポインター
{
}

void Base::UpdateAll()
{
	for (auto& a : m_list) {
		a->Update();
	}
}

void Base::DrowAll()
{
	for (auto& a : m_list) {
		a->Draw();
	}
}

void Base::CollisionAll()	//当たり判定
{
	auto it1 = m_list.begin();	//begin:リストの先頭
	auto last = m_list.end();	//end:リストの最後尾
	while (it1 != last) 
	{
		auto it2 = it1;
		it2++;
		while (it2 != last) 
		{
			(*it1)->Collision(*it2);
			(*it2)->Collision(*it1);
			it2++;
		}
		it1++;
	}
}

void Base::Add(Base* b)
{
	// Type順によるアソート
	auto itr = m_list.begin();
	while (itr != m_list.end()) {
		if ((*itr)->m_type > b->m_type) {
			m_list.insert(itr, b);
			return;
		}
		itr++;
	}
	{

	}
	m_list.push_back(b);
}

void Base::KillAll()
{
	std::list<Base*>ret;
	for (auto& b : m_list) {
		b->SetKill();
	}
}

bool Base::CollisionCircle(Base* b1, Base* b2)
{
	CVector2D v = b1->m_pos - b2->m_pos;
	float l = v.Length();
	if (l < b1 -> m_rad + b2-> m_rad) {
		return true;
	}
	return false;
}

void Base::CheckKillAll()
{
	auto it = m_list.begin();
	auto last = m_list.end();
	while (it != last) {
		if ((*it)->m_kill) {
			delete(*it);
			it = m_list.erase(it);
		}
		else {
			//次へ
			it++;
		}
	}
}

std::list<Base*> Base::FindObjects(int type)
{
	std::list<Base*> ret;
	for (auto& b : m_list) {
		if (b->m_type == type)
			ret.push_back(b);
	}
	return ret;
}
