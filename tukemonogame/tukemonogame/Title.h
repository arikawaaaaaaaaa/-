#pragma once
#include <DxLib.h>
#include "SceneManager.h"

class Title : public AbstractScene {
private:
	int JoyPadX, JoyPadY;
	int OldY;
	int flgY;

	int Image;

	int SoundTitle;			//タイトルの音楽
	int SoundMoveCorsor;	//カーソル移動の効果音
	int	SoundDecision;		//決定の効果音

	int MenuY;
	int MenuNum;

public:
	void InitPad();
	Title();
	virtual ~Title() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};