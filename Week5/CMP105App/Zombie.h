#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"

class Zombie: public GameObject
{
public:
	Zombie();
	~Zombie();

	void handleInput();
	void update(float dt) override;

protected:
	bool walking;
	int facing;
	Animation walk;
};

