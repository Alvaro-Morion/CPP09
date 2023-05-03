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

SRCS		=	main.cpp BitcoinExchange.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	btc

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

%.o: %.cpp
				$(CC) $(CFLAGS) $< -c -o ${<:.cpp=.o}

all:			${NAME}

${NAME}:		${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			
clean:
				rm -f ${OBJS} 

fclean:			clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
