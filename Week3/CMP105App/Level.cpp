#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	
	circle.setRadius(15);
	circle.setFillColor(sf::Color::Black);
	circle.setPosition(100, 100);
	circle.setOutlineColor(sf::Color::White);
	circle.setOutlineThickness(2.f);
	speed = sf::Vector2f(360.f, 100);
	direction = sf::Vector2f (1.f, 0.5f);
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
	circle.move(speed.x * direction.x * dt, speed.y * direction.y * dt);

	if (circle.getPosition().x + circle.getRadius() > window->getSize().x ) {
		direction.x *= -1;
	}
	else if (circle.getPosition().x - circle.getRadius() < 0) {
		direction.x *= -1;
	}
	if (circle.getPosition().y + circle.getRadius() > window->getSize().y) {
		direction.y *= -1;
	}
	else if (circle.getPosition().y - circle.getRadius() < 0) {
		direction.y *= -1;
	}

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);

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