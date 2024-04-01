#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tetromino
{
	std::vector<std::vector<int>> tetromino; 
	sf::Vector2f block_size = sf::Vector2f(25, 25); 
	sf::Vector2f block_position = sf::Vector2f(130, 0); 

public: 

	Tetromino(const std::vector<std::vector<int>>& tetromino);

	void draw(sf::RenderWindow& window) const;
	void move(const int& x, const int& y, const float& speed, sf::Clock& clock);
	void rotation(sf::Clock& clock); 
	void collision(); 
};

