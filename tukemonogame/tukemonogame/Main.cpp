#include "Main.h"
#include "PadInput.h"

#define WIDTH 1280
#define HEIGHT 720

Main::Main() {
	Target = GetRand(4);

	MaterialImg[0] = LoadGraph("images/hakusai.png");	//Þ—¿‰æ‘œ
	MaterialImg[1] = LoadGraph("images/hakusai.png");	//Þ—¿‰æ‘œ
	MaterialImg[2] = LoadGraph("images/kyuuri.png");	//Þ—¿‰æ‘œ
	MaterialImg[3] = LoadGraph("images/shinsyouga.png");	//Þ—¿‰æ‘œ
	MaterialImg[4] = LoadGraph("images/zaasai_motomura.png");	//Þ—¿‰æ‘œ

	dishImg[0] = LoadGraph("images/hakusai_ok.png");		//—¿—‰æ‘œ
	dishImg[1] = LoadGraph("images/kimuchi_ok.png");		//—¿—‰æ‘œ
	dishImg[2] = LoadGraph("images/kyuuri_ok.png");		//—¿—‰æ‘œ
	dishImg[3] = LoadGraph("images/shinsyouga_ok.png");		//—¿—‰æ‘œ
	dishImg[4] = LoadGraph("images/zaasai_ok.png");		//—¿—‰æ‘œ

	Pot[0] = LoadGraph("images/potback.png");
	Pot[1] = LoadGraph("images/potflont.png");
	Pot[2] = LoadGraph("images/lid.png");

	SetFontSize(100);
	Image = LoadGraph("images/kitchen.png");

	Phase = 0;
	Anime = 0;
}

AbstractScene* Main::Update() {
	InitPad();

	if (Phase == 0) {
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B)) Phase++;
	}
	else if (Phase == 1) {
		Anime++;
		if (Anime >= 60) Phase++;
	}
	else if (Phase == 2) {
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B)) Phase++;
	}
	else if (Phase == 3) {
		Anime--;
		if (Anime == 0) Phase++;
	}
	else if (Phase == 4) {
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B)) {
			Phase = 0;
			Target = GetRand(4);
		}
	}

	return this;
}

void Main::Draw() const {

	DrawGraph(0, 0, Image, TRUE);

	if (Phase == 0) {
		int sizeX, sizeY;
		GetGraphSize(MaterialImg[Target], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), (HEIGHT / 2) - (sizeY / 2), MaterialImg[Target], TRUE);

		sizeX = GetDrawStringWidth("ˆê•i–Ú", -1) / 2;
		DrawString(WIDTH / 2 - sizeX, 60, "ˆê•i–Ú", 0x00ff00);
	}
	else if (Phase <= 2) {
		int sizeX, sizeY;

		GetGraphSize(Pot[0], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), HEIGHT - Anime * 7, Pot[0], TRUE);

		GetGraphSize(MaterialImg[Target], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), (HEIGHT / 2) - (sizeY / 2) + Anime * 6, MaterialImg[Target], TRUE);

		GetGraphSize(Pot[0], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), HEIGHT - Anime * 7, Pot[1], TRUE);
		DrawGraph((WIDTH / 2) - (sizeX / 2), -310 + Anime * 10, Pot[2], TRUE);
	
	}
	else if (Phase <= 4) {
		int sizeX, sizeY;

		GetGraphSize(Pot[0], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), HEIGHT - Anime * 7, Pot[0], TRUE);

		GetGraphSize(dishImg[Target], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), (HEIGHT / 2) - (sizeY / 2) + Anime * 6, dishImg[Target], TRUE);

		GetGraphSize(Pot[0], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), HEIGHT - Anime * 7, Pot[1], TRUE);
		DrawGraph((WIDTH / 2) - (sizeX / 2), -310 + Anime * 10, Pot[2], TRUE);

	}

}

void Main::InitPad() {

}
