﻿#include "Main.h"
#include "Result.h"
#include "PadInput.h"

#define WIDTH 1280
#define HEIGHT 720


Main::Main() {
	Target = GetRand(4);			//作る品を決める
	for (int i = 0; i < 5; i++) {
		Cooked[i] = false;
	}

	MaterialImg[0] = LoadGraph("images/hakusai.png");			//白菜の画像
	MaterialImg[1] = LoadGraph("images/hakusai.png");			//白菜の画像
	MaterialImg[2] = LoadGraph("images/kyuuri.png");			//きゅうりの画像
	MaterialImg[3] = LoadGraph("images/shinsyouga.png");		//新ショウガの画像
	MaterialImg[4] = LoadGraph("images/zaasai_motomura.png");	//ザーサイの画像

	dishImg[0] = LoadGraph("images/hakusai_ok.png");		//白菜の完成後の画像
	dishImg[1] = LoadGraph("images/kimuchi_ok.png");		//白菜の完成後（キムチ）の画像
	dishImg[2] = LoadGraph("images/kyuuri_ok.png");			//きゅうりの完成後の画像
	dishImg[3] = LoadGraph("images/shinsyouga_ok.png");		//新ショウガの完成後の画像
	dishImg[4] = LoadGraph("images/zaasai_ok.png");			//ザーサイの完成後の画像

	Pot[0] = LoadGraph("images/potback.png");	//壺：後ろ
	Pot[1] = LoadGraph("images/potflont.png");	//壺：前
	Pot[2] = LoadGraph("images/lid.png");		//壺：蓋

	rotten = LoadGraph("images/failure.png");	//失敗料理

	cat = LoadGraph("images/cat.png");			//ねこ
	Button = LoadGraph("images/button.png");	//ボタン

	SetFontSize(100);
	Image = LoadGraph("images/kitchen.png");	//背景画像

	SoundMain = LoadSoundMem("sounds/main.mp3");				//ゲームBGM
	SoundTimerStart = LoadSoundMem("sounds/timer start.mp3");	//タイマー開始時SE
	SoundTrue = LoadSoundMem("sounds/true.mp3");				//成功時SE
	SoundFalse = LoadSoundMem("sounds/false.mp3");				//失敗時SE
	SoundCat = LoadSoundMem("sounds/cat1a.mp3");				//猫

	menu = 1;						//現在の品目数
	for (int i = 0; i < 3; i++) {
		result[i].type = 0;			//料理の種類
		result[i].quality = 0;		//料理の出来(0:良い　1:早い　2:遅い)
		scoreTime[i] = 0;			//目標時間との差
	}

	Phase = 0;		//ゲーム進行
	Anime = 0;		//アニメーション進行
	CatAnime = 0;	//猫

	setTime[0] = { 10000 }; /*時間設定*/
	setTime[1] = { 17000 }; /*時間設定*/
	setTime[2] = { 4000 };	/*時間設定*/
	setTime[3] = { 14000 }; /*時間設定*/
	setTime[4] = { 8000 };	/*時間設定*/

	getTime = 0;			/*経過時間取得*/

	startTime = 0;			/*スタート時間*/

	saveTime = 0;			/*時間保存*/

	timeState = 0;			/*選択*/

	PlaySoundMem(SoundMain, DX_PLAYTYPE_BACK, TRUE);

}


