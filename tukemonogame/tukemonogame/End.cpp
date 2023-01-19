#include "End.h"
#include "PadInput.h"
#include"SceneManager.h"

#define WIDTH 1280
#define HEIGHT 720


End::End() {

	Image = LoadGraph("images/end.png");
	Imagemoto = LoadGraph("images/kitchen.png");
	Anim = 600;
	SoundEnd = LoadSoundMem("sounds/End.mp3");
	PlaySoundMem(SoundEnd, DX_PLAYTYPE_BACK, TRUE);
}

AbstractScene* End::Update() {
	InitPad();
	while ( Anim > 0) {
		Anim--;
		ClearDrawScreen();
		DrawGraph(0, 0, Imagemoto, FALSE);
		SetFontSize(32);
		ChangeFontType(DX_FONTTYPE_EDGE);	//�t�H���g��ς���
		DrawString(30, Anim, "�`�[�����[�_�[\n", 0x000000,0xffffff);
		DrawString(50, Anim + 40, "�L�� ���\n", 0x000000, 0xffffff);
		DrawString(30, Anim + 40 * 2, "�`�[�������o�[\n", 0x000000, 0xffffff);
		DrawString(50, Anim + 40 * 3, "�o�� �F�O\n", 0x000000, 0xffffff);
		DrawString(300, Anim + 40 * 3, "�ʏ� ����\n", 0x000000, 0xffffff);
		DrawString(50, Anim + 40 * 4, "�{�� �V�Q\n", 0x000000, 0xffffff);
		DrawString(300, Anim + 40 * 4, "��[ �i�M\n", 0x000000, 0xffffff);
		DrawString(50, Anim + 40 * 5, "�V�_ ���\n", 0x000000, 0xffffff);
		DrawString(580, Anim, "���؂肵���f�ވꗗ�i�h�̗��j\n", 0x000000, 0xffffff);
		DrawString(580, Anim + 40 , "�摜\n ���炷�Ƃ�\n", 0x000000, 0xffffff);
		DrawString(580, Anim + 40 * 3 ,  "���y\n ����Ƃǂ��ӂ�\n https://conte-de-fees.com/\n", 0x000000, 0xffffff);
		DrawString(580, Anim + 40 * 6, "���ʉ�\n �t���[���ʉ��E�������ʉ��f��\n�@https://taira-komori.jpn.org/\n", 0x000000, 0xffffff);
		DrawString(600, Anim + 40 * 9, "OtoLogic\n https://otologic.jp/", 0x000000, 0xffffff);
		DrawString(600, Anim + 40 * 11, "���ʉ����{\n https://soundeffect-lab.info/", 0x000000, 0xffffff);
		ScreenFlip(); 
	}
	DrawGraph(0, 0, Image, FALSE);
	//2�b��ɃQ�[���I��
	WaitTimer(2000);
	return nullptr;
}

void End::Draw() const {
	DrawGraph(0, 0, Image, FALSE);
}

void End::InitPad() {

}