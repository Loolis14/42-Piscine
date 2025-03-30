# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeurer <mmeurer@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 11:13:50 by mmeurer           #+#    #+#              #
#    Updated: 2025/02/23 20:32:13 by mmeurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := rush-02

CC := cc
CFLAGS := -Wall -Wextra -Werror
SRC := main.c fonctions_recursives.c dictionnaire.c
OBJ := $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

norm:
	norminette $(SRC)

.PHONY: all clean fclean norm re