AbstractScene* Main::Update()
{
	InitPad();

	if (Phase == 0) {										//ゲーム進行：目標時間表示
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B)) Phase++;	//Bを押すとゲーム進行
		
	}
	else if (Phase == 1) {									//ゲーム進行：開始時アニメーション
		Anime++;											//アニメーション用変数を変化
		if (Anime >= 60) Phase++;							//アニメーション終了時にゲーム進行

	}
	else if (Phase == 2) {									//ゲーム進行：調理
		switch (timeState)
		{
		case 0:
				
				//SE再生
				if (CheckSoundMem(SoundTimerStart) == 0)PlaySoundMem(SoundTimerStart, DX_PLAYTYPE_BACK, TRUE);
	
				//開始時の時間を取得
				startTime = GetNowCount();
				
				timeState = 1;

			break;

		case 1:
			getTime = 0 + (GetNowCount() - startTime);			/*計測時間を図る*/

			//猫
			if (setTime[Target] * 0.3 < getTime && CatAnime < 60) {
				if (CatAnime == 0)PlaySoundMem(SoundCat, DX_PLAYTYPE_BACK, TRUE);
				CatAnime++;
			}

			//計測終了
			if (PAD_INPUT::OnClick(XINPUT_BUTTON_B))
			{
				saveTime = getTime;								/*計測時間を保存する*/

				timeState = 2;									/*次へ*/
			}
			break;

		case 2:
			getTime = 0;										/*時間をリセット*/

			scoreTime[menu - 1] = saveTime - setTime[Target];	/*スコアを求める*/

			timeState = 0;
			Phase++;											//ゲーム進行
			break;
		}
	}
	else if (Phase == 3) {		//ゲーム進行：終了時アニメーション
		Anime--;				//アニメーション変数を変化
		CatAnime--;				//猫が帰る

		if (Anime == 0) {		//アニメーション終了時
			CatAnime = 0;		//猫が帰る
			Phase++;			//ゲーム進行

			if (saveTime < setTime[Target] + (3.5 * 1000) && setTime[Target] * 0.65 < saveTime) {	//目標時間に近い場合
				result[menu - 1].quality = 0;														//結果を記録
				PlaySoundMem(SoundTrue, DX_PLAYTYPE_BACK, TRUE);									//成功SE
			}
			else if (setTime[Target] + (3.5 * 1000) < saveTime) {									//目標時間から遅すぎた場合
				result[menu - 1].quality = 2;														//結果を記録
				PlaySoundMem(SoundFalse, DX_PLAYTYPE_BACK, TRUE);									//失敗SE
			}
			else if (saveTime < setTime[Target] * 0.65) {											//目標時間から速すぎた場合
				result[menu - 1].quality = 1;														//結果を記録
				PlaySoundMem(SoundFalse, DX_PLAYTYPE_BACK, TRUE);									//失敗SE
			}
		}
	}
	else if (Phase == 4) {								//ゲーム進行：終了
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B)) {		//Bボタンが押された
			Phase = 0;									//進行をリセット

			result[menu - 1].type = Target;				//目標時間との差を記録

			if (menu >= 3) {							//3品作り終えた場合
				StopSoundMem(SoundMain);				//BGMを止める
				return new Result(result, scoreTime);	//リザルト画面へ移動
			}

			menu++;										//品目数を増やす

			Cooked[Target] = true;
			while (Cooked[Target]) {					//作る品を抽選
				Target = GetRand(4);
			}
		}

		/*時間経過処理*/

	}
	return this;
}

