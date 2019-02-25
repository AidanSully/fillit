# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nvreeke <nvreeke@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/04 15:35:38 by asulliva       #+#    #+#                 #
#    Updated: 2019/02/14 12:47:37 by nvreeke       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ft_check.c ft_free_arr.c ft_map.c ft_read.c \
ft_solve.c ft_split.c ft_valid.c main.c

COMP = gcc
FLAGS = -Wall -Werror -Wextra
OBJ = *.o
LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@echo "Recompiling libft.a"
	@make -C libft/ fclean && make -C libft/
	@echo "compiling libft.a succesful!"
	@echo "Compiling binary..."
	@$(COMP) $(FLAGS) $(LIB) $(SRCS) -o $(NAME)
	@echo "Compiling succesful!"

clean:
	@echo "Removing object files..."
	@/bin/rm -f $(OBJ)
	@echo "Removing object files succesful!"
	@echo "Removing object files from libft..."
	@make -C libft/ clean
	@echo "Removing object files from libft succesful!"

fclean:
	@echo "Removing binary file..."
	@/bin/rm -f $(NAME)
	@echo "Removing binary file succesful!"
	@echo "Removing binary file from libft"
	@make -C libft/ fclean
	@echo "Removing binary file from libft succesful!"

re: fclean all