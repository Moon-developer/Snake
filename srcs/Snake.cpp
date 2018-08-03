/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:03:50 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/30 15:04:41 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

Snake::Snake(void)
{

}

Snake::Snake(float startX, float startY)
{
	this->_position.x = startX;
	this->_position.y = startY;

	this->_snakeShape.setSize(sf::Vector2f(10, 10));
	this->_snakeShape.setPosition(this->_position);
}

Snake::~Snake(void)
{

}

sf::FloatRect		Snake::getPosition(void) const
{
	return this->_snakeShape.getGlobalBounds();
}

sf::RectangleShape	Snake::getShape(void) const
{
	return this->_snakeShape;
}

void	Snake::moveUp(void)
{
	this->_position.y -= _snakeSpeed;
}

void	Snake::moveDown(void)
{
	this->_position.y += _snakeSpeed;
}

void	Snake::moveLeft(void)
{
	this->_position.x -= _snakeSpeed;
}

void	Snake::moveRight(void)
{
	this->_position.x += _snakeSpeed;
}

void	Snake::update(void)
{
	this->_snakeShape.setPosition(this->_position);
}

// Snake	Snake::operator=(Snake & rhs)
// {
// 	if (this != &rhs)
// 	{
// 		*this = rhs;
// 	}
// }
