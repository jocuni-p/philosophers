# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/21 11:34:01 by jocuni-p          #+#    #+#              #
#    Updated: 2024/06/21 12:05:22 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -MMD -I/. -pthread

SRC =  philo.c utils.c routine.c
OBJS = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
NAME = philo

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)


%.o : %.c Makefile
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME) $(DEPS)

re: fclean all

.PHONY: re all clean fclean
