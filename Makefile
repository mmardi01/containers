# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 16:51:26 by mmardi            #+#    #+#              #
#    Updated: 2022/12/31 20:41:38 by mmardi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =   containers

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

HEADER = vector.hpp vectorIterator.hpp reverse_iterator.hpp iterator_traits.hpp

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