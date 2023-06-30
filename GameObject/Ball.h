#pragma once
#include "GameObject.h"
#include "Bar.h"

class Ball :
    public GameObject
{
protected:
	bool isLinked = true;
	Bar* bar;

public:
	sf::CircleShape circleShape;

	Ball(Bar* bar, const std::string n);
	virtual ~Ball();

	virtual void SetPosition(float x, float y) override;
	virtual void SetPosition(const sf::Vector2f& p) override;

	virtual void SetOrigin(Origins origin) override;
	virtual void SetOrigin(float x, float y) override;

	virtual void Init() override;	//������ ����
	virtual void Release() override;	//�Ҹ��� ����
	virtual void Reset() override;	//�ʱ�ȭ ����

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
};

