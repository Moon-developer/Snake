/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:54:27 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 15:23:23 by mafernan         ###   ########.fr       */
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
Interface	*Factory::createLibrary(int libNum, int width, int height)
{

	if (libNum == this->_currentLib && this->_first == 1)
		return (this->_dlGraphics);
	else if (libNum != this->_currentLib && this->_first == 1)
		deleteLibrary(this->_dlGraphics);
	this->_currentLib = libNum;
	if (libNum == 5)
	{
		this->_first = 1;
		this->_library = "bin/sfml.so";
		this->_currentLib = libNum;
	}
	else if (libNum == 6)
	{
		this->_first = 1;
		this->_library = "bin/sdl.so";
		this->_currentLib = libNum;
	}
	else if (libNum == 7)
	{
		this->_first = 1;
		this->_library = "bin/glfw.so";
		this->_currentLib = libNum;
	}
	this->_dl_handle = dlopen( this->_library.c_str(), RTLD_LAZY | RTLD_LOCAL );
	if ( !this->_dl_handle )
		dlerrorWrapper();
	this->_fn_pointer = (Interface*(*)(void)) dlsym(this->_dl_handle, "CreateDisplay");
	if (!this->_fn_pointer)
		dlerrorWrapper();
	this->_dlGraphics = this->_fn_pointer();
	this->_dlGraphics->Init(width, height);
	return (this->_dlGraphics);
}

void	Factory::deleteLibrary(Interface* & dlGraphics)
{
	void	(*destory)(Interface *);

	if ( !this->_dl_handle )
		dlerrorWrapper();
	destory = (void(*)(Interface *)) dlsym(this->_dl_handle, "DeleteDisplay");
	if (!destory)
		dlerrorWrapper();
	destory(dlGraphics);
	dlclose(this->_dl_handle);
	this->_dl_handle = NULL;
	this->_dlGraphics = NULL;
}
