# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 12:32:39 by ael-oual          #+#    #+#              #
#    Updated: 2022/07/22 16:45:55 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BS = main.c message.c philoo.c rotine.c tools.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
OBJB = $(BS:.c=.o)
all: $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o philo
clean: 
	rm -f $(OBJB)
fclean:clean
	rm $(NAME)
re: fclean all