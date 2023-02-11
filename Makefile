# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 16:51:26 by mmardi            #+#    #+#              #
#    Updated: 2023/02/10 21:02:34 by mmardi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =   containers

# CFLAGS = -Wall -Wextra -Werror 

SRC = main.cpp

HEADER = vector.hpp vectorIterator.hpp \
		reverse_iterator.hpp iterator_traits.hpp \
		stack.hpp equal.hpp enable_if.hpp map.hpp\
		is_integral.hpp pair.hpp redBlackTree.hpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME) 

%.o: %.cpp  $(HEADER)
	c++ $(CFLAGS) -o $@  -c $<

$(NAME): $(OBJ)
	c++ $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all