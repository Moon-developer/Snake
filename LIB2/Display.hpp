/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:06:09 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/21 13:54:43 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include "../srcs/Interface.hpp"
# include "../srcs/Error.hpp"
# include "../srcs/debug.hpp"
# include <vector>
# include <SDL.h>

class Display : public Interface
{
	public:
		Display( void );
		Display ( const Display & src);
		virtual ~Display( void );

		virtual void	Init(int width, int height);
		virtual Keys	getKey( void );
		virtual Keys	getKey2( void );
		virtual void	Render( int foodX, int foodY, int type, std::vector<Block> snake, std::vector<Block> snake2, int set);
		virtual bool	PollEvents( void );

		Display & operator=( const Display & rhs);

		virtual void						CreateServer( void );
		virtual void						ConnectClient( void );
		virtual Keys						sendOnlineKey( void );
		virtual Keys						getOnlineKey( void );
		virtual std::string					getFood( void );
		virtual void						sendFood(int x, int y);
		virtual void						setOnline(int port, std::string ip);
	private:
		int					_width;
		int					_height;
		int					_rows;
		int					_cols;
		int					_te;
		int					_le;
		SDL_Event			_event;
		SDL_Window			*_window;
		SDL_Renderer		*_render;
		SDL_Texture			*_sprites;
		void				secondSnake(std::vector<Block> snake);
};

extern "C" Interface *	CreateDisplay(void);
extern "C" void			DeleteDisplay(Display * display);

#endif
