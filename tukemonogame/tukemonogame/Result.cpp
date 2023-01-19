#include "Result.h"
#include "Title.h"
#include "PadInput.h"

#define WIDTH 1280
#define HEIGHT 720


Result::Result(CookResult result[3], float score[3]) {

	DishImg[0][0] = LoadGraph("images/hakusai_ok.png");	//白菜：成功時
	DishImg[0][1] = LoadGraph("images/hakusai.png");	//白菜：早すぎ
	DishImg[0][2] = LoadGraph("images/failure.png");	//白菜：遅すぎ

	DishImg[1][0] = LoadGraph("images/kimuchi_ok.png");	//キムチ：成功時
	DishImg[1][1] = LoadGraph("images/hakusai.png");	//キムチ：早すぎ
	DishImg[1][2] = LoadGraph("images/failure.png");	//キムチ：遅すぎ

	DishImg[2][0] = LoadGraph("images/kyuuri_ok.png");	//きゅうり：成功時
	DishImg[2][1] = LoadGraph("images/kyuuri.png");		//きゅうり：早すぎ
	DishImg[2][2] = LoadGraph("images/failure.png");	//きゅうり：遅すぎ
	
	DishImg[3][0] = LoadGraph("images/shinsyouga_ok.png");	//新生姜：成功時
	DishImg[3][1] = LoadGraph("images/shinsyouga.png");		//新生姜：早すぎ
	DishImg[3][2] = LoadGraph("images/failure.png");		//新生姜：遅すぎ

	DishImg[4][0] = LoadGraph("images/zaasai_ok.png");			//ザーサイ：成功時
	DishImg[4][1] = LoadGraph("images/zaasai_motomura.png");	//ザーサイ：早すぎ
	DishImg[4][2] = LoadGraph("images/failure.png");			//ザーサイ：遅すぎ

	cat = LoadGraph("images/cat.png");	//ねこ
	Button = LoadGraph("images/button.png");	//ボタン

	anime = 0;	//アニメーション進行
	value = 0;	//失敗した数

	Image = LoadGraph("images/kitchen.png");	//背景画像：キッチン
	table = LoadGraph("images/table.png");		//背景画像：テーブル

	SoundMain = LoadSoundMem("sounds/main.mp3");			//BGM
	SoundScore = LoadSoundMem("sounds/ResultScore.mp3");	//結果発表SE
	SoundResultScore[0] = LoadSoundMem("sounds/MH_sound.mp3");		//１：上手にできたの効果音
	SoundResultScore[1] = LoadSoundMem("sounds/H_sound.mp3");		//２：大体上手にできたの効果音
	SoundResultScore[2] = LoadSoundMem("sounds/L_sound.mp3");		//３：うまくできなかった…の効果音
	SoundResultScore[3] = LoadSoundMem("sounds/ML_sound.mp3");		//４：残念！の効果音

	menu = 1;

	for (int i = 0; i < 3; i++) {
		this->result[i].type = result[i].type;			//料理の種類
		this->result[i].quality = result[i].quality;	//料理の出来
		this->score[i] = score[i] / -1000;				//目標時間との差
		if (this->score[i] == -0)this->score[i] = 0;

		if (this->result[i].quality)value++;			//失敗しているなら失敗数加算
	}
}


AbstractScene* Result::Update()
{
	InitPad();
	anime++;		//アニメーション進行

	//if (CheckSoundMem(SoundMain) == 0)PlaySoundMem(SoundMain, DX_PLAYTYPE_BACK, FALSE);	//BGM再生

	if (anime == 60)PlaySoundMem(SoundScore, DX_PLAYTYPE_BACK, TRUE);		//目標時間に合わせて効果音
	if (anime == 80)PlaySoundMem(SoundScore, DX_PLAYTYPE_BACK, TRUE);		//目標時間に合わせて効果音
	if (anime == 100)PlaySoundMem(SoundScore, DX_PLAYTYPE_BACK, TRUE);		//目標時間に合わせて少しずらして効果音

	if (anime > 180 && PAD_INPUT::OnClick(XINPUT_BUTTON_B)) {				//アニメーション終了後にBボタンが押された
		StopSoundMem(SoundMain);											//BGM終了
		return new Title();													//タイトル画面へ
	}
	if (anime == 140) {
		PlaySoundMem(SoundResultScore[value], DX_PLAYTYPE_BACK, TRUE);
	}

	return this;
}

void Result::Draw() const {

	//背景表示
	DrawGraph(0, 0, Image, TRUE);
	DrawGraph(0, 0, table, TRUE);

	int sizeX;	//画像サイズを格納する変数

	SetFontSize(100);
	DrawExtendGraph((WIDTH / 2) - 482, 300, (WIDTH / 2) - 182, 600, DishImg[result[0].type][result[0].quality], TRUE);	//1品目の画像表示
	
	DrawExtendGraph((WIDTH / 2) - 150, 300, (WIDTH / 2) + 150, 600, DishImg[result[1].type][result[1].quality], TRUE);	//2品目の画像表示

	DrawExtendGraph((WIDTH / 2) + 182, 300, (WIDTH / 2) + 482, 600, DishImg[result[2].type][result[2].quality], TRUE);	//3品目の画像表示

	sizeX = GetDrawStringWidth("完成！", -1) / 2;
	DrawString(WIDTH / 2 - sizeX, 40, "完成！", 0xff00);					//文字表示

	if (anime > 140) {
		switch (value)
		{
		case 0:																		//全部成功した場合の文字表示
			sizeX = GetDrawStringWidth("上手にできた！", -1) / 2;
			DrawString(WIDTH / 2 - sizeX, 140, "上手にできた！", 0xff00);
			break;

		case 1:																		//2つ成功した時の文字表示
			sizeX = GetDrawStringWidth("大体上手にできた！", -1) / 2;
			DrawString(WIDTH / 2 - sizeX, 140, "大体上手にできた！", 0xff00);
			break;

		case 2:																		//1つ成功した時の文字表示
			sizeX = GetDrawStringWidth("うまくできなかった…", -1) / 2;
			DrawString(WIDTH / 2 - sizeX, 140, "うまくできなかった…", 0xff00);
			break;

		case 3:																		//全部失敗した時の文字表示
			sizeX = GetDrawStringWidth("残念！", -1) / 2;
			DrawString(WIDTH / 2 - sizeX, 140, "残念！", 0xff00);
			break;
		}
	}

	SetFontSize(30);
	DrawString(10, 610, "目標時間まで", 0x000000);

	if (anime > 180) {
		DrawExtendGraph(940, 660, 990, 710, Button, TRUE);
		DrawString(1000, 670, "でタイトルに戻る", 0x000000);							//タイトル画面への誘導
	}

	SetFontSize(50);

	if (anime > 60) {

		sizeX = GetDrawFormatStringWidth("%.2f", score[0], -1) / 2;
		DrawFormatString((WIDTH / 2) - 332 - sizeX, 600, 0x000000, "%.2f", score[0]);	//目標時間との差(1品目)表示
	}

	if (anime > 80) {
		sizeX = GetDrawFormatStringWidth("%.2f", score[1], -1) / 2;
		DrawFormatString((WIDTH / 2) - sizeX, 600, 0x000000, "%.2f", score[1]);			//目標時間との差(2品目)表示
	}

	if (anime > 100) {
		sizeX = GetDrawFormatStringWidth("%.2f", score[2], -1) / 2;
		DrawFormatString((WIDTH / 2) + 332 - sizeX, 600, 0x000000, "%.2f", score[2]);	//目標時間との差(3品目)表示
	}


}

void Result::InitPad()
{

}
