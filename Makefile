NAME = fractol
SRC_PATH = ./srcs/
SRC_NAME = $(shell ls $(SRC_PATH) | grep .c)
INC_PATH = ./includes/
OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_PATH = ./libft/srcs/
LIB_SRCS = $(shell ls $(LIB_PATH) | grep .c)
LIB_INC = /libft/includes/
FT_LIB = ./libft/libft.a
MLX_LIB = ./mlx/mlx.a
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -Ofast
FFLAGS = -framework AppKit -framework OpenGL -Lmlx -L. -Llibft -lmlx -lft

all: $(OBJ) $(FT_LIB) $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31m >>> \033[32mCOMPILING \"$(NAME)\"..\033[31m <<<\033[0m"
	@$(CC) $(CFLAGS) $(FFLAGS) $(OBJ) -I$(LIB_INC) -I$(INC_PATH) -Imlx -o $@

$(FT_LIB):
	#clear
	@echo "\033[31m >>> \033[32mCOMPILING \"$(FT_LIB)\"..\033[31m <<<\033[0m"
	@make -C libft

$(MLX_LIB):
	#clear
	@echo "\033[31m >>> \033[32mCOMPILING \"$(MLX_LIB)\"..\033[31m <<<\033[0m"
	@make -C mlx

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
	@mkdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	@$(CC) $(CFLAGS) -c $< -I libft/includes -I ./includes -I mlx -o $@

clean:
	@echo "Remove all .o files"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	@make -C libft clean
	@make -C mlx clean

fclean: clean
		@rm -f $(NAME)
		@echo "\033[31m--- \033[33;4m \"$(NAME)\" EXECUTABLE DELETED\033[0m"

norme :
	norminette $(INC_PATH) $(SRC_PATH)

re: fclean all

.PHONY : all clean fclean norme re
