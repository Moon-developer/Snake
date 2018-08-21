/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:06:09 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/21 14:38:13 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include "../srcs/Interface.hpp"
# include "../srcs/Error.hpp"
# include <vector>
# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <SFML/Network.hpp>

class Display : public Interface
{
	public:
		Display( void );
		Display (const Display & src);
		virtual ~Display( void );

		virtual void			setOnline(int port, std::string ip);
		virtual void			CreateServer( void );
		virtual void			ConnectClient( void );
		virtual Keys			getOnlineKey( void );
		virtual Keys			sendOnlineKey( void );
		virtual std::string		getFood( void );
		virtual void			sendFood(int x, int y);
		virtual Keys			getKey2( void );
		virtual Keys			getKey( void );
		virtual bool			PollEvents( void );
		virtual void			Render( int foodX, int foodY, int type,
										std::vector<Block> snake,
										std::vector<Block> snake2, int set);
		virtual void			Init(int width, int height);

		Display & operator=( const Display & rhs);

	private:
		sf::TcpListener 	_listener;
		sf::TcpSocket		_socket;
		sf::SoundBuffer		_buffer;
		sf::Sound			_sound;
		sf::Event			_event;
		sf::RenderWindow	_window;
		sf::CircleShape		_apple;
		sf::RectangleShape	_bounds[4];
		sf::RectangleShape 	Body;
		sf::Texture			headtex;
		sf::Texture			bodytex;
		virtual void		BackGround( void );
		void				secondSnake(std::vector<Block> snake);
		int					_width;
		int					_height;
		int					_blockSize = 16;
		const std::string	_ip = "10.204.0.19";
		const unsigned short _port = 2000;
};

extern "C" Interface *	CreateDisplay(void);
extern "C" void			DeleteDisplay(Display * display);

#endif
