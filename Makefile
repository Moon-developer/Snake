# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 10:26:13 by mafernan          #+#    #+#              #
#    Updated: 2018/08/03 13:33:10 by mafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME="nibbler"
CC= clang++ 
FLAGS=-std=c++11 -Werror -Wextra -Wall
TARGET= sfml.so
SHAREDL= -fPIC -shared 
INCL= -IGraphics_library/SFML/include
LINK= -LGraphics_library/SFML/lib
LINKL= -lsfml-graphics -lsfml-system -lsfml-window
FRAMEWORK_PATH= Graphics_library/SFML/Frameworks
FRAMEWORKS= -framework sfml-graphics -framework sfml-window -framework sfml-system

SRCS=srcs/main.cpp

SFML='SFML-clang.tar.gz'
SFML_DIR='SFML-2.5.0-macOS-clang'
DWNLD=sh -c '$$(curl -Lo $(SFML) https://www.sfml-dev.org/files/SFML-2.5.0-macOS-clang.tar.gz)'
UNTAR=sh -c '$$(tar -xvzf $(SFML) && rm -rf $(SFML))'
CR_MV=sh -c '$$(mv $(SFML_DIR) ./LIB1/SFML && cp -rf ./LIB1/SFML/extlibs/* ./LIB1/SFML/Frameworks/.)'

SDL_DOWNLOAD=curl -Lo SDL2 http://www.libsdl.org/release/SDL2-2.0.8.dmg;hdiutil attach SDL2;cp -R /Volumes/SDL2/SDL2.framework LIB2/.;hdiutil detach /Volumes/SDL2;rm -rf SDL2

GLFW_DOWNLOAD=curl -Lo glfw-3.2.1.zip https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.zip
GLFW_SETUP=unzip -a glfw-3.2.1.zip && rm -rf glfw-3.2.1.zip && mv glfw-3.2.1 ./LIB3/glfw && cd ./LIB3/glfw && cmake . && make && make install

all: checks SFML SDL GLFW
	@clang++ -std=c++11 -Werror -Wextra -Wall srcs/main.cpp
	@echo "done!"

new: SFML SDL GLFW
	@clang++ -std=c++11 -Werror -Wextra -Wall srcs/main.cpp
	@echo "done!"

SFML:
	@if [ -d "./bin" ];then echo "Bin exists";else mkdir bin;fi
	@echo "Checking if SMFL is installed:"
	@if [ -d "./LIB1/SFML" ]; then echo "File sfml exists";else $(DWNLD) && $(UNTAR) && $(CR_MV);fi
	@cd ./LIB1 && $(MAKE)

SDL:
	@if [ -d "./bin" ];then echo "Bin exists";else mkdir bin;fi
	@echo "Checking if SDL is installed:"
	@if [ -d "./LIB2/SDL2.framework" ]; then echo "File SDL2 exists";else $(SDL_DOWNLOAD);fi
	@cd ./LIB2 && $(MAKE)

GLFW:
	@if [ -d "./bin" ];then echo "Bin exists";else mkdir bin;fi
	@echo "Checking if GLFW is installed:"
	@if [ -d "./LIB3/glfw" ]; then echo "Folder GLFW exists";else $(GLFW_DOWNLOAD) && $(GLFW_SETUP);fi
	@cd ./LIB3 && $(MAKE)

re: clean all

clean:
	@rm -rf a.out bin/*

fclean:
	@rm -rf LIB1/SFML LIB2/SDL2.framework LIB3/glfw a.out bin/*

checks:
	@read -p "Is brew installed? Type Y or n " ans ; if [ $$ans == "Y" ] ; then echo "continuing" ; else echo "Please close this terminal and install brew before running make again" && exec zsh; fi
	@read -p "Is cmake installed? Type Y or n " ans ; if [ $$ans == "Y" ] ; then echo "continuing" ; else echo "Please close this terminal and install cmake before running make again" && exec zsh; fi
