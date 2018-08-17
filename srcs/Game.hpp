/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:49:38 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 09:14:19 by mafernan         ###   ########.fr       */
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

class Game {
	public:
		Game();
		Game(Game const & src);
		~Game();
		Game & operator=(Game const & src);

		int				windowSettings( void );
		std::string		startLibrary( void );
		bool	validLibrary(std::string input);
		int		getHeight( void );
		int		getWidth( void );
		bool	isDigits(const std::string & str);
		void	runNibbler( void );
		Food	food;
		Snake	snake;
		Factory	factory;

	private:
		int		_score;
		int		_width;
		int		_height;
};

#endif
