#include "DxLib.h"
#include "SceneManager.h"
#include "Title.h"
#include "PadInput.h"

#define WIDTH 1280
#define HEIGHT 720

#define FLAME 60

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//ウインドウモード・フルスクリーンモードの変更を行う
	ChangeWindowMode(TRUE);   //(TRUE):ウインドモードで起動・(FALSE):フルスクリーンモードで起動

	//ウインドウサイズの変更
	SetGraphMode(WIDTH, HEIGHT, 32);
	SetMainWindowText("MINI GAME");

	//描画先の指定
	SetDrawScreen(DX_SCREEN_BACK);

	//ライブラリの初期化
	if (DxLib_Init() == -1)   return -1;

	SceneManager sceneMng(new Title());

	float NextTime = 0;		//フレーム毎の経過時間

	while (ProcessMessage() == 0 && sceneMng.Update() != nullptr || NULL) {
		PAD_INPUT::UpdateKey();
		//ESCAPEキーで終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) DxLib_End();
		//if (GetJoypadXInputState(DX_INPUT_KEY_PAD1 & PAD_INPUT_2))
		//BACKキーで終了
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_BACK)) DxLib_End();
		ClearDrawScreen();

		sceneMng.Draw();

		NextTime += 1000.0f / FLAME;					//1フレームごとに 1000/FLAMEミリ秒かかる
		if (NextTime > GetNowCount()) {					//経過フレーム*NextTime秒経過した？
			WaitTimer((int)NextTime - GetNowCount());	//してないなら経過するまで待つ
		}

		ScreenFlip();
		PAD_INPUT::UpdateKey();
	}

	DxLib_End();
	return 0;
}