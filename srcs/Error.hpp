/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:01:27 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/06 16:50:52 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

# include <exception>
# include <iostream>

class	Error {
	public:
		Error( void ) {};
		~Error( void ) {};
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
};

#endif
