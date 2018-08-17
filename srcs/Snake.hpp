/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:54:54 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/16 15:34:49 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include "debug.hpp" 
#include "Food.hpp"
#include <time.h>

enum Direction
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Snake
{
	public:

		Snake( void );
		Snake( const Snake & src );
		~Snake( void );

		std::vector<Block>	getSnake( void ) const;
		void				move( void );
		void				extendSnake( void ); 
		void				checkCollision( void );
		Direction			getDirection( void ) const;
		void				setDirection( Direction dir );
		bool				Tick( Food & apple );
		void				reset( void );
		void				GetWindow(int width, int height);

		Snake & operator=(const Snake & src);

	private:

		std::vector<Block>	_snakeBody;
		Direction			_direction;
		float				_speed;
		int					_width;
		int					_height;
};

#endif
