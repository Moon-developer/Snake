/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:45:26 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/25 18:43:08 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>

class Food
{
	public:

		Food(void);
		Food(float startX, float startY);
		Food(const Food & src);
		~Food(void);

		sf::FloatRect		getPosition(void);
		sf::RectangleShape	getShape(void);
		void				update(void);

		Food operator=(Food & rhs);

	private:

		sf::Vector2f		_position;
		sf::RectangleShape	_foodShape;

};