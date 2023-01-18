#include "Title.h"
#include "Main.h"
#include "PadInput.h"
#include "End.h"

Title::Title() {
	JoyPadX = -1;
	JoyPadY = -1;
	OldY = -1;
	flgY = 0;

	Image = LoadGraph("images/title.png");

	SoundTitle = LoadSoundMem("sounds/title.mp3");
	SoundMoveCorsor = LoadSoundMem("sounds/moving-cursor-4.mp3");
	SoundDecision = LoadSoundMem("sounds/����{�^��������35.mp3");

	//���j���[�I��
	MenuY = 0;
	MenuNum = 0;

	PlaySoundMem(SoundTitle, DX_PLAYTYPE_BACK, TRUE);

}

AbstractScene* Title::Update() {
	InitPad();

		//���j���[�J�[�\���i�O�p�`�j�̍��W
		MenuY = MenuNum * 180;
		//���j���[�J�[�\���ړ�����
		//������
		if (flgY == 0 && JoyPadY < -MARGIN) {
			if (++MenuNum > 1) MenuNum = 0;
			PlaySoundMem(SoundMoveCorsor, DX_PLAYTYPE_BACK, TRUE);

		}
		//�����
		if (flgY == 0 && JoyPadY > MARGIN) {
			if (--MenuNum < 0) MenuNum = 1;
			PlaySoundMem(SoundMoveCorsor, DX_PLAYTYPE_BACK, TRUE);
		}

		//���j���[�I��
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_B)) {
			switch (MenuNum)
			{
			case 0:
				StopSoundMem(SoundTitle);
				PlaySoundMem(SoundDecision, DX_PLAYTYPE_BACK, TRUE);
				return new Main();	//�Q�[����
				break;
			case 1:
				PlaySoundMem(SoundDecision, DX_PLAYTYPE_BACK, TRUE);
				return new End();             //�Q�[���I��
				break;
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