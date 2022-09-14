#pragma once
#include<GLLibrary.h>

enum {	// �񋓌^
	eType_Player,
	eType_Enemy,
	eType_Bullet,
	eType_Effect,
	eType_UI,
};

class Base {
public:
	bool m_kill;
	float m_rad;
	int m_type;
	CVector2D m_pos;
	static std::list<Base*> m_list;
public:
	//�~Base;�@���^�C�v��ݒ肵�Ă���̂ɓ��͂��Ȃ��ƃG���[�̌����ɂȂ�
	Base(int type);						// (�����t����)�R���X�g���N�^
	virtual ~Base();					// �f�X�g���N�^
	Base* Base::FindObject(int type);

	virtual void Update();		
	virtual void Draw();
	virtual void Collision(Base* b);	// �����蔻��
	void SetKill() { m_kill = true; }

	static void UpdateAll();
	static void DrowAll();
	// �S�ẴI�u�W�F�N�g�̓����蔻��
	static void CollisionAll();
	// �I�u�W�F�N�g�̒ǉ�
	static void Add(Base* b);
	// �~���m�̏Փ�
	static bool CollisionCircle(Base* b1,Base* b2);
	static void CheckKillAll();
	static std::list<Base*>FindObjects(int type);
};
