#pragma once
#include "SceneManager.h"
#include "common.h"
#include <DxLib.h>

class Result : public AbstractScene
{
private:
	int Target;			//�i�ڂ����߂�ϐ�

	int DishImg[5][3];	//料理画像
	int cat;		//ねこ
	int Button;		//ボタン

	int Image;
	int table;		//テーブル

	int SoundMain;			//ゲームメインの音楽

	int anime;		//アニメ
	int value;		//評価

	int menu;			//品目数
	CookResult result[3];	//完成結果
	float score[3];		//スコア時間

public:
	void InitPad();
	Result(CookResult result[3], float score[3]);
	virtual ~Result() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

