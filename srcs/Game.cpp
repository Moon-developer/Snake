/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:49:38 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/21 14:37:26 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game() {}

Game::Game(Game const & src)
{
	*this = src;	
}

Game::~Game() {}

Game & Game::operator=(Game const & src) 
{
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

void Game::runOnline(int port, std::string ip, int width, int height, int type)
{
	Interface *func;
	(void)port;
	(void)ip;

	
	// set food and snake variables
	snake.setMultiplayer();
	snake.GetWindow(width, height);
	snake.onlineReset();
	snake.setLives(9);
	snake.setDifficulty(1);
	snake.setDirection(Direction::DOWN);
	snake.setDirection2(Direction::DOWN);
	this->_width = width;
	this->_height = height;
	this->food.init(this->_width, this->_height);
	this->food.spawnFood();
	// get sfml
	try
	{
		// using only sfml for online
		func = factory.createLibrary(5, width, height);
		//func->setOnline(port, ip);
		if (type == 3)
			func->CreateServer();
		else if (type == 4)
			func->ConnectClient();
		while (snake.onlineTick(food))
		{
			if (type == 3)
				func->sendFood(food.getYPos(), food.getXPos());
			else if (type == 4)
				food.setOnlinePos(func->getFood());
			func->Render(this->food.getXPos(), this->food.getYPos(), this->food.getType(), this->snake.getSnake() ,this->snake.getSnake2(), 2);
			if (func->PollEvents() == false)
				break;
			if (func->getOnlineKey() == Keys::ESC || func->sendOnlineKey() == Keys::ESC)
				break;
			// ============ Player one ============= //
			if (type == 3)
			{
				if (func->sendOnlineKey() == Keys::KEYW)
					snake.setDirection(Direction::UP);
				if (func->sendOnlineKey() == Keys::KEYS)
					snake.setDirection(Direction::DOWN);
				if (func->sendOnlineKey() == Keys::KEYA)
					snake.setDirection(Direction::LEFT);
				if (func->sendOnlineKey() == Keys::KEYD)
					snake.setDirection(Direction::RIGHT);
				// ============== Player two =========== //
				if (func->getOnlineKey() == Keys::KEYW)
					snake.setDirection2(Direction::UP);
				if (func->getOnlineKey() == Keys::KEYS)
					snake.setDirection2(Direction::DOWN);
				if (func->getOnlineKey() == Keys::KEYA)
					snake.setDirection2(Direction::LEFT);
				if (func->getOnlineKey() == Keys::KEYD)
					snake.setDirection2(Direction::RIGHT);
			}
			else
			{
				if (func->sendOnlineKey() == Keys::KEYW)
					snake.setDirection2(Direction::UP);
				if (func->sendOnlineKey() == Keys::KEYS)
					snake.setDirection2(Direction::DOWN);
				if (func->sendOnlineKey() == Keys::KEYA)
					snake.setDirection2(Direction::LEFT);
				if (func->sendOnlineKey() == Keys::KEYD)
					snake.setDirection2(Direction::RIGHT);
				// ============== Player two =========== //
				if (func->getOnlineKey() == Keys::KEYW)
					snake.setDirection(Direction::UP);
				if (func->getOnlineKey() == Keys::KEYS)
					snake.setDirection(Direction::DOWN);
				if (func->getOnlineKey() == Keys::KEYA)
					snake.setDirection(Direction::LEFT);
				if (func->getOnlineKey() == Keys::KEYD)
					snake.setDirection(Direction::RIGHT);

			}
		}
		factory.deleteLibrary(func);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

// this will run a constant loop as long as the snake is moving
void Game::runNibbler()
{
	Display display;
	int		set = -1;

	set = display.menu();
	if (set == 3 || set == 4)
		runOnline(5000, "192.168.0.999", display.screenWidth(), display.screenHeight(), set);
	else if (set != 0)
	{
		Interface *func;
		if (set == 2)
			snake.setMultiplayer();
		this->_width = display.screenWidth();
		this->_height = display.screenHeight();
		this->food.init(this->_width, this->_height);
		this->food.spawnFood();
		snake.GetWindow(this->_width, this->_height);
		snake.reset();
		snake.setLives(display.getLives());
		snake.setDifficulty(display.getLevel());
		try
		{
			func = factory.createLibrary(display.getLibrary(), this->_width, this->_height);
			// while snake is moving aka hasn't touched a wall
			while (snake.Tick(this->food))
			{
				// ======================= added these =================== //
				display.reset();
				display.update(snake.getScore(), snake.getLives());
				display.print();
				// ===================  ^^ added these ^^ ================ //
				func->Render(this->food.getXPos(), this->food.getYPos(), this->food.getType(), this->snake.getSnake() ,this->snake.getSnake2(), set);
				if (func->PollEvents() == false)
					break;
				if (func->getKey() == Keys::F1 || func->getKey() == Keys::F2 || func->getKey() == Keys::F3)
					func = factory.createLibrary(func->getKey(), this->_width, this->_height);
				if (func->getKey() == Keys::ESC)
					break;
				if (func->getKey() == Keys::UPA)
					snake.setDirection(Direction::UP);
				if (func->getKey() == Keys::DOWNA)
					snake.setDirection(Direction::DOWN);
				if (func->getKey() == Keys::LEFTA)
					snake.setDirection(Direction::LEFT);
				if (func->getKey() == Keys::RIGHTA)
					snake.setDirection(Direction::RIGHT);
				// player two control
				if (set == 2)
				{
					if (func->getKey2() == Keys::KEYW)
						snake.setDirection2(Direction::UP);
					if (func->getKey2() == Keys::KEYS)
						snake.setDirection2(Direction::DOWN);
					if (func->getKey2() == Keys::KEYA)
						snake.setDirection2(Direction::LEFT);
					if (func->getKey2() == Keys::KEYD)
						snake.setDirection2(Direction::RIGHT);
				}
			}
			factory.deleteLibrary(func);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
