#include "stdafx.h"
#include "Bar.h"

Bar::Bar(const std::string n) : GameObject(n)
{
}

Bar::~Bar()
{
}

void Bar::SetPosition(float x, float y)
{
	rectShape.setPosition(x, y);
}

void Bar::SetPosition(const sf::Vector2f& p)
{
	rectShape.setPosition(p);
}

void Bar::SetOrigin(Origins origin)
{
	Utils::SetOrigin(rectShape, origin);
}

void Bar::SetOrigin(float x, float y)
{
	rectShape.setOrigin(x, y);
}

void Bar::Init()
{
	rectShape.setSize(sf::Vector2f(200.f, 20.f));
}

void Bar::Release()
{
}

void Bar::Reset()
{
}

void Bar::Update(float dt)
{
}

void Bar::Draw(sf::RenderWindow& window)
{
	window.draw(rectShape);
}
