#pragma once
#include "SceneManager.h"
#include <DxLib.h>
class Main : public AbstractScene
{
private:

	int Image;

	float setTime[3]; /*���Ԑݒ�*/
	float getTime; /*�o�ߎ��Ԏ擾*/
	float startTime; //�X�^�[�g����
	float saveTime; /*���ԕۑ�*/
	float scoreTime; /*�X�R�A*/
	int timeState; /*�I��*/

public:
	void InitPad();
	Main();
	virtual ~Main() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

