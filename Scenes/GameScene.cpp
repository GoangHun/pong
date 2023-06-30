#include "stdafx.h"
#include "GameScene.h"
#include "InputMgr.h"
#include "ResourceMgr.h"
#include "TextGo.h"


GameScene::GameScene() : Scene(SceneId::Game)
{
	resources.push_back(std::make_tuple(ResourceTypes::Font, "fonts/DS-DIGI.ttf"));

	for (auto brick : bricks)
	{
		brick = new Brick();
	}
}

void GameScene::Init()
{
	Release();
	Scene::Init();

	AddGo(new Bar("Bar"));
	AddGo(new Ball((Bar*)FindGo("Bar"), "Ball"));

	AddGo(new TextGo("Score"));
	AddGo(new TextGo("Life"));

	for (auto go : gameObjects)
	{
		go->Init();
	}
}

void GameScene::Release()
{
	Scene::Release();
	if (gameObjects.empty())
	{
		return;
	}

	for (auto go : gameObjects)
	{
		//go->Release(); go 소멸자 호출에서 Release
		delete go;
	}
	gameObjects.clear();
}

void GameScene::Enter()
{
	Scene::Enter();

	bar = (Bar*)FindGo("Bar");
	bar->SetPosition(1920 * 0.5f, 1080 * 0.9f);
	bar->SetOrigin(Origins::MC);
	bar->rectShape.setFillColor(sf::Color::White);

	ball = (Ball*)FindGo("Ball");
	ball->SetPosition(bar->rectShape.getPosition().x, bar->rectShape.getPosition().y - 20.f - 10.f);
	ball->SetOrigin(Origins::MC);
	ball->circleShape.setFillColor(sf::Color::White);

	TextGo* findGo = (TextGo*)FindGo("Score");
	findGo->text.setFont(*RESOURCE_MGR.GetFont("fonts/DS-DIGI.ttf"));
	findGo->SetText("Score: " + std::to_string(score), 50, sf::Color::White, 0.f, 0.f);
	findGo->SetOrigin(Origins::TL);

	float interval = findGo->text.getLocalBounds().width + 50.f;

	findGo = (TextGo*)FindGo("Life");
	findGo->text.setFont(*RESOURCE_MGR.GetFont("fonts/DS-DIGI.ttf"));
	findGo->SetText("Life: " + std::to_string(life), 50, sf::Color::White, interval, 0.f);
	findGo->SetOrigin(Origins::TL);
}

void GameScene::Exit()
{
	Scene::Exit();
}

void GameScene::Update(float dt)
{
	Scene::Update(dt);

	for (auto go : gameObjects)
	{
		go->Update(dt);
	}

	Dead();
}

void GameScene::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	for (auto go : gameObjects)
	{
		go->Draw(window);
	}
	
}

void GameScene::Dead()
{
	if (ball->circleShape.getPosition().y > 1080)
	{
		life -= 1;

		TextGo* findGo = (TextGo*)FindGo("Life");
		findGo->SetText("Life: " + std::to_string(life));

		ball->Init();
	}
}
