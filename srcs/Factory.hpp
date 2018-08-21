/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:55:56 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 18:05:58 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_HPP
# define FACTORY_HPP

# include <iostream>
# include <string>
# include "Interface.hpp"
# include "../srcs/Error.hpp"
# include <dlfcn.h>

class Factory
{
	public:
		Factory( void );
		Factory(const Factory & src);
		~Factory(void);

		Interface	*createLibrary( int libNum, int width, int height );
		void	deleteLibrary( Interface* & dlGraphics );

		Factory & operator=( const Factory & src );

	private:
		Interface	*_dlGraphics;
		void		*_dl_handle;
		Interface*	(*_fn_pointer)(void);

		int			_currentLib;
		int			_first = 0;
		std::string	_library;
};

#endif
