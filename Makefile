# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jboer <jboer@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/07/11 13:59:14 by jboer          #+#    #+#                 #
#    Updated: 2019/12/14 16:34:25 by jboer         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = jboer.filler

FlAGS = -Wall -Werror -Wextra

LIB = libft/libft.a

FILES_NAME = filler map_token adddim placepiece addpoints morechecks

FILES = $(FILES_NAME:%=src/%.c)

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME):
	@make re -C libft/
	@gcc -o $(NAME) $(FLAGS) $(FILES) $(LIB)
	@echo jboer.filler created

clean:
	@rm -rf $(OBJ)
	@make clean -C libft/

fclean: clean
	@rm -rf jboer.filler
	@make fclean -C libft/

re: fclean all
