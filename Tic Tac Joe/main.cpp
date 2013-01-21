#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "GameGrid.h"
#include <iostream>

void main() {
	// Create the game window
	sf::RenderWindow gameWindow(sf::VideoMode(500, 500, 32), "Tic Tac Joe", 1);

	// Load the game board
	GameBoard gameBoard;
	if (!gameBoard.init())
		std::cout << "Error loading board";

	// Load the grid
	GameGrid gameGrid;
	gameGrid.init();


	//BEGIN Event polling
	while (gameWindow.isOpen()) {
		sf::Event gameEvents;

		while (gameWindow.pollEvent(gameEvents)) {
			// Close the window if Close button or Escape key is pressed
			if ((gameEvents.type == sf::Event::Closed) || (gameEvents.key.code == sf::Keyboard::Escape))
				gameWindow.close();
				
			else if (gameEvents.type == sf::Event::MouseButtonPressed)
				gameGrid.update(gameEvents.mouseButton.x, gameEvents.mouseButton.y);


		} // END Event polling

		// Draw objects
		gameBoard.draw(gameWindow);
		gameGrid.draw(gameWindow);

		// Check for a winner
		if (gameGrid.checkWin(1)) {
			std::cout << "Player 1 Wins!";
		}
		else if (gameGrid.checkWin(2)) {
			std::cout << "Player 2 Wins!";
		}

		// Display to window then clear the screen
		gameWindow.display();
		gameWindow.clear(sf::Color::White);
	} // END gameWindow Open
};