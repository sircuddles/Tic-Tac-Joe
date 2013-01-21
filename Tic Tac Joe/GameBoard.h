#pragma once
#include <SFML/Graphics.hpp>

class GameBoard {
private:
	sf::Texture boardTexture;
	sf::Sprite boardSprite;

protected:

public:
	GameBoard(void);
	~GameBoard(void);

	bool init();
	void draw(sf::RenderWindow& window);
};

