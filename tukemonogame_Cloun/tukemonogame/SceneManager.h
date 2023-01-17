#pragma once

//シーンで必ず使うもの
class AbstractScene {
public:
	//デストラクタ
	virtual ~AbstractScene() {};
	//描画以外の更新
	virtual AbstractScene* Update() = 0;
	//描画
	virtual void Draw() const = 0;
};

class SceneManager : public AbstractScene {
private:
	AbstractScene* mScene;
public:
	SceneManager(AbstractScene* scene) : mScene(scene) {
	}

	~SceneManager() {
		delete mScene;
	}
	AbstractScene* Update() override;
	void Draw() const override;
};