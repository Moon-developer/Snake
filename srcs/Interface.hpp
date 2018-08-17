/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:40:11 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/16 11:17:13 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_HPP
#define INTERFACE_HPP

# include <vector>
# include "debug.hpp" 

enum Keys {
	UPA,
	DOWNA,
	LEFTA,
	RIGHTA,
	ESC,
	F1,
	F2,
	F3,
	UNKNOWN
};

class Interface
{
	public:
		virtual void Init(int width, int height) = 0;
		virtual Keys getKey( void ) = 0;
		virtual void Render(int foodX, int foodY, std::vector<Block> snake) = 0;
		virtual bool PollEvents( void ) = 0;
		virtual void CloseWindow( void ) = 0;
		virtual void BackGround( void ) = 0;
};

#endif

