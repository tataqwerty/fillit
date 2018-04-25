# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 20:42:59 by tkiselev          #+#    #+#              #
#    Updated: 2018/04/09 10:58:44 by tkiselev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc -Wall -Wextra -Werror
NAME=fillit
LIBA=libft.a
DIR=fillit_dir/
SRCSFILES=fillit.c ft_solver.c algorithm.c
SRCSINDIR=$(addprefix $(DIR),$(SRCSFILES))

all: $(LIBA) $(NAME)

$(NAME): $(SRCS)
	$(CC) -c $(SRCSINDIR)
	$(CC) $(SRCSFILES:.c=.o) -o $(NAME) -L. ./libft/$(LIBA)

$(LIBA):
	make -C ./libft

clean:
	rm -f *.o ./libft/*.o

fclean: clean
	rm -f $(NAME) ./libft/$(LIBA)

re: fclean all
