#include "Zombie.h"

Zombie::Zombie()
{
	walking = false;
	facing = 0;

	walk.addFrame(sf::IntRect(111, 0, 54, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.setFrameSpeed(1.f / 6.4f);
}

Zombie::~Zombie()
{
}

void Zombie::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::Left) && !input->isKeyDown(sf::Keyboard::Right))
	{
		walk.setFlipped(true);
		walking = true;
		velocity.x -= 50;
	}
	else if (input->isKeyDown(sf::Keyboard::Right) && !input->isKeyDown(sf::Keyboard::Left))
	{
		walk.setFlipped(false);
		walking = true;
		velocity.x += 50;
	}
	else
	{
		walking = false;
	}
}

void Zombie::update(float dt)
{
	if (walking)
	{
		walk.animate(dt);
	}
	else
	{
		walk.reset();
	}
	setTextureRect(walk.getCurrentFrame());

	move(velocity * dt);
	velocity = sf::Vector2f(0, 0);
}