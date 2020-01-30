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
	speed = sf::Vector2f(200.f, 200.f);
	direction = sf::Vector2f (1.f, 1.f);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
		/*if (input->isKeyDown(sf::Keyboard::Right)) {
			direction.x = 1.f;
			input->setKeyUp(sf::Keyboard::Right);
		}
		else if (input->isKeyDown(sf::Keyboard::Left)) {
			direction.x = -1.f;
			input->setKeyUp(sf::Keyboard::Left);
		}
		else {
			direction.x = 0.f;
		}*/
{
		if (input->isKeyDown(sf::Keyboard::LShift)) {
			speed = sf::Vector2f(400.f, 400.f);
			//input->setKeyUp(sf::Keyboard::LShift);
		}
		else if (input->isKeyDown(sf::Keyboard::BackSpace)) {
			speed = sf::Vector2f(100.f, 100.f);
			//input->setKeyUp(sf::Keyboard::BackSpace);
		}
		else {
			speed = sf::Vector2f(200.f, 200.f);
		}
			
}

// Update game objects
void Level::update(float dt)
{
	
	circle.move(speed.x * direction.x * dt, speed.y * direction.y * dt);
	if (circle.getPosition().x + circle.getRadius() * 2 > window->getSize().x ) {
		direction.x *= -1;
	}
	else if (circle.getPosition().x < 0) {
		direction.x *= -1;
	}
	if (circle.getPosition().y + circle.getRadius() * 2 > window->getSize().y) {
		direction.y *= -1;
	}
	else if (circle.getPosition().y< 0) {
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