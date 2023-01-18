#pragma once
#include "SceneManager.h"
#include <DxLib.h>

struct Result	//完成結果
{
	int type;	//種類
	int quality;	//出来の良さ 0:良い 1:早い 2:遅い
};

class Main : public AbstractScene
{
private:
	int Target;			//�i�ڂ����߂�ϐ�

	int MaterialImg[5];	//�ޗ��摜
	int dishImg[5];		//�����摜
	int Pot[3];	//��摜
	int rotten;

	int Image;

	int SoundMain;				//ゲームメインの音楽
	int SoundTimerStart;		//タイマーの開始効果音
	int SoundTrue;				//成功時の効果音
	int SoundFalse;				//失敗時の効果音

	int menu;			//品目数
	Result result[3];	//完成結果

	int Phase;			//���o�i�s�x
	int Anime;			//�A�j���[�V�����p

	float setTime[5]; /*���Ԑݒ�*/
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

