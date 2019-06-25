NAME = 80s_phonebook
CPP = clang++
FLG = -Wall -Wextra -Werror

SRC = main.cpp \
	  Contact.class.cpp

HDR = crappy_phonebook.h \
	  Contact.class.hpp

OBJ = $(SRC:.cpp=.o)

.NOTPARALLEL: all clean fclean re

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	$(CPP) $(FLG) -o $(NAME) $(OBJ)

%.o: %.cpp $(HDR)
	$(CPP) $(FLG) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
