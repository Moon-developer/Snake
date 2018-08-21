/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:49:37 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 18:05:51 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_CPP
# define DEBUG_CPP

# include <iostream>

struct Block
{
	int x;
	int y;
	Block( int xPos, int yPos ): x(xPos), y(yPos) {}
};

class Debug {
	public:
		Debug( void );
		~Debug( void );

		static void	print(std::string string, bool flag) {
			std::string	RED = "\033[1;31m";
			std::string	RESET = "\033[0m";
			if (flag == true)
				std::cout << RED << string << RESET << std::endl;
		};
};

#endif
