# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 18:44:50 by pmartyny          #+#    #+#              #
#    Updated: 2019/07/07 19:44:05 by pmartyny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_gkrellm

LIBS 	= -lncurses

SRC		= main.cpp\
		IMonitorDisplay.cpp\
		IMonitorModule.cpp\
		TerminalDisplay.cpp\
		RAMModule.cpp\
		CPUModule.cpp\
		NetworkModule.cpp\
		HostUserNameModule.cpp\
		OsInfoModule.cpp\
		DateTimeModule.cpp\
		DiskModule.cpp

INC		= IMonitorDisplay.hpp\
		IMonitorModule.hpp\
		TerminalDisplay.hpp\
		RAMModule.hpp\
		CPUModule.hpp\
		NetworkModule.hpp\
		HostUserNameModule.hpp\
		OsInfoModule.hpp\
		DateTimeModule.hpp\
		DiskModule.hpp

OBJ		= $(SRC:.cpp=.o)

FLAG	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	mkdir -p system
	clang++ $(FLAG) $(LIBS) $^ -o $(NAME) 

./%.o: ./%.cpp
	clang++ $(FLAG) -c $< -o $@ 

clean:
	/bin/rm -f *.o
	/bin/rm -f ./system/*
	/bin/rm -rf ./system

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
