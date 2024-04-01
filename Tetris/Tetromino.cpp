#include "Tetromino.h"

Tetromino::Tetromino(const std::vector<std::vector<int>>& tetromino)
{
	this->tetromino = tetromino;
}

void Tetromino::draw(sf::RenderWindow& window) const
{
	float margin = 5.f;
	for (auto& coordenate : this->tetromino)
	{
		sf::RectangleShape block(sf::Vector2f(25, 25));
		block.setPosition(this->block_position.x + coordenate[0] * (this->block_size.x + margin), 
						  this->block_position.y + coordenate[1] * (this->block_size.y + margin));
		block.setFillColor(sf::Color::Green);
		window.draw(block);
	}
}

void Tetromino::move(const int& x, const int& y, const float& speed, sf::Clock& clock)
{
	if (clock.getElapsedTime().asSeconds() >= speed)
	{
		this->block_position.x += x; 
		this->block_position.y += y; 
		clock.restart(); 
	}
}

void Tetromino::rotation(sf::Clock& clock)
{
	int x = 0; 
	int y = 0; 
	if (clock.getElapsedTime().asSeconds() >= 0.2f) 
	{
		std::vector<std::vector<int>> rotated_tetromino = this->tetromino; 

		for (auto& coordenate : rotated_tetromino)
		{
			x = coordenate[1] * -1;
			y = coordenate[0];
			coordenate[0] = x;
			coordenate[1] = y;
		}

		this->tetromino = rotated_tetromino; 

		clock.restart(); 
	}
}

void Tetromino::collision() {
	int max_x = 0; 
	int min_x = 0; 
	for (auto& coordenate : this->tetromino) {
		if (coordenate[0] > max_x)
		{
			max_x = coordenate[0]; 
		}

		if (coordenate[0] < min_x)
		{
			min_x = coordenate[0]; 
		}
	}
}