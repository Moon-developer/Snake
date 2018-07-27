# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/26 10:14:37 by mafernan          #+#    #+#              #
#    Updated: 2018/07/26 14:50:29 by mafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@echo "SFML shared library:"
	clang++ -Wl,-rpath,$(PWD)/SFML/Frameworks -shared -fPIC -framework sfml-graphics -framework sfml-window -framework sfml-system -F SFML/Frameworks interface.cpp -o sfml.so -I includes -I SFML/include -I SFML/lib
	mv sfml.so ../bin/.
