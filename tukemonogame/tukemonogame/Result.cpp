#include "Result.h"
#include "Title.h"
#include "PadInput.h"

#define WIDTH 1280
#define HEIGHT 720


Result::Result(CookResult result[3], float score[3]) {
	Target = GetRand(4);

	DishImg[0][0] = LoadGraph("images/hakusai_ok.png");	//�ޗ��摜
	DishImg[0][1] = LoadGraph("images/hakusai.png");	//�ޗ��摜
	DishImg[0][2] = LoadGraph("images/failure.png");	//�ޗ��摜

	DishImg[1][0] = LoadGraph("images/kimuchi_ok.png");	//�ޗ��摜
	DishImg[1][1] = LoadGraph("images/hakusai.png");	//�ޗ��摜
	DishImg[1][2] = LoadGraph("images/failure.png");	//�ޗ��摜

	DishImg[2][0] = LoadGraph("images/kyuuri_ok.png");	//�ޗ��摜
	DishImg[2][1] = LoadGraph("images/kyuuri.png");	//�ޗ��摜
	DishImg[2][2] = LoadGraph("images/failure.png");	//�ޗ��摜
	
	DishImg[3][0] = LoadGraph("images/shinsyouga_ok.png");	//�ޗ��摜
	DishImg[3][1] = LoadGraph("images/shinsyouga.png");	//�ޗ��摜
	DishImg[3][2] = LoadGraph("images/failure.png");	//�ޗ��摜

	DishImg[4][0] = LoadGraph("images/zaasai_ok.png");	//�ޗ��摜
	DishImg[4][1] = LoadGraph("images/zaasai_motomura.png");	//�ޗ��摜
	DishImg[4][2] = LoadGraph("images/failure.png");	//�ޗ��摜

	cat = LoadGraph("images/cat.png");	//ねこ
	Button = LoadGraph("images/button.png");	//ボタン

	anime = 0;
	value = 0;

	Image = LoadGraph("images/kitchen.png");
	table = LoadGraph("images/table.png");

	SoundMostHight = LoadSoundMem("sounds/MH_sound.mp3");
	SoundHight = LoadSoundMem("sounds/H_sound.mp3");
	SoundLow = LoadSoundMem("sounds/L_sound.mp3");
	SoundMostLow = LoadSoundMem("sounds/ML_sound.mp3");

	menu = 1;
	for (int i = 0; i < 3; i++) {
		this->result[i].type = result[i].type;
		this->result[i].quality = result[i].quality;
		this->score[i] = score[i] / -1000;

		if (this->result[i].quality)value++;
	}
}


AbstractScene* Result::Update()
{
	InitPad();
	anime++;


	if (anime > 180 && PAD_INPUT::OnClick(XINPUT_BUTTON_B)) {
		return new Title();
	}
	if (anime == 140) {
		switch (value)
		{
		case 0:
			PlaySoundMem(SoundMostHight, DX_PLAYTYPE_BACK, TRUE);
			break;

		case 1:
			PlaySoundMem(SoundHight, DX_PLAYTYPE_BACK, TRUE);
			break;

		case 2:
			PlaySoundMem(SoundLow, DX_PLAYTYPE_BACK, TRUE);
			break;

		case 3:
			PlaySoundMem(SoundMostLow, DX_PLAYTYPE_BACK, TRUE);
			break;
		}
	}

	return this;
}

void Result::Draw() const {

	DrawGraph(0, 0, Image, TRUE);
	DrawGraph(0, 0, table, TRUE);

	int sizeX;

	SetFontSize(100);
	DrawExtendGraph((WIDTH / 2) - 482, 300, (WIDTH / 2) - 182, 600, DishImg[result[0].type][result[0].quality], TRUE);
	
	DrawExtendGraph((WIDTH / 2) - 150, 300, (WIDTH / 2) + 150, 600, DishImg[result[1].type][result[1].quality], TRUE);

	DrawExtendGraph((WIDTH / 2) + 182, 300, (WIDTH / 2) + 482, 600, DishImg[result[2].type][result[2].quality], TRUE);

	sizeX = GetDrawStringWidth("完成！", -1) / 2;
	DrawString(WIDTH / 2 - sizeX, 40, "完成！", 0xff00);

	if (anime > 140) {
		switch (value)
		{
		case 0:
			sizeX = GetDrawStringWidth("上手にできた！", -1) / 2;
			DrawString(WIDTH / 2 - sizeX, 140, "上手にできた！", 0xff00);
			break;

		case 1:
			sizeX = GetDrawStringWidth("大体上手にできた！", -1) / 2;
			DrawString(WIDTH / 2 - sizeX, 140, "大体上手にできた！", 0xff00);
			break;

		case 2:
			sizeX = GetDrawStringWidth("うまくできなかった…", -1) / 2;
			DrawString(WIDTH / 2 - sizeX, 140, "うまくできなかった…", 0xff00);
			break;

		case 3:
			sizeX = GetDrawStringWidth("残念！", -1) / 2;
			DrawString(WIDTH / 2 - sizeX, 140, "残念！", 0xff00);
			break;
		}
	}

	SetFontSize(30);
	DrawString(10, 610, "目標時間まで", 0x000000);

	if (anime > 180) {
		DrawExtendGraph(940, 660, 990, 710, Button, TRUE);
		DrawString(1000, 670, "でタイトルに戻る", 0x000000);
	}

	SetFontSize(50);

	if (anime > 60) {

		sizeX = GetDrawFormatStringWidth("%.2f", score[0], -1) / 2;
		DrawFormatString((WIDTH / 2) - 332 - sizeX, 600, 0x000000, "%.2f", score[0]);
	}

	if (anime > 80) {
		sizeX = GetDrawFormatStringWidth("%.2f", score[1], -1) / 2;
		DrawFormatString((WIDTH / 2) - sizeX, 600, 0x000000, "%.2f", score[1]);
	}

	if (anime > 100) {
		sizeX = GetDrawFormatStringWidth("%.2f", score[2], -1) / 2;
		DrawFormatString((WIDTH / 2) + 332 - sizeX, 600, 0x000000, "%.2f", score[2]);
	}


}

void Result::InitPad()
{

}
