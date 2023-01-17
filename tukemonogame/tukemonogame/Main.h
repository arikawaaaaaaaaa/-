#pragma once
#include "SceneManager.h"
#include <DxLib.h>
class Main : public AbstractScene
{
private:

	int Image;


public:
	void InitPad();
	Main();
	virtual ~Main() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

