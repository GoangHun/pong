#include "stdafx.h"
#include "Brick.h"

Brick::Brick(const std::string n)
{
	brick.setSize(sf::Vector2f(100.f, 40.f));
}

Brick::~Brick()
{
}

sf::Vector2f Brick::GetPosition()
{
	return brick.getPosition();
}

void Brick::SetPosition(float x, float y)
{
	brick.setPosition(x, y);
}

void Brick::SetPosition(const sf::Vector2f& p)
{
	brick.setPosition(p);
}

void Brick::SetOrigin(Origins origin)
{
	Utils::SetOrigin(brick, origin);
}

void Brick::SetOrigin(float x, float y)
{
	brick.setOrigin(x, y);
}

void Brick::Init()
{
}

void Brick::Release()
{
}

void Brick::Reset()
{
}

void Brick::Update(float dt)
{
}

void Brick::Draw(sf::RenderWindow& window)
{
	window.draw(brick);
}
