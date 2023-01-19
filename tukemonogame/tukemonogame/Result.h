#pragma once
#include "SceneManager.h"
#include "common.h"
#include <DxLib.h>

class Result : public AbstractScene
{
private:

	int DishImg[5][3];	//料理画像
	int cat;		//ねこ
	int Button;		//ボタン

	int Image;
	int table;		//テーブル


	int SoundMain;			//ゲームメインの音楽
	int SoundScore;			//スコアの効果音
	int SoundResultScore[4];	//１：上手にできたの効果音　２：大体上手にできたの効果音　３：うまくできなかった…の効果音　４：残念！の効果音

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

