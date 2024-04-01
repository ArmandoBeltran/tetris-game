#include "Game.h"
#include "Board.h"
#include "Tetromino.h"

Game::Game(){}

void Game::init_board(sf::RenderWindow& window) const
{ 
	board.draw(window); 
}

Tetromino Game::init_tetromino(sf::RenderWindow& window) const
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 4);

	int piece = dis(gen);

	Tetromino tetromino(this->tetrominos[4]);

	return tetromino; 
}

void Game::game_loop()
{
	sf::RenderWindow window(sf::VideoMode(620, 620), "Tetris");
	window.setFramerateLimit(this->fps_limit);

	Tetromino tetromino = init_tetromino(window); 

	sf::Event event;

	int move_x = 0.f;
	int move_y = 30.f;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			move_x = 30.f;
			move_y = 0.f;
			tetromino.move(move_x, move_y, 0.1f, this->clock);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			move_x = -30.f;
			move_y = 0.f;
			tetromino.move(move_x, move_y, 0.1f, this->clock);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			move_x = 0.f;
			move_y = 30.f;
			tetromino.move(move_x, move_y, 0.1f, this->clock);
		}
		else
		{
			move_x = 0.f;
			move_y = 30.f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			tetromino.rotation(this->clock); 
		}

		window.clear(); 
		init_board(window); 
		tetromino.draw(window); 
		tetromino.move(move_x, move_y, this->game_speed, this->clock); 
		tetromino.collision(); 
		window.display();
	}
}