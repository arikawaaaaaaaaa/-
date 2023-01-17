#pragma once
#include "SceneManager.h"
#include <DxLib.h>
class Main : public AbstractScene
{
private:
	int Target;			//�i�ڂ����߂�ϐ�

	int MaterialImg[5];	//�ޗ��摜
	int dishImg[5];		//�����摜
	int Pot[3];			//��摜
	int Image;

	int Phase;			//���o�i�s�x
	int Anime;			//�A�j���[�V�����p

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

