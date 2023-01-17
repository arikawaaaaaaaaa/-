#include "Main.h"
#include "PadInput.h"

#define WIDTH 1280
#define HEIGHT 720


Main::Main() {
	Target = GetRand(4);

	MaterialImg[0] = LoadGraph("images/hakusai.png");	//�ޗ��摜
	MaterialImg[1] = LoadGraph("images/hakusai.png");	//�ޗ��摜
	MaterialImg[2] = LoadGraph("images/kyuuri.png");	//�ޗ��摜
	MaterialImg[3] = LoadGraph("images/shinsyouga.png");	//�ޗ��摜
	MaterialImg[4] = LoadGraph("images/zaasai_motomura.png");	//�ޗ��摜

	dishImg[0] = LoadGraph("images/hakusai_ok.png");		//�����摜
	dishImg[1] = LoadGraph("images/kimuchi_ok.png");		//�����摜
	dishImg[2] = LoadGraph("images/kyuuri_ok.png");		//�����摜
	dishImg[3] = LoadGraph("images/shinsyouga_ok.png");		//�����摜
	dishImg[4] = LoadGraph("images/zaasai_ok.png");		//�����摜

	Pot[0] = LoadGraph("images/potback.png");
	Pot[1] = LoadGraph("images/potflont.png");
	Pot[2] = LoadGraph("images/lid.png");

	SetFontSize(100);
	Image = LoadGraph("images/kitchen.png");

	Phase = 0;
	Anime = 0;
	setTime[0] = { 10000 }; /*���Ԑݒ�*/
	setTime[1] = { 20000 }; /*���Ԑݒ�*/
	setTime[2] = { 500 };/*���Ԑݒ�*/

	getTime = 0; /*�o�ߎ��Ԏ擾*/

	startTime = 0; //�X�^�[�g����

	saveTime = 0; /*���ԕۑ�*/

	scoreTime = 0; /*�X�R�A*/

	timeState = 0; /*�I��*/

}


AbstractScene* Main::Update()
{
	InitPad();

	if (Phase == 0) {
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B)) Phase++;
	}
	else if (Phase == 1) {
		Anime++;
		if (Anime >= 60) Phase++;
	}
	else if (Phase == 2) {
		switch (timeState)
		{
		case 0:
				startTime = GetNowCount();

				timeState = 1;
			break;

		case 1:
			getTime = 0 + (GetNowCount() - startTime); /*�v�����Ԃ��v��*/

			if (PAD_INPUT::OnClick(XINPUT_BUTTON_B))
			{
				saveTime = getTime; /*�v�����Ԃ�ۑ�����*/

				timeState = 2; /*����*/
			}
			break;

		case 2:
			getTime = 0; /*���Ԃ����Z�b�g*/

			scoreTime = setTime[0] - saveTime; /*�X�R�A�����߂�*/

			if (scoreTime < 0) /*0��菬�����Ƃ�*/
			{
				scoreTime *= -1; /*�}�C�i�X��������v���X�ɂ���*/
			}
			timeState = 0;
			Phase++;
			break;
		}
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

		/* ���Ԍo�ߏ��� */

	}
	return this;
}

void Main::Draw() const {

	DrawGraph(0, 0, Image, TRUE);
	
	DrawFormatString(300, 100, 0x0000000, "%0.2f", setTime[0] / 1000); /*�ڕW����*/
	DrawFormatString(300, 200, 0x0000000, "%0.2f", getTime / 1000);    /*�o�ߎ���*/
	DrawFormatString(300, 250, 0x0000000, "%0.2f", saveTime / 1000);   /*�ۑ�����*/
	DrawFormatString(300, 350, 0x0000000, "%0.2f", scoreTime / 1000);  /*�X�R�A*/

	if (Phase == 0) {
		int sizeX, sizeY;
		GetGraphSize(MaterialImg[Target], &sizeX, &sizeY);
		DrawGraph((WIDTH / 2) - (sizeX / 2), (HEIGHT / 2) - (sizeY / 2), MaterialImg[Target], TRUE);

		sizeX = GetDrawStringWidth("1品目", -1) / 2;
		DrawString(WIDTH / 2 - sizeX, 60, "1品目", 0x00ff00);
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

	/*���ԕ\��*/

}

void Main::InitPad() 
{

}
