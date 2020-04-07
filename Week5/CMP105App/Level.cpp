#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	marioSheet.loadFromFile("gfx/MarioSheetT.png");
	mario.setTexture(&marioSheet);
	mario.setSize(sf::Vector2f(15, 21));
	mario.setScale(sf::Vector2f(5, 5));
	mario.setPosition(100, 200);
	mario.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	mario.handleInput();
}

// Update game objects
void Level::update(float dt)
{
	mario.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(mario);

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