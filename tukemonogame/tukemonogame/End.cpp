#include "End.h"
#include "PadInput.h"
#include"SceneManager.h"

static int StartTime;
int NowTime;

End::End() {

	Image = LoadGraph("images/end.png");
	static int StartTime = GetNowCount();
	NowTime = GetNowCount();
}

AbstractScene* End::Update() {
	InitPad();

	if (NowTime >= (StartTime + 3000))return nullptr;
}

void End::Draw() const {
	DrawGraph(0, 0, Image, FALSE);
}

void End::InitPad() {

}