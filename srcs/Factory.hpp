/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factor.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:55:56 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 09:08:25 by mafernan         ###   ########.fr       */
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

		Interface	*createLibrary(int libNum);
		void	deleteLibrary(Interface* & dlGraphics);
		
		Interface	*dlGraphics;

	private:
		int			_currentLib;
		int			_first = 0;
};

#endif
