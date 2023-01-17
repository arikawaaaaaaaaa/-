#pragma once
#include "SceneManager.h"
#include <DxLib.h>
class Main : public AbstractScene
{
private:
	int Target;			//品目を決める変数

	int MaterialImg[5];	//材料画像
	int dishImg[5];		//料理画像
	int Pot[3];			//壺画像
	int Image;

	int Phase;			//演出進行度
	int Anime;			//アニメーション用
public:
	void InitPad();
	Main();
	virtual ~Main() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

