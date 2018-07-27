# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 10:26:13 by mafernan          #+#    #+#              #
#    Updated: 2018/07/26 15:53:26 by mafernan         ###   ########.fr        #
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

all: SFML
	echo "done!"

SFML:
	@echo "Checking if SMFL is installed:"
	@if [ -d "./LIB1/SFML" ]; then echo "File sfml exists";else $(DWNLD) && $(UNTAR) && $(CR_MV);fi
	@cd ./LIB1 && $(MAKE) && cd ..
