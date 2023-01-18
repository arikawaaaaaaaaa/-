#include "Result.h"
#include "PadInput.h"

#define WIDTH 1280
#define HEIGHT 720


Result::Result(CookResult result[3], float score) {
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

	Pot[0] = LoadGraph("images/potback.png");	//壺：後ろ
	Pot[1] = LoadGraph("images/potflont.png");	//壺：前
	Pot[2] = LoadGraph("images/lid.png");		//壺：蓋

	rotten = LoadGraph("images/failure.png");	//失敗料理

	cat = LoadGraph("images/cat.png");	//ねこ
	Button = LoadGraph("images/button.png");	//ボタン

	SetFontSize(100);
	Image = LoadGraph("images/kitchen.png");

	menu = 1;
	for (int i = 0; i < 3; i++) {
		this->result[i].type = result[i].type;
		this->result[i].quality = result[i].quality;
	}

	Phase = 0;
	Anime = 0;
	CatAnime = 0;

	setTime[0] = { 10000 }; /*���Ԑݒ�*/
	setTime[1] = { 17000 }; /*���Ԑݒ�*/
	setTime[2] = { 4000 };/*���Ԑݒ�*/
	setTime[3] = { 14000 }; /*���Ԑݒ�*/
	setTime[4] = { 8000 };/*���Ԑݒ�*/

	getTime = 0; /*�o�ߎ��Ԏ擾*/

	startTime = 0; //�X�^�[�g����

	saveTime = 0; /*���ԕۑ�*/

	scoreTime = 0; /*�X�R�A*/

	timeState = 0; /*�I��*/

}


AbstractScene* Result::Update()
{
	InitPad();

	return this;
}

void Result::Draw() const {

	DrawGraph(0, 0, Image, TRUE);

	for (int i = 0; i < 3; i++) {
		DrawFormatString(200 * i, 0, 0x000000, "%d", result[i].type);
		DrawFormatString(200 * i, 100, 0x000000, "%d", result[i].quality);
	}
}

void Result::InitPad()
{

}
