#include "Main.h"
#include "PadInput.h"

Main::Main()
{

	Image = LoadGraph("images/kitchen.png");

}

int g_NowKey;     //����̓��̓L�[

float setTime[3] = { 10000 ,20000,500 }; /*���Ԑݒ�*/

float getTime = 0; /*�o�ߎ��Ԏ擾*/

float startTime = 0; //�X�^�[�g����

float saveTime; /*���ԕۑ�*/

float scoreTime = 0; /*�X�R�A*/

int timeState; /*�I��*/

AbstractScene* Main::Update() 
{
	InitPad();

	if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
	{
		startTime = GetNowCount();

		timeState = 1;
	}

	/* ���Ԍo�ߏ��� */
	switch (timeState)
	{
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
		break;
	}

	return this;
}

void Main::Draw() const 
{
	DrawGraph(0, 0, Image, FALSE);

	/*���ԕ\��*/
	SetFontSize(40);
	DrawFormatString(300, 100, 0x0000000, "%0.2f", setTime[0] / 1000); /*�ڕW����*/
	DrawFormatString(300, 170, 0x0000000, "%0.2f", getTime / 1000);    /*�o�ߎ���*/
	DrawFormatString(300, 200, 0x0000000, "%0.2f", saveTime / 1000);   /*�ۑ�����*/
	DrawFormatString(300, 300, 0x0000000, "%0.2f", scoreTime / 1000);  /*�X�R�A*/
}

void Main::InitPad() 
{

}
