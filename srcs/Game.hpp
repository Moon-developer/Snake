/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:49:38 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/21 13:41:03 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GAME_HPP
# define	GAME_HPP

# include <iostream>
# include "Interface.hpp"
# include "Factory.hpp"
# include "Error.hpp"
# include "Snake.hpp"
# include "Food.hpp"
# include "Display.hpp"

class Game {
	public:
		Game( void );
		Game( Game const & src );
		~Game( void );

		Game & operator=( Game const & src );

		void	runOnline(int port, std::string ip, int width, int height, int type);
		void	runNibbler( void );
		Food	food;
		Snake	snake;
		Factory	factory;
		int		moveCount = 0;

	private:
		int		_width;
		int		_height;
};

#endif
