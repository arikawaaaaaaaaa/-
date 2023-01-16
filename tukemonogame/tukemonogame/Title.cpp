#include "Title.h"
#include "PadInput.h"

Title::Title() {
	JoyPadX = -1;
	JoyPadY = -1;
	OldY = -1;
	flgY = 0;

	Image = LoadGraph("images/title.png");

	Credit = false;

	//メニュー選択
	MenuY = 0;
	MenuNum = 0;

}

AbstractScene* Title::Update() {
	InitPad();

	if (!Credit) {
		//メニューカーソル（三角形）の座標
		MenuY = MenuNum * 180;
		//メニューカーソル移動処理
		//下方向
		if (flgY == 0 && JoyPadY < -MARGIN) {
			if (++MenuNum > 1) MenuNum = 0;
		}
		//上方向
		if (flgY == 0 && JoyPadY > MARGIN) {
			if (--MenuNum < 0) MenuNum = 1;
		}

		//メニュー選択
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B)) {
			switch (MenuNum)
			{
			case 0:
				//return new GameSelect();	//ゲーム選択画面へ
				break;
			case 1:
				return nullptr;             //ゲーム終了
				break;
			}
		}
	}
	else {
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B)) {
			Credit = false;
		}
	}

	return this;
}

void Title::Draw() const {
	DrawGraph(0, 0, Image, FALSE);
	DrawBox(450, 510 + MenuY, 830, 515 + MenuY, 0x00ffcc, TRUE);
}

void Title::InitPad() {

	JoyPadY = PAD_INPUT::GetPadThumbLY();

	if (OldY > MARGIN && JoyPadY > MARGIN) {
		flgY = 1;
	}
	else if (OldY < -MARGIN && JoyPadY < -MARGIN)flgY = 1;
	else flgY = 0;

	OldY = JoyPadY;
}