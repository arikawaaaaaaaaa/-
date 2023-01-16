#pragma once
#include <DxLib.h>
#include "SceneManager.h"

class Title : public AbstractScene {
private:
	int JoyPadX, JoyPadY;
	int OldY;
	int flgY;

	bool Credit;

	int MenuY;
	int MenuNum;

public:
	void InitPad();
	Title();
	virtual ~Title() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};