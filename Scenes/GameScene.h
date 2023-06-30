#pragma once
#include "Scene.h"
#include "Bar.h"
#include "Ball.h"
#include "Brick.h"

class GameScene :
    public Scene
{
private:
	Bar* bar = nullptr;
	Ball* ball = nullptr;
	Brick* bricks[30];

	int score = 0;
	int life = 3;

public:
	GameScene();
	virtual ~GameScene() override = default;

	virtual void Init() override;
	virtual void Release() override;

	virtual void Enter() override;	
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void Dead();
};

