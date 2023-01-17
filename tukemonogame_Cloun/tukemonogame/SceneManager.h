#pragma once

//�V�[���ŕK���g������
class AbstractScene {
public:
	//�f�X�g���N�^
	virtual ~AbstractScene() {};
	//�`��ȊO�̍X�V
	virtual AbstractScene* Update() = 0;
	//�`��
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