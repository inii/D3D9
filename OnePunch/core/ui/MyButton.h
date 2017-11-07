#pragma once
#include <windows.h>
#include <string>
#include <functional>
#include "Node.h"
#include "TextureCache.h"
#include "Collide.h"

class CMyButton : public CNode
{
	enum ButtonState
	{
		state_normal,
		state_suspend,
		state_clickin,
		state_disable,
	}mState;

	CMyButton();

	CTexture* mNormal;
	CTexture* mSuspend;
	CTexture* mClickin;
	CTexture* mDisable;

	std::function<void()> mClickCallback;

	CCollide mCollide;
	bool mEnable;
public:
	~CMyButton();

	void init(const string& normal,
		const string& suspend,
		const string& clickin,
		const string& disable,
		const std::function<void()>& func);//静态函数无法调用指针函数
	
	static CMyButton* create(const string& normal,
		const string& suspend,
		const string& clickin,
		const string& disable,
		const std::function<void()>& func) {
		CMyButton * p = new CMyButton();
		p->init(normal, suspend, clickin, disable, func);
		return p;
	}

	void update(float);
	void render();

	//更新碰撞区
	void updateCollide();

	void setEnable(bool b) { mEnable = b; }

	void setPosition(const D3DXVECTOR3& v) {
		m_vPos = v;
		updateCollide();
	}
};

