# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/30 09:02:14 by mafernan          #+#    #+#              #
#    Updated: 2018/08/03 13:23:14 by mafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = sdl.so

SRC_DLL = interface.cpp

HEADER = -I SDL2.framework/Headers

CMP_DLL = clang++ -shared -fPIC SDL2.framework/SDL2

all:
	@$(CMP_DLL) $(SRC_DLL) -o $(NAME) $(HEADER) -Wl,-rpath,$(PWD)/.
	@mv $(NAME) ../bin/.
	@echo "Created /bin/sdl.so"
