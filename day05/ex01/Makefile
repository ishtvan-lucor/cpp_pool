NAME = BureaucratFillForm
CPP = clang++
FLG = -Wall -Wextra -Werror

SRC = main.cpp \
	  Bureaucrat.cpp \
	  Form.cpp

HDR = Bureaucrat.hpp Form.hpp

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
