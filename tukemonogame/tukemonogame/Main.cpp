#include "Main.h"
#include "PadInput.h"

Main::Main()
{

	Image = LoadGraph("images/kitchen.png");

	setTime[0] = { 10000 }; /*時間設定*/
	setTime[1] = { 20000 }; /*時間設定*/
	setTime[2] = { 500 };/*時間設定*/

	getTime = 0; /*経過時間取得*/

	startTime = 0; //スタート時間

	saveTime = 0; /*時間保存*/

	scoreTime = 0; /*スコア*/

	timeState = 0; /*選択*/

}


AbstractScene* Main::Update() 
{
	InitPad();


	/* 時間経過処理 */
	switch (timeState)
	{
	case 0:
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B))
		{
			startTime = GetNowCount();

			timeState = 1;
		}
		break;

	case 1:
		getTime = 0 + (GetNowCount() - startTime); /*計測時間を計る*/

		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B))
		{
			saveTime = getTime; /*計測時間を保存する*/

			timeState = 2; /*次へ*/
		}
		break;

	case 2:
		getTime = 0; /*時間をリセット*/

		scoreTime = setTime[0] - saveTime; /*スコアを求める*/

		if (scoreTime < 0) /*0より小さいとき*/
		{
			scoreTime *= -1; /*マイナスだったらプラスにする*/
		}
		timeState = 0;
		break;
	}

	return this;
}

void Main::Draw() const 
{
	DrawGraph(0, 0, Image, FALSE);

	/*時間表示*/
	SetFontSize(40);
	DrawFormatString(300, 100, 0x0000000, "%0.2f", setTime[0] / 1000); /*目標時間*/
	DrawFormatString(300, 170, 0x0000000, "%0.2f", getTime / 1000);    /*経過時間*/
	DrawFormatString(300, 200, 0x0000000, "%0.2f", saveTime / 1000);   /*保存時間*/
	DrawFormatString(300, 300, 0x0000000, "%0.2f", scoreTime / 1000);  /*スコア*/
}

void Main::InitPad() 
{

}
