#pragma once

#include <SFML/Graphics.hpp>

#include "ship.h"
#include "bullet.h"
#include "asteroid.h"

class Game
{
public:
	Game();
	~Game();
	void run();
	void init();

protected:
	static const int NUM_OF_ASTEROIDS = 10; // Declaration is ok here
	static const char *GAME_NAME;   // Defined in cpp

	void createWindow();
	void update(float frameTime);
	void render(sf::RenderTarget &target);
	void onEvent(const sf::Event &event);

	void updateAsteroids(float frameTime);
	void updateBullets(float frameTime);
	void checkObjectCollision();
	void generateBullet();

private:
	Ship ship;
	std::vector<Asteroid> asteroids;
	std::vector<Bullet> bullets;

	bool shoot = false;

	sf::RenderWindow window;
	bool running;
};
