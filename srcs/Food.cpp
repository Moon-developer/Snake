/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:45:22 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/30 15:05:08 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Food.hpp"

Food::Food(void)
{

}

Food::Food(float startX, float startY)
{
	this->_position.x = startX;
	this->_position.y = startY;

	this->_foodShape.setSize(sf::Vector2f(10, 10));
	this->_foodShape.setPosition(this->_position);
}

Food::~Food(void)
{

}

sf::FloatRect		Food::getPosition(void)
{
	return this->_foodShape.getGlobalBounds();
}

sf::RectangleShape	Food::getShape(void)
{
	return this->_foodShape;
}

void		Food::update(void)
{
	return this->_foodShape.setPosition(this->_position);
}

// Food	Food::operator=(Food & rhs)
// {
// 	if (this != &rhs)
// 	{
// 		*this = rhs;
// 	}
// }
