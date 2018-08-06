/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16/49/38 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/06 17:29:46 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GAME_HPP
# define	GAME_HPP

# include <iostream>
# include <dlfcn.h>
# include "Error.hpp"

class Game {
	public:
		Game();
		Game(Game const & src);
		~Game();
		Game & operator=(Game const & src);

		std::string		windowSettings( void );
		std::string		startLibrary( void );
		bool	validLibrary(std::string input);
		int		getHeight( void );
		int		getWidth( void );
		bool	isDigits(const std::string & str);
		void	runNibbler( void );

	private:
		int		_width;
		int		_height;
};

#endif
