#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okupin <okupin@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 16:07:42 by okupin            #+#    #+#              #
#    Updated: 2019/06/22 16:07:47 by okupin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME     := ft_retro

SRCS     := main.cpp Player.cpp Controller.cpp Vec2.cpp Enemy.cpp Bullet.cpp AGameObject.cpp Squad.cpp Star.cpp
OBJS     := $(SRCS:.cpp=.o)

CXX      := clang++
CXXFLAGS := -Wall -Werror -Wextra
NCURSES  := -lncurses

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) $(NCURSES) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

re:     fclean all

.PHONY: all clean fclean format re