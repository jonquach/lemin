##
## Makefile for  in /home/kauch_j/rendu/prog_elem/lem_in
## 
## Made by kauch_j
## Login   <kauch_j@epitech.net>
## 
## Started on  Wed Apr 16 17:02:53 2014 kauch_j
## Last update Sun May  4 14:59:46 2014 kauch_j
##

CC	=	gcc

SRC	=	xmalloc.c \
		my_str_to_wordtab.c \
		get_pipe.c \
		ants.c \
		solve.c \
		is_num.c \
		get_ants.c \
		count_len.c \
		find_pipe.c \
		pipe_get_function.c \
		pipe_check_function.c \
		set_link.c \
		functions.c \
		functions_str.c \
		aff_str.c \
		algo.c \
		define_name.c \
		check_name.c \
		get_pipe_number.c \
		check_error.c \
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

RED     =	\033[1;31m

GREEN   =	\033[1;32m

WHITE   =	\033[0m

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@echo -e "$(GREEN) > COMPILATION .C EN COURS\n"
		$(CC) -o $(NAME) $(OBJ)
		@echo -e "$(GREEN) > COMPILATION .C TERMINEE\n"
		@echo -e "$(RED)"
		@cat ./Makefile_deco/header
		@echo -e "$(WHITE)"

clean	:
		@echo -e "$(GREEN) > SUPPRESSION DES .O"
		rm -f $(OBJ)
		@echo -e "$(WHITE)"

fclean	:	clean
		@echo -e "$(GREEN) > SUPPRESSION DU BINAIRE"
		rm -f $(NAME)
		@echo -e "$(WHITE)"

re	:	fclean all

coffee:
		@echo -e "$(RED)"
		@cat ./Makefile_deco/coffee
		@echo -e "$(WHITE)"

.PHONY	:	all clean fclean re
