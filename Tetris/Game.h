#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "Board.h"
#include "Tetromino.h"


class Game
{
	float game_speed = 1.f;
	float fps_limit = 60.0f; 

	Board board;

	sf::Clock clock; 

	std::vector<std::vector<int>> square_shape = 
	{
		{0, 0}, {1, 0},
		{0, 1}, {1, 1}
	}; 

	std::vector<std::vector<int>> l_shape = 
	{
		{0, 0},
		{0, 1},
		{0, 2},
		{0, 3}
	};

	std::vector<std::vector<int>> s_shape = 
	{
		{0, 0},
		{0, 1},
		{1, 1},
		{1, 2}
	}; 

	std::vector<std::vector<int>> t_shape = 
	{
		{0, 0},
		{0, 1},
		{1, 1},
		{-1, 1}
	}; 

	std::vector<std::vector<int>> L_shape = 
	{
		{0, 0},
		{0, 1},
		{0, 2},
		{1, 2}
	}; 

	std::vector<std::vector<std::vector<int>>> tetrominos = 
	{
		square_shape,
		l_shape,
		L_shape,
		s_shape,
		t_shape
	}; 


public: 

	Game();

	void init_board(sf::RenderWindow& window) const;
	Tetromino init_tetromino(sf::RenderWindow& window) const; 

	void game_loop(); 

};

