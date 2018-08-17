/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 13:08:26 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 09:21:40 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"

// constructor
Display::Display(void)
{
}

// deconstructor
Display::~Display(void)
{
	this->_window.close();
}

void	Display::CloseWindow( void )
{
	this->_window.close();
}

// get the key inputs
Keys	Display::getKey(void)
{
	if (this->_event.type == sf::Event::KeyPressed)
	{
		int	keyCode = this->_event.key.code;
		
		if (keyCode == sf::Keyboard::Up)
		{
			std::cout << "Up\n";
			return Keys::UPA;
		}
		else if (keyCode == sf::Keyboard::Down)
		{
			std::cout << "Down\n";
			return Keys::DOWNA;
		}
		else if (keyCode == sf::Keyboard::Left)
		{
			std::cout << "Left\n";				
			return Keys::LEFTA;
		}
		else if (keyCode == sf::Keyboard::Right)
		{
			std::cout << "Right\n";				
			return Keys::RIGHTA;
		}
		else if (keyCode == sf::Keyboard::Escape)
		{
			std::cout << "Escape\n";				
			return Keys::ESC;
		}
		else if (keyCode == sf::Keyboard::F1)
		{
			std::cout << "F1\n";				
			return Keys::F1;
		}
		else if (keyCode == sf::Keyboard::F2)
		{
			std::cout << "F2\n";				
			return Keys::F2;
		}
		else if (keyCode == sf::Keyboard::F3)
		{
			std::cout << "F3\n";				
			return Keys::F3;
		}
		else
			return Keys::UNKNOWN;
	}
	return Keys::UNKNOWN;
}

// get the events
bool	Display::PollEvents( void )
{
	if (this->_window.pollEvent(this->_event))
	{
		if (this->_event.type == sf::Event::Closed)
		{
			Debug::print("closed window", true);
			return false;
		}
	}
	return true;
}

// render the background & border
void	Display::BackGround( void )
{
	// =========== Background ============= //
	sf::Texture		texture;
	if (!texture.loadFromFile("sprites/background.jpg"))
		Debug::print("failed to load background texture in sfml", true);
	texture.setRepeated(true);
	sf::Sprite	background(texture);
	background.setTextureRect(sf::IntRect(0, 0, this->_window.getSize().x, this->_window.getSize().y));
	this->_window.draw(background);
	// =========== Border ============= //
	for (int i = 0; i < 4; ++i)
	{
		this->_bounds[i].setFillColor(sf::Color(216, 216, 216));
		if (!((i + 1) % 2))
			this->_bounds[i].setSize(sf::Vector2f(this->_window.getSize().x, this->_blockSize));
		else
			this->_bounds[i].setSize(sf::Vector2f(this->_blockSize,this->_window.getSize().y));
		if (i < 2)
			this->_bounds[i].setPosition(0, 0);
		else
		{
			this->_bounds[i].setOrigin(this->_bounds[i].getSize());
			this->_bounds[i].setPosition(sf::Vector2f(this->_window.getSize()));
		}
		this->_window.draw(this->_bounds[i]);
	}

}

// render background/apple/snake/border
void	Display::Render(int foodX, int foodY, std::vector<Block> snake)
{
	this->_window.clear(sf::Color(163, 159, 151));
	// === Background === //
	BackGround();
	// ===== APPLE ===== //
	sf::Texture		texture;
	if (!texture.loadFromFile("sprites/apple.png"))
	{
		Debug::print("failed to load apple texture in sfml", true);
		_apple.setFillColor(sf::Color::Red);
	}
	texture.setRepeated(true);
	_apple.setRadius(this->_blockSize / 2);
	_apple.setPosition(foodX * this->_blockSize, foodY * this->_blockSize);
	_apple.setTexture(&texture);
	this->_window.draw(_apple);

	// ====== SNAKE ========= //
	sf::RectangleShape 	Body;
	sf::Texture			headtex;
	sf::Texture			bodytex;
	Body.setSize(sf::Vector2f(this->_blockSize, this->_blockSize));
	if (!headtex.loadFromFile("sprites/head.png") || !bodytex.loadFromFile("sprites/body.png"))
	{
		Debug::print("failed to load apple texture in sfml", true);
		Body.setFillColor(sf::Color::Red);
	}
	if (snake.size() == 0)
		Debug::print("Vector is empty please check if snake has been initialized properly", true);
	auto head = snake.begin();
	Body.setTexture(&headtex);
	Body.setPosition(head->x * this->_blockSize, head->y * this->_blockSize);
	this->_window.draw(Body);
	for (auto section = snake.begin() + 1; section != snake.end(); ++section)
	{
		Body.setTexture(&bodytex);
		Body.setPosition(section->x * this->_blockSize, section->y * this->_blockSize);
		this->_window.draw(Body);
	}
	this->_window.display();
}

// initilize screen size
void	Display::Init(int width, int height)
{
	this->_width = width;
	this->_height = height;
	this->_window.create(sf::VideoMode(_width, _height, 32), "Snake", sf::Style::Close);
}

// return instance of display object.
Interface * CreateDisplay( void )
{
	return new Display;
}
// delete new instance of it
void	DeleteDisplay(Display * display)
{
	delete display;
}
