#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Utils.h"

class GameObject
{
protected:
	std::string name;
	sf::Vector2f position;

	bool isActive = true;

public:
	int sortLayer = 0;	//직접 만들 때는 public으로 멤버변수 선언금지
	int sortOrder = 0;

	GameObject(const std::string n = "");
	virtual ~GameObject();

	bool GetActive() const;
	void SetActive(bool active);

	std::string GetName();
	void SetName(const std::string& n);

	virtual sf::Vector2f GetPosition();

	virtual void SetPosition(float x, float y);
	virtual void SetPosition(const sf::Vector2f& p);

	virtual void SetOrigin(Origins origin) {}
	virtual void SetOrigin(float x, float y) {}

	virtual void Init() = 0;	//생성자 역할
	virtual void Release() {};	//소멸자 역할
	virtual void Reset() = 0;	//초기화 역할

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};

