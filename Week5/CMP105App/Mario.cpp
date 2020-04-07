#include "Mario.h"

Mario::Mario() {
	walking = false;
	swimming = false;
	ducking = false;
	duckPrev = false;
	spacePrev = false;
	unducking = false;

	swims = 2;

	facing = 0;

	idle.addFrame(sf::IntRect(0, 0, 15, 21));
	idle.setFrameSpeed(1.f/6.4f);

	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 6.4f);

	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 6.4f);

	duckDown.addFrame(sf::IntRect(16, 41, 16, 20));
	duckDown.addFrame(sf::IntRect(0, 41, 16, 20));
	duckDown.setFrameSpeed(1.f / 6.4f);

	duckUp.addFrame(sf::IntRect(16, 41, 16, 20));
	duckUp.addFrame(sf::IntRect(0, 0, 15, 21));
	duckUp.setFrameSpeed(1.f / 6.4f);

	duckDown.setLooping(false);
	duckUp.setLooping(false);
	swim.setLooping(false);

	currentAnim = &idle;
};

Mario::~Mario() {};

void Mario::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::Down) && !swimming)
	{
		ducking = true;
		currentAnim = &duckDown;
		duckUp.reset();
		duckUp.setPlaying(true);
	}
	else if (duckPrev)
	{
		ducking = false;
		duckDown.reset();
		duckDown.setPlaying(true);
		currentAnim = &duckUp;
		unducking = true;
	}

	if (!duckUp.getPlaying())
	{
		unducking = false;
	}

	if (input->isKeyDown(sf::Keyboard::Space) && swims > 0 && !spacePrev && !ducking)
	{
		swim.reset();
		swim.setPlaying(true);
		currentAnim = &swim;
		swimming = true;
		momentum.y = -400;
		swims--;
	}

	spacePrev = input->isKeyDown(sf::Keyboard::Space);

	if (!ducking)
	{
		if (input->isKeyDown(sf::Keyboard::Left) && !input->isKeyDown(sf::Keyboard::Right))
		{
			facing = 1;
			velocity.x -= 200;
		}
		if (input->isKeyDown(sf::Keyboard::Right) && !input->isKeyDown(sf::Keyboard::Left))
		{
			facing = 0;
			velocity.x += 200;
		}

		if (!swimming)
		{
			if (input->isKeyDown(sf::Keyboard::Left) || input->isKeyDown(sf::Keyboard::Right))
			{
				walking = true;
				currentAnim = &walk;
			}
			else if (!unducking)
			{
				walking = false;
				currentAnim = &idle;
			}
		}
	}
};

void Mario::update(float dt)
{
	switch (facing) {
	case 0:
		currentAnim->setFlipped(false);
		break;
	case 1:
		currentAnim->setFlipped(true);
		break;
	}

	currentAnim->animate(dt);
	setTextureRect(currentAnim->getCurrentFrame());

	velocity += momentum;

	move(velocity * dt);
	velocity = sf::Vector2f(0, 0);

	if (swimming)
	{
		momentum.y += 0.3f;
	}

	if (getPosition().y > 200)
	{
		setPosition(sf::Vector2f(getPosition().x, 200));
		swims = 2;
		swimming = false;
		momentum = sf::Vector2f(0, 0);
		swim.reset();
		swim.setPlaying(true);
		currentAnim = &idle;
	}

	duckPrev = ducking;
};