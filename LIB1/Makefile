# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/26 10:14:37 by mafernan          #+#    #+#              #
#    Updated: 2018/08/03 14:11:32 by mafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang++ -std=c++11 -Werror -Wextra -Wall

OUT= -o sfml.so

RPATH= -Wl,-rpath,$(PWD)/SFML/Frameworks

SHAREFLAGS= -shared -fPIC

FRAMEWORKS= -framework sfml-graphics -framework sfml-window -framework sfml-system

FRAMEWORK_PATH= -F SFML/Frameworks

SRCS= interface.cpp ../srcs/Food.cpp ../srcs/Snake.cpp

INCL= -I includes -I SFML/include -I SFML/lib

all:
	@echo "Compiling dylib for SFML"
	@$(CC) $(RPATH) $(SHAREFLAGS) $(FRAMEWORKS) $(FRAMEWORK_PATH) $(SRCS) $(OUT) $(INCL)
	@mv sfml.so ../bin/.
	@echo "Created /bin/sfml.so"
