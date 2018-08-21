# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/30 09:02:14 by mafernan          #+#    #+#              #
#    Updated: 2018/08/17 17:10:39 by mafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = sdl.so

SRC_DLL = Display.cpp ../srcs/Error.cpp

HEADER = -I SDL2.framework/Headers

CMP_DLL = clang++ -shared -fPIC SDL2.framework/SDL2 -std=c++11

all:
	@$(CMP_DLL) $(SRC_DLL) -o $(NAME) $(HEADER) -Wl,-rpath,$(PWD)/.
	@mv $(NAME) ../bin/.
	@echo "Created /bin/sdl.so"
