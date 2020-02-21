#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombleWalk.loadFromFile("gfx/animZombie.png");
	zomble.setTexture(&zombleWalk);
	zomble.setSize(sf::Vector2f(55, 108));
	zomble.setPosition(100, 100);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	zomble.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(zomble);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}