/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:54:27 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 09:18:32 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"

Factory::Factory()
{
}

Factory::~Factory()
{
}

// throw error if dlhandle isn't working
void	dlerrorWrapper()
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit( EXIT_FAILURE );
}

// This will create and return the correct dynamic library
// need to add a check to see if it's the same library or not
Interface	*Factory::createLibrary(int libNum)
{
	void			*dl_handle;
	Interface*		(*fn_pointer)( void );
	std::string		library;

	if (this->_first == 0)
	{
		if (libNum == 5)
		{
			library = "bin/sfml.so";
			this->_currentLib = libNum;
		}
		else if (libNum == 6)
		{
			library = "bin/sdl.so";
			this->_currentLib = libNum;
		}
		else if (libNum == 7)
		{
			library = "bin/glfw.so";
			this->_currentLib = libNum;
		}
		this->_first = 1;
	}
	else if (libNum == this->_currentLib)
		Debug::print("Already using that library", true);
	else if (libNum == 5)
	{
		library = "bin/sfml.so";
		this->_currentLib = libNum;
	}
	else if (libNum == 6)
	{
		library = "bin/sdl.so";
		this->_currentLib = libNum;
	}
	else if (libNum == 7)
	{
		library = "bin/glfw.so";
		this->_currentLib = libNum;
	}
	dl_handle = dlopen( library.c_str(), RTLD_LAZY | RTLD_LOCAL );
	if ( !dl_handle )
		dlerrorWrapper();
	fn_pointer = (Interface*(*)(void)) dlsym(dl_handle, "CreateDisplay");
	if (!fn_pointer)
		dlerrorWrapper();
	this->dlGraphics = fn_pointer();
	return (this->dlGraphics);
}

void	Factory::deleteLibrary(Interface* & dlGraphics)
{
	(void)dlGraphics;
	std::cout << "deleted" << std::endl;
	//delete this->dlGraphics;
}
