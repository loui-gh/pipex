# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 22:18:38 by mokatova          #+#    #+#              #
#    Updated: 2022/04/22 20:17:42 by Loui :)          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = main.c helpers1.c helpers2.c parse_cmds.c fd_pipe_fork.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ 

all: $(NAME)
clean: 
	$(RM) $(OBJ) $(OBJB)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus