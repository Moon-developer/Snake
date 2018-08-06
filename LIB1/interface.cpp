/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:10:42 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/06 17:04:21 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "../srcs/main.hpp"
#include "../srcs/Snake.hpp"
#include "../srcs/Food.hpp"

extern "C" void	test(int width, int height)
{
	sf::RenderWindow	window(sf::VideoMode(width, height),"Nibbler: SFML");

	Snake	snake(width / 2, height - 20);
	Food	food(height / 2, 1);

	while (window.isOpen())
	{
		sf::Event	currentEvent;	
		while (window.pollEvent(currentEvent))
		{
			if (currentEvent.type == sf::Event::Closed)
			{
				window.close();
				break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			snake.moveUp();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			snake.moveDown();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			snake.moveLeft();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			snake.moveRight();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			window.close();

		snake.update();
		food.update();
		window.clear();

		window.draw(snake.getShape());
		window.draw(food.getShape());
		window.display();
		
	}
}
