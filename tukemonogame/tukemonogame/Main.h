#pragma once
#include "SceneManager.h"
#include <DxLib.h>
class Main : public AbstractScene
{
private:

	int Image;

	float setTime[3]; /*時間設定*/
	float getTime; /*経過時間取得*/
	float startTime; //スタート時間
	float saveTime; /*時間保存*/
	float scoreTime; /*スコア*/
	int timeState; /*選択*/

public:
	void InitPad();
	Main();
	virtual ~Main() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

