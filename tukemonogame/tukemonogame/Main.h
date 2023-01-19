#pragma once
#include "SceneManager.h"
#include "common.h"
#include <DxLib.h>

class Main : public AbstractScene
{
private:
	int Target;			//�i�ڂ����߂�ϐ�

	int MaterialImg[5];	//�ޗ��摜
	int dishImg[5];		//�����摜
	int Pot[3];	//��摜
	int rotten;
	int cat;		//ねこ
	int Button;		//ボタン

	int Image;

	int SoundMain;				//ゲームメインの音楽
	int SoundTimerStart;		//タイマーの開始効果音
	int SoundTrue;				//成功時の効果音
	int SoundFalse;				//失敗時の効果音
	int SoundCat;				//猫の効果音

	int menu;			//品目数

	CookResult result[3];	//完成結果

	int Phase;			//���o�i�s�x
	int Anime;			//�A�j���[�V�����p
	int CatAnime;		//ねこアニメ

	float setTime[5]; /*���Ԑݒ�*/
	float getTime; /*�o�ߎ��Ԏ擾*/
	float startTime; //�X�^�[�g����
	float saveTime; /*���ԕۑ�*/
	float scoreTime[3]; /*�X�R�A*/
	int timeState; 

public:
	void InitPad();
	Main();
	virtual ~Main() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

