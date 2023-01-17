#include "Main.h"
#include "PadInput.h"

Main::Main() {

	Image = LoadGraph("images/kitchen.png");

}

AbstractScene* Main::Update() {
	InitPad();

	return this;
}

void Main::Draw() const {
	DrawGraph(0, 0, Image, FALSE);
}

void Main::InitPad() {

}
