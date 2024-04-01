#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#define BOARD_H

class Board
{

	int board_width  = 310; 
	int board_height = 720; 

	float block_margin = 5.f; 
	sf::Vector2f block_size = sf::Vector2f(25, 25);


public: 
	
	Board();

	void draw(sf::RenderWindow& window) const; 

};

