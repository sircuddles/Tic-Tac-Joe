#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameGrid {
private:
	sf::Texture textureX;
	sf::Texture textureO;
	sf::Sprite spriteX[3][3];
	sf::Sprite spriteO[3][3];

	sf::Rect<int> squares[3][3];
	int element[3][3];
	int squareWidth;
	int playerTurn;

	
	bool isEmpty();

public:
	GameGrid(void);
	~GameGrid(void);

	bool checkWin(int player);

	void init();
	void update(int x, int y);
	void draw(sf::RenderWindow& window);
	void reset();
};