# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/15 09:52:03 by knzeng-e          #+#    #+#              #
#    Updated: 2017/09/16 13:30:48 by knzeng-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@echo "\033[32m >>> [MLX] >>> \033[31mRemove .o files..\033[0m"
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
