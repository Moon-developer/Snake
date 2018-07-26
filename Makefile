# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 10:26:13 by mafernan          #+#    #+#              #
#    Updated: 2018/07/25 15:31:28 by mafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME="nibbler"
CC= clang++ 
FLAGS=-std=c++11 -Werror -Wextra -Wall
TARGET= sfml.dylib
SHAREDL= -fPIC -shared 
INCL= -IGraphics_library/SFML-2.5.0-macOS-clang/include
LINK= -LGraphics_library/SFML-2.5.0-macOS-clang/lib
LINKL= -lsfml-graphics -lsfml-system -lsfml-window
FRAMEWORK_PATH= Graphics_library/SFML-2.5.0-macOS-clang/Frameworks
FRAMEWORKS= -framework sfml-graphics -framework sfml-window -framework sfml-system


SRCS=srcs/main.cpp


SFML='SFML-clang.tar.gz'
SFML_DIR='SFML-2.5.0-macOS-clang'
DWNLD=sh -c '$$(curl -Lo $(SFML) https://www.sfml-dev.org/files/SFML-2.5.0-macOS-clang.tar.gz)'
UNTAR=sh -c '$$(tar -xvzf $(SFML) && rm -rf $(SFML))'
CR_MV=sh -c '$$(mv $(SFML_DIR) ./Graphics_library/.)'

all: check_libraries
	@echo "SFML shared library:"
	$(CC) -o $(TARGET) $(FLAGS) $(INCL) $(SHAREDL) ./srcs/interface.cpp $(LINK) $(LINKL) -F$(FRAMEWORK_PATH) $(FRAMEWORKS)

check_libraries:
	@mkdir -p "./Graphics_library"
	@echo "Checking if SMFL is installed:"
	@if [ -d "./Graphics_library/SFML-2.5.0-macOS-clang" ]; then echo "File sfml exists";else $(DWNLD) && $(UNTAR) && $(CR_MV);fi
