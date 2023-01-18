#pragma once
#include <DxLib.h>
#include "SceneManager.h"

class Title : public AbstractScene {
private:
	int JoyPadX, JoyPadY;
	int OldY;
	int flgY;

	int Image;

	int SoundTitle;			//�^�C�g���̉��y
	int SoundMoveCorsor;	//�J�[�\���ړ��̌��ʉ�
	int	SoundDecision;		//����̌��ʉ�

	int MenuY;
	int MenuNum;

public:
	void InitPad();
	Title();
	virtual ~Title() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};