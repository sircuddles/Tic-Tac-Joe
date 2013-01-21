#include "GameGrid.h"

GameGrid::GameGrid(void) {}
GameGrid::~GameGrid(void)  {}

void GameGrid::init() {
	// Load X and O graphics
	textureX.loadFromFile("images/x.png");
	textureO.loadFromFile("images/o.png");


	// Define grid square coordinates
	squareWidth = 166;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			squares[i][j].top = (i * 166);
			squares[i][j].left = (j * 166);
			squares[i][j].width = squares[i][j].height = squareWidth;
			spriteX[i][j].setTexture(textureX);
			spriteO[i][j].setTexture(textureO);
		}
	}

	playerTurn = 1;
	reset();
}

void GameGrid::update(int x, int y) {
	// Go through the grid
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// If the point intersects with a square and the square is empty
			// Set the proper sprite into position, set the element to X or O
			// and switch player turn
			if (squares[i][j].contains(x, y) && element[i][j] == 0) {
				if (playerTurn == 1) {
					spriteX[i][j].setPosition(squares[i][j].left, squares[i][j].top);
					element[i][j] = 1;
					playerTurn = 2;
				}
				else if (playerTurn == 2) {
					spriteO[i][j].setPosition(squares[i][j].left, squares[i][j].top);
					element[i][j] = 2;
					playerTurn = 1;
				}
			} // End contains loop
		} // End j loop
	} // End i loop

}

void GameGrid::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (element[i][j] == 1) {
				window.draw(spriteX[i][j]);
			}
			else if (element[i][j] == 2)
				window.draw(spriteO[i][j]);
		}
	}

	
}

void GameGrid::reset() {
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) 
			element[i][j] = 0;
}

bool GameGrid::checkWin(int player) {
	if (!isEmpty()) {
		// * * *
		// * *
		// *    *
		if ((element[0][0] == player) && (element[0][1] == player) && (element[0][2] == player)) {
			return true;
		}
		else if ((element[0][0] == player) && (element[1][0] == player) && (element[2][0] == player)) {
			return true;
		}
		else if ((element[0][0] == player) && (element[1][1] == player) && (element[2][2] == player)) {
			return true;
		}

		//    * 
		//    *
		//    *
		else if ((element[0][1] == player) && (element[1][1] == player) && (element[2][1] == player)) {
			return true;
		}

		//       *
		//    * *
		//  *   *
		else if ((element[0][2] == player) && (element[1][1] == player) && (element[2][0] == player)) {
			return true;
		}
		else if ((element[0][2] == player) && (element[1][2] == player) && (element[2][2] == player)) {
			return true;
		}

		//       
		//  * * *
		//  * * *
		else if ((element[1][0] == player) && (element[1][1] == player) && (element[1][2] == player)) {
			return true;
		}
		else if ((element[2][0] == player) && (element[2][1] == player) && (element[2][2] == player)) {
			return true;
		}
	}
	return false;
}

bool GameGrid::isEmpty() {
	int count = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (element[i][j] == 0) {
				count++;
			}
		}
	}

	if (count == 9)
		return true;
	else 
		return false;
}