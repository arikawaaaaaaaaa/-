#include "DxLib.h"
#include "SceneManager.h"
#include "Title.h"
#include "PadInput.h"

#define WIDTH 1280
#define HEIGHT 720

#define FLAME 60

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//�E�C���h�E���[�h�E�t���X�N���[�����[�h�̕ύX���s��
	ChangeWindowMode(TRUE);   //(TRUE):�E�C���h���[�h�ŋN���E(FALSE):�t���X�N���[�����[�h�ŋN��

	//�E�C���h�E�T�C�Y�̕ύX
	SetGraphMode(WIDTH, HEIGHT, 32);
	SetMainWindowText("MINI GAME");

	//�`���̎w��
	SetDrawScreen(DX_SCREEN_BACK);

	//���C�u�����̏�����
	if (DxLib_Init() == -1)   return -1;

	SceneManager sceneMng(new Title());

	float NextTime = 0;		//�t���[�����̌o�ߎ���

	while (ProcessMessage() == 0 && sceneMng.Update() != nullptr || NULL) {
		PAD_INPUT::UpdateKey();
		//ESCAPE�L�[�ŏI��
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) DxLib_End();
		//if (GetJoypadXInputState(DX_INPUT_KEY_PAD1 & PAD_INPUT_2))
		//BACK�L�[�ŏI��
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_BACK)) DxLib_End();
		ClearDrawScreen();

		sceneMng.Draw();

		NextTime += 1000.0f / FLAME;					//1�t���[�����Ƃ� 1000/FLAME�~���b������
		if (NextTime > GetNowCount()) {					//�o�߃t���[��*NextTime�b�o�߂����H
			WaitTimer((int)NextTime - GetNowCount());	//���ĂȂ��Ȃ�o�߂���܂ő҂�
		}

		ScreenFlip();
		PAD_INPUT::UpdateKey();
	}

	DxLib_End();
	return 0;
}