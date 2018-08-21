/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:55:00 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/21 10:31:05 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

Snake::Snake( void )
{

}

Snake::Snake( const Snake & src )
{
	*this = src;
	return;
}

Snake::~Snake( void )
{

}

void				Snake::GetWindow(int width, int height)
{
	this->_width = width / 16;
	this->_height = height / 16;
}

bool				Snake::onlineTick(Food & apple)
{
	clock_t time_end;
	time_end = clock() + 200 * CLOCKS_PER_SEC/1000;
	while (clock() < time_end) {}

	moveOnline();
	checkCollisionOnline();
	if (this->getSnake()[0].x == apple.getXPos() && this->getSnake()[0].y == apple.getYPos())
	{
		if (this->_difficulty == 1)
			this->_speed -= 0.0f;
		else if (this->_difficulty == 2)
			this->_speed -= 0.5f;
		else if (this->_difficulty == 3)
			this->_speed -= 1.5f;
		else if (this->_difficulty == 4)
			this->_speed -= 3.0f;
		extendSnake(1);
		if (apple.getType() == 1)
			this->_score +=5;
		else if (apple.getType() == 2)
			this->_score += 10;
		apple.spawnFood();
	}
	if (this->_player == 2)
	{
		if (getSnake2().empty())
			return false;
		if (this->getSnake2()[0].x == apple.getXPos() && this->getSnake2()[0].y == apple.getYPos())
		{
			if (this->_difficulty == 1)
				this->_speed -= 0.0f;
			else if (this->_difficulty == 2)
				this->_speed -= 0.5f;
			else if (this->_difficulty == 3)
				this->_speed -= 1.5f;
			else if (this->_difficulty == 4)
				this->_speed -= 3.0f;
			extendSnake(2);
			if (apple.getType() == 1)
				this->_score +=5;
			else if (apple.getType() == 2)
				this->_score += 10;
			apple.spawnFood();
		}
	}
	return true;
}

bool				Snake::Tick(Food & apple)
{
	clock_t time_end;
	time_end = clock() + this->_speed * CLOCKS_PER_SEC/1000;

	while (clock() < time_end) {}
	if (getSnake().empty())
		return false;
	move();
	checkCollision();
	if (this->getSnake()[0].x == apple.getXPos() && this->getSnake()[0].y == apple.getYPos())
	{
		if (this->_difficulty == 1)
			this->_speed -= 0.0f;
		else if (this->_difficulty == 2)
			this->_speed -= 0.5f;
		else if (this->_difficulty == 3)
			this->_speed -= 1.5f;
		else if (this->_difficulty == 4)
			this->_speed -= 3.0f;
		extendSnake(1);
		if (apple.getType() == 1)
			this->_score +=5;
		else if (apple.getType() == 2)
			this->_score += 10;
		apple.spawnFood();
	}
	if (this->_player == 2)
	{
		if (getSnake2().empty())
			return false;
		if (this->getSnake2()[0].x == apple.getXPos() && this->getSnake2()[0].y == apple.getYPos())
		{
			if (this->_difficulty == 1)
				this->_speed -= 0.0f;
			else if (this->_difficulty == 2)
				this->_speed -= 0.5f;
			else if (this->_difficulty == 3)
				this->_speed -= 1.5f;
			else if (this->_difficulty == 4)
				this->_speed -= 3.0f;
			extendSnake(2);
			if (apple.getType() == 1)
				this->_score +=5;
			else if (apple.getType() == 2)
				this->_score += 10;
			apple.spawnFood();
		}
	}
	return true;
}

// get player one
std::vector<Block>	Snake::getSnake( void ) const
{
	return _snakeBody;
}

// get player two
std::vector<Block>	Snake::getSnake2( void ) const
{
	return _snakeBody2;
}

void				Snake::start1(void)
{
	player1Start = true;
}

void				Snake::start2(void)
{
	player2Start = true;
}

void				Snake::moveOnline( void )
{
	// ============== player one =============== //
	if (player1Start == true)
	{
		for (int i = getSnake().size() - 1; i > 0; --i)
		{
			_snakeBody[i].x = _snakeBody[i - 1].x;
			_snakeBody[i].y = _snakeBody[i - 1].y;
		}
		if (_direction == Direction::LEFT)
			--_snakeBody[0].x;
		else if (_direction == Direction::RIGHT)
			++_snakeBody[0].x;
		else if (_direction == Direction::UP)
			--_snakeBody[0].y;
		else if (_direction == Direction::DOWN)
			++_snakeBody[0].y;
	}
	// ============= player two =============== //
	if (player2Start == true)
	{
		for (int i = getSnake2().size() - 1; i > 0; --i)
		{
			_snakeBody2[i].x = _snakeBody2[i - 1].x;
			_snakeBody2[i].y = _snakeBody2[i - 1].y;
		}
		if (_direction2 == Direction::LEFT)
			--_snakeBody2[0].x;
		else if (_direction2 == Direction::RIGHT)
			++_snakeBody2[0].x;
		else if (_direction2 == Direction::UP)
			--_snakeBody2[0].y;
		else if (_direction2 == Direction::DOWN)
			++_snakeBody2[0].y;
	}
}

