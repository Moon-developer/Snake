/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:58:03 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/21 13:07:27 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Food.hpp"

Food::Food(void) {}

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

Food::~Food(void) {}

int		Food::getXPos(void) const
{
	return _xPos;
}

int		Food::getYPos(void) const
{
	return _yPos;
}

void	Food::setOnlinePos(std::string res)
{
	std::string::size_type pos = res.find(':');
    if(res.npos != pos) 
	{
        _xPos = std::stoi(res.substr(pos + 1));
        _yPos = std::stoi(res.substr(0, pos));
    }
}

void	Food::spawnFood(void)
{
	//width and height passed in from game class
	int	maxX = (this->_width / blockSize) - 2;
	int	maxY = (this->_height/ blockSize) - 2;

	_xPos = (std::rand() % maxX + 1);
	_yPos = (std::rand() % maxY + 1);
	// random food type. if less than 5 its a type 1 else a type 2
	if (std::rand() % 10 < 5)
		this->_type = 1;
	else
		this->_type = 2;
}

int		Food::getType(void)
{
	return (this->_type);
}

Food 	&Food::operator=( const Food & rhs )
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}
