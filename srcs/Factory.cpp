/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:54:27 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 16:46:44 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"

Factory::Factory() {}

Factory::~Factory() {}

// This will create and return the correct dynamic library
Interface	*Factory::createLibrary(int libNum, int width, int height)
{
	if (libNum == this->_currentLib && this->_first == 1)
		return (this->_dlGraphics);
	else if (libNum != this->_currentLib && this->_first == 1)
		deleteLibrary(this->_dlGraphics);
	this->_first = 1;
	if (libNum == 5)
		this->_library = "bin/sfml.so";
	else if (libNum == 6)
		this->_library = "bin/sdl.so";
	else if (libNum == 7)
		this->_library = "bin/glfw.so";
	this->_currentLib = libNum;
	this->_dl_handle = dlopen( this->_library.c_str(), RTLD_LAZY | RTLD_LOCAL );
	if ( !this->_dl_handle )
		throw Error::NoLibrary(std::string(dlerror()));
	this->_fn_pointer = (Interface*(*)(void)) dlsym(this->_dl_handle, "CreateDisplay");
	if (!this->_fn_pointer)
		throw Error::FunctionPointer(std::string(dlerror()));
	this->_dlGraphics = this->_fn_pointer();
	this->_dlGraphics->Init(width, height);
	return (this->_dlGraphics);
}

// delete the current library
void	Factory::deleteLibrary(Interface* & dlGraphics)
{
	void	(*destory)(Interface *);

	if ( !this->_dl_handle )
		throw Error::NoLibrary(std::string(dlerror()));
	destory = (void(*)(Interface *)) dlsym(this->_dl_handle, "DeleteDisplay");
	if (!destory)
		throw Error::FunctionPointer(std::string(dlerror()));
	destory(dlGraphics);
	dlclose(this->_dl_handle);
	this->_dl_handle = NULL;
	this->_dlGraphics = NULL;
}
