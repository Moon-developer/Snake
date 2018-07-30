# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/26 10:14:37 by mafernan          #+#    #+#              #
#    Updated: 2018/07/27 10:20:32 by mafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang++ -Werror -Wextra -Wall

OUT= -o sfml.so

RPATH= -Wl,-rpath,$(PWD)/SFML/Frameworks

SHAREFLAGS= -shared -fPIC

FRAMEWORKS= -framework sfml-graphics -framework sfml-window -framework sfml-system

FRAMEWORK_PATH= -F SFML/Frameworks

SRCS= interface.cpp

INCL= -I includes -I SFML/include -I SFML/lib

all:
	@echo "Compiling dylib for SFML"
	@$(CC) $(RPATH) $(SHAREFLAGS) $(FRAMEWORKS) $(FRAMEWORK_PATH) $(SRCS) $(OUT) $(INCL)
	@mv sfml.so ../bin/.
	@echo "SFML completed."
