/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:01:27 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 18:02:06 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

# include <exception>
# include <iostream>

class	Error {
	public:
		Error( void );
		~Error( void );
		class InvalidWidth : public std::exception {
			public:
				std::string		e_msg;
				InvalidWidth(const std::string & line);
				virtual const char * what() const throw();
		};
		class InvalidHeight : public std::exception {
			public:
				std::string		e_msg;
				InvalidHeight(const std::string & line);
				virtual const char * what() const throw();
		};
		class NotDigit : public std::exception {
			public:
				std::string		e_msg;
				NotDigit(const std::string & line);
				virtual const char * what() const throw();
		};
		class InvalidLibrary : public std::exception {
			public:
				std::string		e_msg;
				InvalidLibrary(const std::string & line);
				virtual const char * what() const throw();
		};
		class NoLibrary : public std::exception {
			public:
				std::string		e_msg;
				NoLibrary(const std::string & line);
				virtual const char * what() const throw();
		};
		class FunctionPointer : public std::exception {
			public:
				std::string		e_msg;
				FunctionPointer(const std::string & line);
				virtual const char * what() const throw();
		};
		class Texture : public std::exception {
			public:
				std::string		e_msg;
				Texture(const std::string & line);
				virtual const char * what() const throw();
		};
		class Snake : public std::exception {
			public:
				std::string		e_msg;
				Snake(const std::string & line);
				virtual const char * what() const throw();
		};
		class RuntimeError : public std::exception {
			public:
				std::string		e_msg;
				RuntimeError(const std::string & line);
				virtual const char * what() const throw();
		};
};

#endif
