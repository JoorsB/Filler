# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jboer <jboer@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/16 12:56:23 by jboer          #+#    #+#                 #
#    Updated: 2019/12/10 16:16:31 by jboer         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

CC = gcc

SRC = ft_atoi.c ft_isalpha.c ft_memcpy.c ft_putnbr_fd.c ft_strdel.c \
ft_strmapi.c ft_strstr.c ft_isascii.c ft_memdel.c ft_putstr.c \
ft_strdup.c ft_strncat.c ft_strsub.c ft_isdigit.c ft_memmove.c \
ft_putstr_fd.c ft_strequ.c ft_strncmp.c ft_strtrim.c ft_bzero.c \
ft_isprint.c ft_memset.c ft_strc.c ft_striter.c ft_strncpy.c ft_tolower.c \
ft_charc.c ft_itoa.c ft_putchar.c ft_strcat.c ft_striteri.c ft_strnequ.c \
ft_toupper.c ft_delimc.c ft_memalloc.c ft_putchar_fd.c ft_strchr.c \
ft_strjoin.c ft_strnew.c ft_intlen.c ft_memccpy.c ft_putendl.c ft_strclr.c \
ft_strlcat.c ft_strnstr.c ft_intos.c ft_memchr.c ft_putendl_fd.c ft_strcmp.c \
ft_strlen.c ft_strrchr.c ft_isalnum.c ft_memcmp.c ft_putnbr.c ft_strcpy.c \
ft_strmap.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
ft_lstiter.c ft_lstmap.c ft_printarray.c ft_strndup.c ft_strdcount.c \
ft_astrlen.c ft_mapdel.c ft_charindex.c get_next_line.c ft_ispint.c \
ft_llatoi.c ft_natoi.c ft_datoi.c ft_printarray_fd.c ft_powerof.c

HEAD = -I./

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME):
		@echo Creating basic libary...
		@$(CC) $(FLAGS) -c $(SRC) $(HEAD)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@make clean
		@echo libft.a created

clean:
		@rm -rf $(OBJ)
		@rm -rf *~

fclean: clean
		@rm -rf $(NAME)

re: fclean all
