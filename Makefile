##
## EPITECH PROJECT, 2024
## Game-of-life
## File description:
## Makefile
##

SRC:=$(shell find sources -name "*.cpp" | sort)
OBJ:=$(SRC:.cpp=.o)
CXXFLAGS:=-Wall -Wextra -Werror -pedantic -I./includes -I./libraries/includes -L./libraries/bin -lraylib -O3
NAME:=game_of_life

all: $(NAME)

%.o: %.cpp
	@($(CXX) -c -o $@ $< $(CXXFLAGS) && echo "Compiled "$<) || (echo "Failed to compile "$< && exit 1)

$(NAME): $(OBJ)
	@($(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) && echo "Compiled "$@) || (echo "Failed to compile "$@ && exit 1)

clean:
	@($(RM) $(OBJ) && echo "Cleaned objects") || (echo "Failed to clean objects" && exit 1)

fclean: clean
	@($(RM) $(NAME) && echo "Cleaned "$(NAME)) || (echo "Failed to clean "$(NAME) && exit 1)

re: fclean all

debug: CXXFLAGS += -g3
debug: re

.PHONY: all clean fclean re debug