void				Snake::move( void )
{
	for (int i = getSnake().size() - 1; i > 0; --i)
	{
		_snakeBody[i].x = _snakeBody[i - 1].x;
		_snakeBody[i].y = _snakeBody[i - 1].y;
	}
	if (_direction == Direction::LEFT)
		--_snakeBody[0].x;
	else if (_direction == Direction::RIGHT)
		++_snakeBody[0].x;
	else if (_direction == Direction::UP)
		--_snakeBody[0].y;
	else if (_direction == Direction::DOWN)
		++_snakeBody[0].y;
	// ============ player two movement ========= //
	if (this->_player == 2)
	{
		for (int i = getSnake2().size() - 1; i > 0; --i)
		{
			_snakeBody2[i].x = _snakeBody2[i - 1].x;
			_snakeBody2[i].y = _snakeBody2[i - 1].y;
		}
		if (_direction2 == Direction::LEFT)
			--_snakeBody2[0].x;
		else if (_direction2 == Direction::RIGHT)
			++_snakeBody2[0].x;
		else if (_direction2 == Direction::UP)
			--_snakeBody2[0].y;
		else if (_direction2 == Direction::DOWN)
			++_snakeBody2[0].y;
	}
}

void				Snake::extendSnake( int set)
{
	if (set == 1)
	{
		if (_snakeBody.empty())
			return; 
		Block &tail_head = _snakeBody[_snakeBody.size() - 1];
		if(_snakeBody.size() > 1)
		{
			Block &tail_bone = _snakeBody[_snakeBody.size() - 2];
			if(tail_head.x == tail_bone.x)
			{
				if(tail_head.y > tail_bone.y)
					_snakeBody.push_back(Block(tail_head.x, tail_head.y + 1));
				else
					_snakeBody.push_back(Block(tail_head.x, tail_head.y - 1));
			} 
			else if(tail_head.y == tail_bone.y)
			{
				if(tail_head.x > tail_bone.x)
					_snakeBody.push_back(Block(tail_head.x + 1, tail_head.y));
				else
					_snakeBody.push_back(Block(tail_head.x - 1, tail_head.y));
			}
		} 
		else
		{
			if(_direction == Direction::UP)
				_snakeBody.push_back(Block(tail_head.x, tail_head.y + 1));
			else if (_direction == Direction::DOWN)
				_snakeBody.push_back(Block(tail_head.x, tail_head.y - 1));
			else if (_direction == Direction::LEFT)
				_snakeBody.push_back(Block(tail_head.x + 1, tail_head.y));
			else if (_direction == Direction::RIGHT)
				_snakeBody.push_back(Block(tail_head.x - 1, tail_head.y));
		}
	}
	else if (set == 2)
	{
		// ================== player two =================== //
		if (_snakeBody2.empty())
			return; 
		Block &tail_head2 = _snakeBody2[_snakeBody2.size() - 1];
		if(_snakeBody2.size() > 1)
		{
			Block &tail_bone2 = _snakeBody2[_snakeBody2.size() - 2];
			if(tail_head2.x == tail_bone2.x)
			{
				if(tail_head2.y > tail_bone2.y)
					_snakeBody2.push_back(Block(tail_head2.x, tail_head2.y + 1));
				else
					_snakeBody2.push_back(Block(tail_head2.x, tail_head2.y - 1));
			} 
			else if(tail_head2.y == tail_bone2.y)
			{
				if(tail_head2.x > tail_bone2.x)
					_snakeBody2.push_back(Block(tail_head2.x + 1, tail_head2.y));
				else
					_snakeBody2.push_back(Block(tail_head2.x - 1, tail_head2.y));
			}
		} 
		else
		{
			if(_direction2 == Direction::UP)
				_snakeBody2.push_back(Block(tail_head2.x, tail_head2.y + 1));
			else if (_direction2 == Direction::DOWN)
				_snakeBody2.push_back(Block(tail_head2.x, tail_head2.y - 1));
			else if (_direction2 == Direction::LEFT)
				_snakeBody2.push_back(Block(tail_head2.x + 1, tail_head2.y));
			else if (_direction2 == Direction::RIGHT)
				_snakeBody2.push_back(Block(tail_head2.x - 1, tail_head2.y));
		}

	}
}

void				Snake::checkCollisionOnline( void )
{
	Block &head = _snakeBody.front();
	for(auto itr = _snakeBody.begin() + 1; itr != _snakeBody.end(); ++itr)
		if(itr->x == head.x && itr->y == head.y)
		{
			this->reset();
			break;
		}	
	if (head.x <= 0 || head.y <= 0 || head.x >= _width - 1 || head.y >= _height - 1)
		this->reset();
	Block &head2 = _snakeBody2.front();
	for(auto itr = _snakeBody2.begin() + 1; itr != _snakeBody2.end(); ++itr)
		if(itr->x == head2.x && itr->y == head2.y)
		{
			this->reset();
			break;
		}	
	if (head2.x <= 0 || head2.y <= 0 || head2.x >= _width - 1 || head2.y >= _height - 1)
		this->reset();
}

