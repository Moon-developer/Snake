/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:06:09 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 11:56:01 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include "../srcs/Interface.hpp"
# include "../srcs/debug.hpp"
# include <vector>
# include <glfw3.h>

typedef struct FPoints {
	float x0;
	float x1;
	float y0;
	float y1;
} Points;

class Display : public Interface
{
	public:
		Display( void );
		virtual ~Display( void );

		virtual void	Init(int width, int height);
		virtual Keys	getKey( void );
		virtual void	Render( int foodX, int foodY, std::vector<Block> snake);
		virtual bool	PollEvents( void );
		virtual void	CloseWindow( void );
		virtual void	BackGround( void );

	private:
		int					_width;
		int					_height;
		GLFWwindow			*_window;
		Points				getPoints(int x, int y);
};

extern "C" Interface *	CreateDisplay(void);
extern "C" void			DeleteDisplay(Display * display);

#endif
