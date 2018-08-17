/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:58:03 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/14 16:05:02 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Food.hpp"

Food::Food(void)
{
}

void	Food::init(int width, int height)
{
	this->_width = width;
	this->_height = height;
}

Food::Food(const Food & src)
{
	*this = src;
	return;
}

Food::~Food(void)
{

}

int		Food::getXPos(void) const
{
	return _xPos;
}

int		Food::getYPos(void) const
{
	return _yPos;
}

void	Food::spawnFood(void)
{
	//width and height passed in from game class
	int	maxX = (this->_width / blockSize) - 2;
	int	maxY = (this->_height/ blockSize) - 2;

	_xPos = (std::rand() % maxX + 1);
	_yPos = (std::rand() % maxY + 1);
}

Food 	&Food::operator=( const Food & rhs )
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}