void Main::Draw() const {

	//背景画像
	DrawGraph(0, 0, Image, TRUE);
	
	if (Phase == 0) {
		int sizeX, sizeY;
		GetGraphSize(MaterialImg[Target], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), (HEIGHT / 2) - (sizeY / 2), MaterialImg[Target], TRUE);	//材料の画像を表示

		sizeX = GetDrawStringWidth("1品目", -1) / 2;
		DrawFormatString(WIDTH / 2 - sizeX, 40, 0xff00, "%d品目", menu);								//品目数(3まで)

		GetGraphSize(Button, &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), (HEIGHT / 2) + 140, Button, TRUE);							//ボタン画像

		sizeX = GetDrawStringWidth("漬ける時間 00.00秒", -1) / 2;
		DrawFormatString(WIDTH / 2 - sizeX, 600, 0xff00, "漬ける時間 %2.2f秒", setTime[Target] / 1000);	//目標時間
	}
	else if (Phase <= 2) {

		//画像サイズを格納する変数
		int sizeX, sizeY;

		GetGraphSize(Pot[0], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), HEIGHT - Anime * 7, Pot[0], TRUE);											//壺画像(後ろに表示)

		GetGraphSize(MaterialImg[Target], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), (HEIGHT / 2) - (sizeY / 2) + Anime * 6, MaterialImg[Target], TRUE);		//材料画像

		GetGraphSize(Pot[0], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), HEIGHT - Anime * 7, Pot[1], TRUE);											//壺画像(前面に表示)
		DrawGraph((WIDTH / 2) - (sizeX / 2), -310 + Anime * 10, Pot[2], TRUE);											//壺のふた

		sizeX = GetDrawStringWidth("00.00", -1) / 2;
		DrawFormatString(WIDTH / 2 - sizeX, 340, 0x000000, "%4.2f", getTime / 1000);									//タイマー表示

		GetGraphSize(cat, &sizeX, &sizeY);
		DrawGraph(WIDTH / 2 - sizeX / 2 - sizeX * 3 + (sizeX / 20) * CatAnime, HEIGHT / 2 - (sizeY / 2), cat, TRUE);	//猫

		if (Phase == 2) {
			GetGraphSize(Button, &sizeX, &sizeY);
			DrawGraph((WIDTH / 2) - (sizeX / 2), (HEIGHT / 2) + 140, Button, TRUE);										//ボタン画像
		}

		sizeX = GetDrawStringWidth("漬ける時間 00.00秒", -1) / 2;
		DrawFormatString(WIDTH / 2 - sizeX, 600, 0xff00, "漬ける時間 %2.2f秒", setTime[Target] / 1000);					//目標時間表示
	
	}
	else if (Phase <= 4) {
		int sizeX, sizeY;

		GetGraphSize(Pot[0], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), HEIGHT - Anime * 7, Pot[0], TRUE);											//壺画像(後ろに表示)

		if (saveTime < setTime[Target] +(3.5 * 1000) && setTime[Target] * 0.65 < saveTime) {							//目標時間に近い場合
			GetGraphSize(dishImg[Target], &sizeX, &sizeY);
			DrawGraph((WIDTH / 2) - (sizeX / 2), (HEIGHT / 2) - (sizeY / 2) + Anime * 6, dishImg[Target], TRUE);		//完成品の画像
		}
		else if (setTime[Target] + (3.5 * 1000) < saveTime) {															//遅すぎた場合
			GetGraphSize(rotten, &sizeX, &sizeY);
			DrawGraph((WIDTH / 2) - (sizeX / 2), (HEIGHT / 2) - (sizeY / 2) + Anime * 6, rotten, TRUE);					//失敗料理の画像
		}
		else if (saveTime < setTime[Target] * 0.65) {																	//早すぎた場合
			GetGraphSize(MaterialImg[Target], &sizeX, &sizeY);
			DrawGraph((WIDTH / 2) - (sizeX / 2), (HEIGHT / 2) - (sizeY / 2) + Anime * 6, MaterialImg[Target], TRUE);	//材料の画像
		}

		GetGraphSize(Pot[0], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), HEIGHT - Anime * 7, Pot[1], TRUE);											//壺画像(前面)
		DrawGraph((WIDTH / 2) - (sizeX / 2), -310 + Anime * 10, Pot[2], TRUE);											//壺のふた

		sizeX = GetDrawStringWidth("00.00", -1) / 2;
		DrawFormatString(WIDTH / 2 - sizeX, 40 + (5 * Anime) , 0x000000, "%4.2f", saveTime / 1000);						//タイマー表示

		if (Phase == 4) {
			GetGraphSize(Button, &sizeX, &sizeY);
			DrawGraph((WIDTH / 2) - (sizeX / 2), (HEIGHT / 2) + 140, Button, TRUE);										//ボタン画像

			sizeX = GetDrawStringWidth("ああああ", -1) / 2;

			if (saveTime < setTime[Target] + (3.5 * 1000) && setTime[Target] * 0.65 < saveTime)	{
				DrawFormatString(WIDTH / 2 - sizeX, 600, 0xff00, "できた！", setTime[Target] / 1000);	//目標時間に近かった場合の文字表示
			}
			else if (setTime[Target] + (3.5 * 1000) < saveTime) {
				DrawFormatString(WIDTH / 2 - sizeX, 600, 0xff00, "遅すぎ！", setTime[Target] / 1000);	//目標時間から遅すぎた場合の文字表示
			}
			else if (saveTime < setTime[Target] * 0.65) {
				DrawFormatString(WIDTH / 2 - sizeX, 600, 0xff00, "早すぎ！", setTime[Target] / 1000);	//目標時間から速すぎた場合の文字表示
			}
		}

		GetGraphSize(cat, &sizeX, &sizeY);
		DrawTurnGraph(WIDTH / 2 - sizeX / 2 - sizeX * 3 + (sizeX / 20) * CatAnime, HEIGHT / 2 - (sizeY / 2), cat, TRUE);	//猫

	}
}

void Main::InitPad() 
{

}
