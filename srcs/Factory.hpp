/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factor.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:55:56 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 15:00:29 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_HPP
# define FACTORY_HPP

# include <iostream>
# include "Interface.hpp"
# include <dlfcn.h>

class Factory
{
	public:
		Factory(void);
		~Factory(void);

		Interface	*createLibrary(int libNum, int width, int height);
		void	deleteLibrary(Interface* & dlGraphics);
		

	private:
		Interface	*_dlGraphics;
		void		*_dl_handle;
		Interface*	(*_fn_pointer)(void);

		int			_currentLib;
		int			_first = 0;
		std::string	_library;
};

#endif
