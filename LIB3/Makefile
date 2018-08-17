# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 07:28:48 by mafernan          #+#    #+#              #
#    Updated: 2018/08/03 12:42:41 by mafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++ -w -Werror -Wall -Wextra

DYL_NAME = -o glfw.so

SRCS = interface.cpp

SHAREFLAGS = -shared -fPIC

INCLUDES_PATH = -I ~/.brew/include/GLFW

LIBRARY_PATH = -L ~/.brew/lib -lglfw3

FRAMEWORKS = -framework Cocoa -framework OpenGl -framework IOKit -framework CoreFoundation -framework CoreVideo

all:
	@$(CC) $(SRCS) $(SHAREFLAGS) $(DYL_NAME) $(INCLUDES_PATH) $(LIBRARY_PATH) $(FRAMEWORKS)
	@mv glfw.so ../bin/.
	@echo "Created /bin/glfw.so"
