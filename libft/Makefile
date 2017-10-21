# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/17 16:35:36 by knzeng-e          #+#    #+#              #
#    Updated: 2017/09/16 13:30:29 by knzeng-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_PATH = ./srcs/
SRC = ./srcs/ft_atoi.c \
	  ./srcs/ft_isspace.c \
	  ./srcs/ft_memdel.c \
	  ./srcs/ft_str_is_alpha.c \
	  ./srcs/ft_striter.c \
	  ./srcs/ft_strnstr.c \
	  ./srcs/ft_atoi_base.c \
	  ./srcs/ft_itoa.c \
	  ./srcs/ft_memmove.c \
	  ./srcs/ft_str_is_lowercase.c \
	  ./srcs/ft_striteri.c \
	  ./srcs/ft_strrchr.c \
	  ./srcs/ft_bzero.c \
	  ./srcs/ft_list_push_params.c \
	  ./srcs/ft_memset.c \
	  ./srcs/ft_str_is_numeric.c \
	  ./srcs/ft_strjoin.c \
	  ./srcs/ft_strrev.c \
	  ./srcs/ft_count_words.c \
	  ./srcs/ft_lstadd.c \
	  ./srcs/ft_putchar.c \
	  ./srcs/ft_str_is_printable.c \
	  ./srcs/ft_strlcat.c \
	  ./srcs/ft_strsplit.c \
	  ./srcs/ft_create_elem.c \
	  ./srcs/ft_lstdel.c \
	  ./srcs/ft_putchar_fd.c \
	  ./srcs/ft_str_is_uppercase.c \
	  ./srcs/ft_strlcpy.c \
	  ./srcs/ft_strstr.c \
	  ./srcs/ft_get_int_size.c \
	  ./srcs/ft_lstdelone.c \
	  ./srcs/ft_putendl.c \
	  ./srcs/ft_strcapitalize.c \
	  ./srcs/ft_strlen.c \
	  ./srcs/ft_strsub.c \
	  ./srcs/ft_get_word.c \
	  ./srcs/ft_lstiter.c \
	  ./srcs/ft_putendl_fd.c \
	  ./srcs/ft_strcat.c \
	  ./srcs/ft_strlowcase.c \
	  ./srcs/ft_strtrim.c \
	  ./srcs/ft_is_low.c \
	  ./srcs/ft_lstmap.c \
	  ./srcs/ft_putnbr.c \
	  ./srcs/ft_strchr.c \
	  ./srcs/ft_strmap.c \
	  ./srcs/ft_strupcase.c \
	  ./srcs/ft_is_upper.c \
	  ./srcs/ft_lstnew.c \
	  ./srcs/ft_putnbr_base.c\
	  ./srcs/ft_strclr.c \
	  ./srcs/ft_strmapi.c \
	  ./srcs/ft_tolower.c \
	  ./srcs/ft_isalnum.c \
	  ./srcs/ft_memalloc.c \
	  ./srcs/ft_putnbr_fd.c \
	  ./srcs/ft_strcmp.c \
	  ./srcs/ft_strncat.c \
	  ./srcs/ft_toupper.c \
	  ./srcs/ft_isalpha.c \
	  ./srcs/ft_memccpy.c \
	  ./srcs/ft_putstr.c \
	  ./srcs/ft_strcpy.c \
	  ./srcs/ft_strncmp.c \
	  ./srcs/ft_isascii.c \
	  ./srcs/ft_memchr.c \
	  ./srcs/ft_putstr_fd.c \
	  ./srcs/ft_strdel.c \
	  ./srcs/ft_strncpy.c \
	  ./srcs/ft_isdigit.c \
	  ./srcs/ft_memcmp.c \
	  ./srcs/ft_putstr_non_printable.c \
	  ./srcs/ft_strdup.c \
	  ./srcs/ft_strnequ.c \
	  ./srcs/ft_isprint.c \
	  ./srcs/ft_memcpy.c \
	  ./srcs/ft_split_whitespaces.c \
	  ./srcs/ft_strequ.c \
	  ./srcs/ft_strnew.c \
	  ./srcs/get_next_line.c

INC_PATH = -I./includes/
OBJ = ft_atoi.o \
	  ft_isspace.o \
	  ft_memdel.o \
	  ft_str_is_alpha.o \
	  ft_striter.o \
	  ft_strnstr.o \
	  ft_atoi_base.o \
	  ft_itoa.o \
	  ft_memmove.o \
	  ft_str_is_lowercase.o \
	  ft_striteri.o \
	  ft_strrchr.o \
	  ft_bzero.o \
	  ft_list_push_params.o \
	  ft_memset.o \
	  ft_str_is_numeric.o \
	  ft_strjoin.o \
	  ft_strrev.o \
	  ft_count_words.o \
	  ft_lstadd.o \
	  ft_putchar.o \
	  ft_str_is_printable.o \
	  ft_strlcat.o \
	  ft_strsplit.o \
	  ft_create_elem.o \
	  ft_lstdel.o \
	  ft_putchar_fd.o \
	  ft_str_is_uppercase.o \
	  ft_strlcpy.o \
	  ft_strstr.o \
	  ft_get_int_size.o \
	  ft_lstdelone.o \
	  ft_putendl.o \
	  ft_strcapitalize.o \
	  ft_strlen.o \
	  ft_strsub.o \
	  ft_get_word.o \
	  ft_lstiter.o \
	  ft_putendl_fd.o \
	  ft_strcat.o \
	  ft_strlowcase.o \
	  ft_strtrim.o \
	  ft_is_low.o \
	  ft_lstmap.o \
	  ft_putnbr.o \
	  ft_strchr.o \
	  ft_strmap.o \
	  ft_strupcase.o \
	  ft_is_upper.o \
	  ft_lstnew.o \
	  ft_putnbr_base.o\
	  ft_strclr.o \
	  ft_strmapi.o \
	  ft_tolower.o \
	  ft_isalnum.o \
	  ft_memalloc.o \
	  ft_putnbr_fd.o \
	  ft_strcmp.o \
	  ft_strncat.o \
	  ft_toupper.o \
	  ft_isalpha.o \
	  ft_memccpy.o \
	  ft_putstr.o \
	  ft_strcpy.o \
	  ft_strncmp.o \
	  ft_isascii.o \
	  ft_memchr.o \
	  ft_putstr_fd.o \
	  ft_strdel.o \
	  ft_strncpy.o \
	  ft_isdigit.o \
	  ft_memcmp.o \
	  ft_putstr_non_printable.o \
	  ft_strdup.o \
	  ft_strnequ.o \
	  ft_isprint.o \
	  ft_memcpy.o \
	  ft_split_whitespaces.o \
	  ft_strequ.o \
	  ft_strnew.o \
	  get_next_line.o

CC = gcc

FLAGS = -Wall -Werror -Wextra -c

all	: $(NAME)

$(NAME) :
	@echo "Compile all .c files"
	@echo "Linking all .o files and obtain lib.ft binary"
	@$(CC) $(FLAGS) $(INC_PATH) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)


clean : all
	@echo "\033[32m >>> [LIBFT] >>> \033[31mRemove .o files..\033[0m"
	@rm -rf $(OBJ)

fclean : clean
	@echo "removing $(NAME)"
	@rm -rf $(NAME)

norme :
	norminette $(INC_PATH) $(SRC_PATH)

re : fclean
	@make all

.PHONY : all clean fclean norme re
