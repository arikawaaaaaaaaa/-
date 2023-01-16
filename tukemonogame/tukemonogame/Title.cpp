#include "Title.h"
#include "PadInput.h"

Title::Title() {
	JoyPadX = -1;
	JoyPadY = -1;
	OldY = -1;
	flgY = 0;

	Image = LoadGraph("images/title.png");

	Credit = false;

	//���j���[�I��
	MenuY = 0;
	MenuNum = 0;

}

AbstractScene* Title::Update() {
	InitPad();

	if (!Credit) {
		//���j���[�J�[�\���i�O�p�`�j�̍��W
		MenuY = MenuNum * 180;
		//���j���[�J�[�\���ړ�����
		//������
		if (flgY == 0 && JoyPadY < -MARGIN) {
			if (++MenuNum > 1) MenuNum = 0;
		}
		//�����
		if (flgY == 0 && JoyPadY > MARGIN) {
			if (--MenuNum < 0) MenuNum = 1;
		}

		//���j���[�I��
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B)) {
			switch (MenuNum)
			{
			case 0:
				//return new GameSelect();	//�Q�[���I����ʂ�
				break;
			case 1:
				return nullptr;             //�Q�[���I��
				break;
			}
		}
	}
	else {
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B)) {
			Credit = false;
		}
	}

	return this;
}

void Title::Draw() const {
	DrawGraph(0, 0, Image, FALSE);
	DrawBox(450, 510 + MenuY, 830, 515 + MenuY, 0x00ffcc, TRUE);
}

void Title::InitPad() {

	JoyPadY = PAD_INPUT::GetPadThumbLY();

	if (OldY > MARGIN && JoyPadY > MARGIN) {
		flgY = 1;
	}
	else if (OldY < -MARGIN && JoyPadY < -MARGIN)flgY = 1;
	else flgY = 0;

	OldY = JoyPadY;
}