# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/21 11:34:01 by jocuni-p          #+#    #+#              #
#    Updated: 2024/06/29 18:44:27 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror -MMD -I/. -pthread -fsanitize=address #-fsanitize=thread

SRC =  philo.c utils.c routine.c


OBJS = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
INCLUDE = philo.h

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJS) $(INCLUDE) Makefile
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)


%.o : %.c $(INCLUDE) Makefile
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME) $(DEPS)

re: fclean all

.PHONY: re all clean fclean
