# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/26 10:14:37 by mafernan          #+#    #+#              #
#    Updated: 2018/08/21 14:45:17 by mafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang++ -stdlib=libc++ -std=c++11

OUT= -o sfml.so

RPATH= -Wl,-rpath,$(PWD)/SFML/Frameworks

SHAREFLAGS= -shared -fPIC

FRAMEWORKS= -framework sfml-graphics -framework sfml-audio -framework sfml-network -framework sfml-window -framework sfml-system

FRAMEWORK_PATH= -F SFML/Frameworks

INCL= -I includes -I SFML/include -I SFML/lib

SRCS= Display.cpp ../srcs/Error.cpp 

all:
	@echo "Compiling dylib for SFML"
	@$(CC) $(SHAREFLAGS) $(RPATH) $(FRAMEWORKS) $(FRAMEWORK_PATH) $(SRCS) $(INCL) $(OUT)
	@mv sfml.so ../bin/.
	@echo "Created /bin/sfml.so"

