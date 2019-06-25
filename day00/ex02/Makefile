NAME = account.exe
SRC = Account.class.cpp \
		tests.cpp
OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
HEADERS = Account.class.hpp
FLAGS = -Werror -Wall -Wextra
all: $(NAME)
$(NAME): $(OBJ_DIR) $(OBJ) $(HEADERS)
	clang++ -o $(NAME) $(OBJ)
$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	clang++ $(FLAGS) -c $< -o $@
$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
clean:
	@rm -rf $(OBJ_DIR)
fclean: clean
	@rm -f $(NAME)
re: fclean all