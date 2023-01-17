#include "End.h"
#include "PadInput.h"
#include"SceneManager.h"

End::End() {

	Image = LoadGraph("images/end.png");

}

AbstractScene* End::Update() {
	InitPad();

	WaitTimer(1000);
	return nullptr;
}

void End::Draw() const {
	DrawGraph(0, 0, Image, FALSE);
}

void End::InitPad() {

}