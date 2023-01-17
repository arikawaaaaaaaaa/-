#pragma once
#include "SceneManager.h"
#include <DxLib.h>
 class End : public AbstractScene
{
private:

	int Image;


public:
	void InitPad();
	End();
	virtual ~End() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

