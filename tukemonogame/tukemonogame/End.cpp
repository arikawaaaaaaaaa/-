#include "End.h"
#include "PadInput.h"
#include"SceneManager.h"

#define WIDTH 1280
#define HEIGHT 720


End::End() {

	Image = LoadGraph("images/end.png");
	Imagemoto = LoadGraph("images/kitchen.png");
	Anim = 600;
	SoundEnd = LoadSoundMem("sounds/End.mp3");
	PlaySoundMem(SoundEnd, DX_PLAYTYPE_BACK, TRUE);
}

AbstractScene* End::Update() {
	InitPad();
	while ( Anim > 0) {
		Anim--;
		ClearDrawScreen();
		DrawGraph(0, 0, Imagemoto, FALSE);
		SetFontSize(32);
		ChangeFontType(DX_FONTTYPE_EDGE);	//フォントを変える
		DrawString(30, Anim, "チームリーダー\n", 0x000000,0xffffff);
		DrawString(50, Anim + 40, "有川 大晟\n", 0x000000, 0xffffff);
		DrawString(30, Anim + 40 * 2, "チームメンバー\n", 0x000000, 0xffffff);
		DrawString(50, Anim + 40 * 3, "與座 芳弘\n", 0x000000, 0xffffff);
		DrawString(300, Anim + 40 * 3, "玉城 流叶\n", 0x000000, 0xffffff);
		DrawString(50, Anim + 40 * 4, "本村 天鵬\n", 0x000000, 0xffffff);
		DrawString(300, Anim + 40 * 4, "喜納 司貴\n", 0x000000, 0xffffff);
		DrawString(50, Anim + 40 * 5, "新垣 大喜\n", 0x000000, 0xffffff);
		DrawString(580, Anim, "お借りした素材一覧（敬称略）\n", 0x000000, 0xffffff);
		DrawString(580, Anim + 40 , "画像\n いらすとや\n", 0x000000, 0xffffff);
		DrawString(580, Anim + 40 * 3 ,  "音楽\n こんとどぅふぇ\n https://conte-de-fees.com/\n", 0x000000, 0xffffff);
		DrawString(580, Anim + 40 * 6, "効果音\n フリー効果音・無料効果音素材\n　https://taira-komori.jpn.org/\n", 0x000000, 0xffffff);
		DrawString(600, Anim + 40 * 9, "OtoLogic\n https://otologic.jp/", 0x000000, 0xffffff);
		DrawString(600, Anim + 40 * 11, "効果音ラボ\n https://soundeffect-lab.info/", 0x000000, 0xffffff);
		ScreenFlip(); 
	}
	DrawGraph(0, 0, Image, FALSE);
	//2秒後にゲーム終了
	WaitTimer(2000);
	return nullptr;
}

void End::Draw() const {
	DrawGraph(0, 0, Image, FALSE);
}

void End::InitPad() {

}