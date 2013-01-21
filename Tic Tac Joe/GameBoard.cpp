#include "GameBoard.h"

GameBoard::GameBoard(void) {}
GameBoard::~GameBoard(void) {}

bool GameBoard::init() {
	if (GameBoard::boardTexture.loadFromFile("images/gameBoard.png")) {
		GameBoard::boardSprite.setTexture(GameBoard::boardTexture);
		return true;
	}

	else
		return false;
}

void GameBoard::draw(sf::RenderWindow& window) {
	window.draw(GameBoard::boardSprite);
}