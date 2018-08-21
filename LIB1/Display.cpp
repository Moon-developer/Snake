/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 13:08:26 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/21 15:31:00 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"

// constructor
Display::Display(void)
{
	if (!this->_buffer.loadFromFile("sprites/eat.wav"))
		throw Error::Texture("buffer.loadFromFile did not find move.wav");
	if (!headtex.loadFromFile("sprites/head.png") || !bodytex.loadFromFile("sprites/body.png"))
		Body.setFillColor(sf::Color::Red);
	// set blocking to fast from the start
	this->_socket.setBlocking(false);
}

// deconstructor
Display::~Display(void)
{
	this->_window.close();
}

void	Display::setOnline(int port, std::string ip)
{
	(void)ip;
	(void)port;
	//this->_ip = ip;
	//this->_port = port;
}

// create a server
void	Display::CreateServer( void )
{
	// listen to port 2000
	this->_listener.listen(this->_port);
	this->_listener.accept(this->_socket);
}

// connect as client
void	Display::ConnectClient( void )
{
	this->_socket.connect(this->_ip.c_str(), this->_port);
}

// get keys from online player to return to the user
Keys	Display::getOnlineKey( void )
{
	sf::Packet		packetRecieve;
	int				KeyCode;

	this->_socket.receive(packetRecieve);
	packetRecieve >> KeyCode;
	if (KeyCode != Keys::UNKNOWN)
	{
		switch (KeyCode) {
			case Keys::KEYW:
				return Keys::KEYW;
			case Keys::KEYA:
				return Keys::KEYA;
			case Keys::KEYS:
				return Keys::KEYS;
			case Keys::KEYD:
				return Keys::KEYD;
			case sf::Keyboard::Escape:
				return Keys::ESC;
		}
	}
	return Keys::UNKNOWN;
}
// Send player they keys and return keys to user

Keys	Display::sendOnlineKey( void )
{
	sf::Packet		packetSend;

	if (this->_event.type == sf::Event::KeyPressed)
	{
		int KeyCode = this->_event.key.code;
		switch (KeyCode) {
			case sf::Keyboard::W:
				packetSend << Keys::KEYW;
				this->_socket.send(packetSend);
				return Keys::KEYW;
			case sf::Keyboard::A:
				packetSend << Keys::KEYA;
				this->_socket.send(packetSend);
				return Keys::KEYA;
			case sf::Keyboard::S:
				packetSend << Keys::KEYS;
				this->_socket.send(packetSend);
				return Keys::KEYS;
			case sf::Keyboard::D:
				packetSend << Keys::KEYD;
				this->_socket.send(packetSend);
				return Keys::KEYD;
			case sf::Keyboard::Escape:
				packetSend << Keys::KEYD;
				this->_socket.send(packetSend);
				return Keys::ESC;
			packetSend << Keys::UNKNOWN;
			this->_socket.send(packetSend);
			return Keys::UNKNOWN;
		}
	}
	packetSend << Keys::UNKNOWN;
	this->_socket.send(packetSend);
	return Keys::UNKNOWN;
}

// get food position
std::string		Display::getFood( void )
{
	sf::Packet		packetRecieve;
	int				x;
	int				y;
	std::string 	result;

	this->_socket.receive(packetRecieve);
	packetRecieve >> x >> y;
	result = std::to_string(x) + ":" + std::to_string(y);
	return (result);
}

// send food position
void	Display::sendFood(int x, int y)
{
	sf::Packet		packetSend;
	packetSend << x << y;
	this->_socket.send(packetSend);
}

// player two controls
Keys	Display::getKey2(void)
{
	if (this->_event.type == sf::Event::KeyPressed) 
	{
		int	keyCode = this->_event.key.code;
		switch (keyCode) {
			case sf::Keyboard::W:
				return Keys::KEYW;
				break;
			case sf::Keyboard::A:
				return Keys::KEYA;
				break;
			case sf::Keyboard::S:
				return Keys::KEYS;
				break;
			case sf::Keyboard::D:
				return Keys::KEYD;
				break;
			return Keys::UNKNOWN;
		}
	}
	return Keys::UNKNOWN;
}

// get the key inputs
Keys	Display::getKey(void)
{
	if (this->_event.type == sf::Event::KeyPressed) 
	{
		int	keyCode = this->_event.key.code;
		switch (keyCode) {
			case sf::Keyboard::Up:
				return Keys::UPA;
				break;
			case sf::Keyboard::Down:
				return Keys::DOWNA;
				break;
			case sf::Keyboard::Left:
				return Keys::LEFTA;
				break;
			case sf::Keyboard::Right:
				return Keys::RIGHTA;
				break;
			case sf::Keyboard::Escape:
				return Keys::ESC;
				break;
			case sf::Keyboard::F1:
				return Keys::F1;
				break;
			case sf::Keyboard::F2:
				return Keys::F2;
				break;
			case sf::Keyboard::F3:
				return Keys::F3;
				break;
			return Keys::UNKNOWN;
		}
	}
	return Keys::UNKNOWN;
}

// get the events
bool	Display::PollEvents( void )
{
	if (this->_window.pollEvent(this->_event))
		if (this->_event.type == sf::Event::Closed)
			return false;
	return true;
}

// render the background & border
void	Display::BackGround( void )
{
	// =========== Background ============= //
	sf::Texture		texture;
	if (!texture.loadFromFile("sprites/background.jpg"))
		std::cout << "temp" << std::endl;
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

// player two snake
void	Display::secondSnake(std::vector<Block> snake)
{
	Body.setSize(sf::Vector2f(this->_blockSize, this->_blockSize));
	if (snake.size() == 0)
		std::cout << "temp" << std::endl;
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
}

// render background/apple/snake/border
void	Display::Render(int foodX, int foodY, int type, std::vector<Block> snake, std::vector<Block> snake2, int set)
{
	this->_window.clear(sf::Color(163, 159, 151));
	// === Background === //
	BackGround();
	// ===== APPLE ===== //
	sf::Texture		texture;
	if (type == 1)
	{
		if (!texture.loadFromFile("sprites/apple.png"))
			_apple.setFillColor(sf::Color::Red);
	}
	else if (type == 2)
	{
		if (!texture.loadFromFile("sprites/tomato.png"))
			_apple.setFillColor(sf::Color::Red);
	}
	texture.setRepeated(true);
	_apple.setRadius(this->_blockSize / 2);
	_apple.setPosition(foodX * this->_blockSize, foodY * this->_blockSize);
	_apple.setTexture(&texture);
	this->_window.draw(_apple);
	// ====== SNAKE ========= //
	Body.setSize(sf::Vector2f(this->_blockSize, this->_blockSize));
	if (snake.size() == 0)
		std::cout << "temp" << std::endl;
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
	if (set == 2)
		secondSnake(snake2);
	// ========= sounds ============= //
	if (snake.begin()->x == foodX && snake.begin()->y == foodY)
	{
		this->_sound.setBuffer(this->_buffer);
		this->_sound.setLoop(false);
		this->_sound.play();
	}
	// ============================== //
	this->_window.display();
}

// initilize screen size
void	Display::Init(int width, int height)
{
	this->_width = width;
	this->_height = height;
	this->_window.create(sf::VideoMode(_width, _height, 32), "Snake SFML", sf::Style::Close);
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
