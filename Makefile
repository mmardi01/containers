# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 16:51:26 by mmardi            #+#    #+#              #
#    Updated: 2023/03/01 15:34:00 by mmardi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =   containers

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

HEADER =  src/vector.hpp iterators/vectorIterator.hpp src/set.hpp\
		iterators/reverse_iterator.hpp iterators/iterator_traits.hpp \
		src/stack.hpp utility/equal.hpp utility/enable_if.hpp src/map.hpp\
		utility/is_integral.hpp utility/pair.hpp src/redBlackTree.hpp \

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