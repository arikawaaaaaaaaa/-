#pragma once
#include "SceneManager.h"
#include <DxLib.h>
 class End : public AbstractScene
{
private:

	int Image;
	int Imagemoto;

	int Anim;

	int SoundEnd;			//ƒGƒ“ƒh‚Ì‰¹Šy

public:
	void InitPad();
	End();
	virtual ~End() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

