#pragma once
#include "SceneManager.h"
#include "common.h"
#include <DxLib.h>

class Main : public AbstractScene
{
private:
	int Target;			//料理の種類を決める変数

	int MaterialImg[5];	//食材の完成前
	int dishImg[5];		//食材の完成後
	int Pot[3];			//壺
	int rotten;			//失敗料理
	int cat;		//ねこ
	int Button;		//ボタン

	int Image;		//背景画像

	int SoundMain;				//ゲームメインの音楽
	int SoundTimerStart;		//タイマーの開始効果音
	int SoundTrue;				//成功時の効果音
	int SoundFalse;				//失敗時の効果音
	int SoundCat;				//猫の効果音

	int menu;			//品目数

	CookResult result[3];	//完成結果

	int Phase;			//ゲーム進行
	int Anime;			//アニメーション進行
	int CatAnime;		//ねこアニメ

	float setTime[5];	/*時間設定*/
	float getTime;		/*経過時間*/
	float startTime;	//スタート時間
	float saveTime;		/*時間保存*/
	float scoreTime[3]; /*スコア*/
	int timeState; 

public:
	void InitPad();
	Main();
	virtual ~Main() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

