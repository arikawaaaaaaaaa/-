#include "Title.h"
#include "PadInput.h"

Title::Title() {
	JoyPadX = -1;
	JoyPadY = -1;
	OldY = -1;
	flgY = 0;

	Credit = false;

	//���j���[�I��
	MenuY = 0;
	MenuNum = 0;

}

AbstractScene* Title::Update() {
	InitPad();

	if (!Credit) {
		//���j���[�J�[�\���i�O�p�`�j�̍��W
		MenuY = MenuNum * 90;
		//���j���[�J�[�\���ړ�����
		//������
		if (flgY == 0 && JoyPadY < -MARGIN) {
			if (++MenuNum > 2) MenuNum = 0;
		}
		//�����
		if (flgY == 0 && JoyPadY > MARGIN) {
			if (--MenuNum < 0) MenuNum = 2;
		}

		//���j���[�I��
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B)) {
			switch (MenuNum)
			{
			case 0:
				//return new GameSelect();	//�Q�[���I����ʂ�
				break;
			case 1:
				Credit = true;	//�Q�[���I����ʂ�
				break;
			case 2:
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
	DrawString(500, 255, "unti no zigoku", 0xffffff);
	DrawFormatString(500, 270, 0xffffff, "%d", MenuNum);
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