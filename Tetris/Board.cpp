#include "Board.h"

Board::Board(){}

void Board::draw(sf::RenderWindow& window) const
{
	int size = this->block_margin + this->block_size.x; 
	for (int x = 10; x < this->board_width; x+=size)
	{
		for (int y = 0; y < this->board_height; y +=size)
		{
			sf::RectangleShape block(this->block_size); 
			block.setPosition(x, y); 
			block.setFillColor(sf::Color(64,64,64));
			window.draw(block); 
		}
	}
}