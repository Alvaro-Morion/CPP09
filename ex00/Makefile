# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 11:46:02 by amorion-          #+#    #+#              #
#    Updated: 2023/04/13 11:46:04 by amorion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp BitcoinExchange.cpp

OBJS = $(SRCS:.cpp=.o)

CC = clang++

FLAGS = -std=c++98 -Wall -Werror -Wextra -g

NAME = btc

all: $(NAME)

.cpp.o:
	@$(CC) $(FLAGS) -c $< -o ${<:.cpp=.o}

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "Binary generated"

clean: 
	@rm -rf $(OBJS)
	@echo "Object files deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "Binary file deleted"

re: fclean all

.PHONY: re fclean clean all