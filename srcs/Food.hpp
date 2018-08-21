/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:51:33 by ckatz             #+#    #+#             */
/*   Updated: 2018/08/21 12:49:26 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOOD_HPP
#define FOOD_HPP

# include <cstdlib>
# include <iostream>
# include <string>

class Food
{
	public:

		Food( void );
		Food( const Food & src );
		~Food( void );

		int		getXPos( void ) const;
		int		getYPos( void ) const;
		int		getType( void );
		void	spawnFood( void );
		void	init(int width, int height);
		void	setOnlinePos(std::string res);

		Food &	operator=( const Food & rhs ); 

	private:
		int		blockSize = 16;
		int		_width;
		int		_height;
		int		_xPos;
		int		_yPos;
		int		_type = 1;
};

#endif
