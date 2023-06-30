#include "stdafx.h"
#include "Ball.h"
#include "InputMgr.h"

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
		Shot();
	}
	else
	{	
		SetPosition(circleShape.getPosition() + direction * speed * dt);
		IsCollided();
	}
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(circleShape);
}

bool Ball::IsCollided()
{
	if (circleShape.getPosition().x <= 20 || circleShape.getPosition().x >= 1900)
	{
		direction.x *= -1.f;
		return true;
	}
	if (circleShape.getPosition().y <= 20 || circleShape.getGlobalBounds().intersects(bar->rectShape.getGlobalBounds()))
	{
		direction.y *= -1.f;
		return true;
	}
	return false;
}

void Ball::Shot()
{
	if (isLinked && INPUT_MGR.GetKeyDown(sf::Keyboard::Space))
	{
		if (bar->GetDirection().x == 0.f)
		{
			direction.x = 1.f;
			isLinked = false;
			return;
		}
		direction.x = bar->GetDirection().x;
		isLinked = false;
	}
}



