#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"

class Mario: public GameObject
{
public:
	Mario();
	~Mario();

	void handleInput();
	void update(float dt) override;

protected:
	bool walking;
	bool swimming;
	bool ducking;
	bool duckPrev;
	bool spacePrev;
	bool unducking;
	int facing;
	int swims;
	Animation *currentAnim;
	Animation idle;
	Animation walk;
	Animation swim;
	Animation duckDown;
	Animation duckUp;
	sf::Vector2f momentum;
};

