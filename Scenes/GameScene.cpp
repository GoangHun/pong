#include "stdafx.h"
#include "GameScene.h"
#include "InputMgr.h"


GameScene::GameScene() : Scene(SceneId::Game)
{
}

void GameScene::Init()
{
	Release();
	Scene::Init();

	AddGo(new Bar("Bar"));
	AddGo(new Ball((Bar*)FindGo("Bar"), "Ball"));
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

}

void GameScene::Exit()
{
	Scene::Exit();
}

void GameScene::Update(float dt)
{
	Scene::Update(dt);
	if (INPUT_MGR.GetKey(sf::Keyboard::Left))
	{
		bar->SetPosition(bar->rectShape.getPosition().x + -1.f * 700.f * dt, bar->rectShape.getPosition().y);
	}
	if (INPUT_MGR.GetKey(sf::Keyboard::Right))
	{
		bar->SetPosition(bar->rectShape.getPosition().x + 1.f * 700.f * dt, bar->rectShape.getPosition().y);
	}

	for (auto go : gameObjects)
	{
		go->Update(dt);
	}
}

void GameScene::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	for (auto go : gameObjects)
	{
		go->Draw(window);
	}
	
}
