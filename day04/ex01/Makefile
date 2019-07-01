NAME = Fallout
CPP = clang++
FLG = -Wall -Wextra -Werror

SRC = main.cpp \
	  Character.cpp \
	  Enemy.cpp \
	  AWeapon.cpp \
	  PlasmaRifle.cpp \
	  PowerFist.cpp \
	  RadScorpion.cpp \
	  SuperMutant.cpp

HDR = Enemy.hpp \
	  Character.hpp \
	  AWeapon.hpp \
	  PlasmaRifle.cpp \
	  PowerFist.hpp \
	  RadScorpion.hpp \
	  SuperMutant.hpp

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
