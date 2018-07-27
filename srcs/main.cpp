/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:34:22 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/26 17:00:57 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <dlfcn.h>

void	dlerror_wrapper()
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

int	main(void )
{
	void		*dl_handle;
	void		(*fn_pointer)(void);

	dl_handle = dlopen("./bin/sfml.so", RTLD_LAZY | RTLD_LOCAL);
	if (!dl_handle)
		dlerror_wrapper();
	fn_pointer = (void(*)(void)) dlsym(dl_handle, "test");
	if (!fn_pointer)
		dlerror_wrapper();

	fn_pointer();
	return (0);
}
