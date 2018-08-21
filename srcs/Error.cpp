/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:05:17 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 17:14:52 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

// incorrect width size
Error::InvalidWidth::InvalidWidth(const std::string & line)
{
	if (std::stoi(line) < 400)
		e_msg = std::string("Invalid Width Error : " + line +" smaller than 400");
	else if (std::stoi(line) > 1920)
		e_msg = std::string("Invalid Width Error : " + line +" greater than 1920");
}

const char * Error::InvalidWidth::what() const throw () {
	return e_msg.c_str();
}

// incorrect height size
Error::InvalidHeight::InvalidHeight(const std::string & line)
{
	if (std::stoi(line) < 400)
		e_msg = std::string("Invalid Height Error : " + line +" smaller than 400");
	else if (std::stoi(line) > 1080)
		e_msg = std::string("Invalid Height Error : " + line +" greater than 1080");
}

const char * Error::InvalidHeight::what() const throw () {
	return e_msg.c_str();
}

// is not made of only digits
Error::NotDigit::NotDigit(const std::string & line)
{
	e_msg = std::string("Invalid Input Error : " + line +" is not made up of digits only");
}

const char * Error::NotDigit::what() const throw () {
	return e_msg.c_str();
}

// incorrect library input
Error::InvalidLibrary::InvalidLibrary(const std::string & line)
{
	e_msg = std::string("Invalid library option : " + line +" is not an implemented library");
}

const char * Error::InvalidLibrary::what() const throw () {
	return e_msg.c_str();
}

// no Library
Error::NoLibrary::NoLibrary(const std::string & line)
{
	e_msg = std::string(line + " : Usually means the dylib/so file is missing or not linking properly");
}

const char * Error::NoLibrary::what() const throw () {
	return e_msg.c_str();
}

// Function pointer not correct
Error::FunctionPointer::FunctionPointer(const std::string & line)
{
	e_msg = std::string(line + " : usually means it did not find the function given in the dlsym call");
}

const char * Error::FunctionPointer::what() const throw () {
	return e_msg.c_str();
}

// Texture loading error 
Error::Texture::Texture(const std::string & line)
{
	e_msg = std::string(line);
}

const char * Error::Texture::what() const throw () {
	return e_msg.c_str();
}

// Snake errorsr 
Error::Snake::Snake(const std::string & line)
{
	e_msg = std::string(line);
}

const char * Error::Snake::what() const throw () {
	return e_msg.c_str();
}

// SDL run time errors 
Error::RuntimeError::RuntimeError(const std::string & line)
{
	e_msg = std::string(line);
}

const char * Error::RuntimeError::what() const throw () {
	return e_msg.c_str();
}

