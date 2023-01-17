#include "Main.h"
#include "PadInput.h"

int Time = 10000;

int g_StartTime; //スタート時間

Main::Main()
{
	//Image = LoadGraph("images/kitchen.png");

	//現在経過時間を得る
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
