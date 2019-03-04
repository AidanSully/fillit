# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/04 15:35:38 by asulliva       #+#    #+#                 #
#    Updated: 2019/03/04 16:40:15 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = src/ft_check.c src/ft_free_arr.c src/ft_map.c src/ft_read.c \
src/ft_solve.c src/ft_split.c src/ft_valid.c src/main.c

COMP = gcc
FLAGS = -Wall -Werror -Wextra
OBJ = ft_check.o ft_free_arr.o ft_map.o ft_read.o \
ft_solve.o ft_split.o ft_valid.o main.o
LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@echo "Recompiling libft.a"
	@make -C libft/ fclean && make -C libft/
	@echo "compiling libft.a succesful!"
	@echo "Compiling binary..."
	@$(COMP) $(FLAGS) -c $(SRCS)
	@$(COMP) $(FLAGS) $(OBJ) -o $(NAME) -L libft/ -lft
	@echo "Compiling succesful!"

clean:
	@echo "Removing object files..."
	@/bin/rm -f $(OBJ)
	@echo "Removing object files succesful!"
	@echo "Removing object files from libft..."
	@make -C libft/ clean
	@echo "Removing object files from libft succesful!"

fclean: clean
	@echo "Removing binary file..."
	@/bin/rm -f $(NAME)
	@echo "Removing binary file succesful!"
	@echo "Removing binary file from libft"
	@make -C libft/ fclean
	@echo "Removing binary file from libft succesful!"

re: fclean all