#include "stdafx.h"
#include "Ball.h"

Ball::Ball(Bar* bar, const std::string n) : GameObject(n), bar(bar)
{
}

Ball::~Ball()
{
}

void Ball::SetPosition(float x, float y)
{
	circleShape.setPosition(x, y);
}

void Ball::SetPosition(const sf::Vector2f& p)
{
	circleShape.setPosition(p);
}

void Ball::SetOrigin(Origins origin)
{
	Utils::SetOrigin(circleShape, origin);
}

void Ball::SetOrigin(float x, float y)
{
	circleShape.setOrigin(x, y);
}

void Ball::Init()
{
	isLinked = true;

	circleShape.setRadius(20.f);
	circleShape.setPointCount(100);
}

void Ball::Release()
{
}

void Ball::Reset()
{
}

void Ball::Update(float dt)
{
	if (isLinked)
	{
		SetPosition(bar->rectShape.getPosition().x, bar->rectShape.getPosition().y - 20.f - 10.f);
	}
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(circleShape);
}
