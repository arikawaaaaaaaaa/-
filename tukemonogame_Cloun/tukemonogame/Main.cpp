#include "Main.h"
#include "PadInput.h"

int Time = 10000;

int g_StartTime; //�X�^�[�g����

Main::Main()
{
	//Image = LoadGraph("images/kitchen.png");

	//���݌o�ߎ��Ԃ𓾂�
	g_StartTime = GetNowCount();
}

AbstractScene* Main::Update() 
{
	InitPad();

	return this;
}

void Main::Draw() const 
{
	DrawGraph(0, 0, Image, FALSE);

	DrawFormatString(40, 270, 0xffff00, "%3d", Time / 1000);
}

void Main::InitPad() 
{

}