void				Snake::checkCollision( void )
{
	if (_snakeBody.size() < 4)
		return; 
	Block &head = _snakeBody.front();
	for(auto itr = _snakeBody.begin() + 1; itr != _snakeBody.end(); ++itr)
	{
		if(itr->x == head.x && itr->y == head.y)
		{
			this->_lives -= 1;
			if (this->_lives <= 0)
			{
				this->_lives = this->_resetLives;
				this->_score = 0;
			}
			this->reset();
			break;
		}	
	}
	if (head.x <= 0 || head.y <= 0 || head.x >= _width - 1 || head.y >= _height - 1)
	{
		this->_lives -= 1;
		if (this->_lives <= 0)
		{
			this->_lives = this->_resetLives;
			this->_score = 0;
		}
		this->reset();
	}
	//=============== player two collision =================== //
	if (this->_player == 2)
	{
		if (_snakeBody2.size() < 4)
			return; 
		Block &head2 = _snakeBody2.front();
		for(auto itr = _snakeBody2.begin() + 1; itr != _snakeBody2.end(); ++itr)
		{
			if(itr->x == head2.x && itr->y == head2.y)
			{
				this->_lives2 -= 1;
				if (this->_lives2 <= 0)
				{
					this->_lives2 = this->_resetLives;
					this->_score = 0;
				}
				this->reset();
				break;
			}	
		}
		if (head2.x <= 0 || head2.y <= 0 || head2.x >= _width - 1 || head2.y >= _height - 1)
		{
			this->_lives2 -= 1;
			if (this->_lives2 <= 0)
			{
				this->_lives2 = this->_resetLives;
				this->_score = 0;
			}
			this->reset();
		}

	}
}

Direction			Snake::getDirection( void ) const
{
	return _direction;
}

// Only set direction unless it's trying to go
// in the opposite direction that it's currently moving
void				Snake::setDirection( Direction dir )
{
	if (player1Start == false && dir != Direction::NONE)
		player1Start = true;
	if (_direction != Direction::LEFT && dir == Direction::RIGHT)
		_direction = dir;
	else if (_direction != Direction::RIGHT && dir == Direction::LEFT)
		_direction = dir;
	else if (_direction != Direction::UP && dir == Direction::DOWN)
		_direction = dir;
	else if (_direction != Direction::DOWN && dir == Direction::UP)
		_direction = dir;
	else if (dir == Direction::NONE)
		_direction = dir;
}

// player two direction
void				Snake::setDirection2( Direction dir )
{
	if (player2Start == false && dir != Direction::NONE)
		player2Start = true;
	if (_direction2 != Direction::LEFT && dir == Direction::RIGHT)
		_direction2 = dir;
	else if (_direction2 != Direction::RIGHT && dir == Direction::LEFT)
		_direction2 = dir;
	else if (_direction2 != Direction::UP && dir == Direction::DOWN)
		_direction2 = dir;
	else if (_direction2 != Direction::DOWN && dir == Direction::UP)
		_direction2 = dir;
	else if (dir == Direction::NONE)
		_direction2 = dir;
}

void				Snake::onlineReset(void)
{
	this->_speed = 100;
	_snakeBody.clear();
	_snakeBody.push_back(Block(5,7));
	_snakeBody.push_back(Block(5,6));
	_snakeBody.push_back(Block(5,5));
	_snakeBody.push_back(Block(5,4));
	setDirection(Direction::NONE); // Start off still.
	_snakeBody2.clear();
	_snakeBody2.push_back(Block(10,7));
	_snakeBody2.push_back(Block(10,6));
	_snakeBody2.push_back(Block(10,5));
	_snakeBody2.push_back(Block(10,4));
	setDirection(Direction::NONE); // Start off still.
}

void				Snake::reset( void )
{
	this->_speed = 100;
	_snakeBody.clear();
	_snakeBody.push_back(Block(5,7));
	_snakeBody.push_back(Block(5,6));
	_snakeBody.push_back(Block(5,5));
	_snakeBody.push_back(Block(5,4));
	setDirection(Direction::NONE); // Start off still.
	if (this->_player == 2)
	{
		_snakeBody2.clear();
		_snakeBody2.push_back(Block(10,7));
		_snakeBody2.push_back(Block(10,6));
		_snakeBody2.push_back(Block(10,5));
		_snakeBody2.push_back(Block(10,4));
		setDirection(Direction::NONE); // Start off still.
	}
}

void				Snake::setLives(int lives)
{
	this->_lives = lives;	
	this->_resetLives = lives;
	if (this->_player == 2)
		this->_lives2 = lives;
}

int					Snake::getLives(void)
{
	return (this->_lives);
}

int					Snake::getScore(void)
{
	return (this->_score);
}

void				Snake::setDifficulty(int level)
{
	this->_difficulty = level;
}

void				Snake::setMultiplayer( void )
{
	this->_player = 2;
}

Snake & 			Snake::operator=(const Snake & src)
{
	if (this != &src)
	{
		*this = src;
	}
	return *this;
}
