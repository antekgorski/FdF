# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 11:48:03 by prutkows          #+#    #+#              #
#    Updated: 2024/11/08 13:51:31 by prutkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

# compiler
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror

# sources
SRC_DIR =	srcs/
SRCS	=	$(SRC_DIR)main.c $(SRC_DIR)move_player_and_init_possition.c $(SRC_DIR)render_map_and_sprite.c $(SRC_DIR)map.c $(SRC_DIR)messages.c $(SRC_DIR)utils.c

# objects
OBJ_DIR	=	objs/
OBJ		=	$(SRC:.c=.o)
OBJS	=	$(OBJ_DIR)main.o $(OBJ_DIR)move_player_and_init_possition.o $(OBJ_DIR)render_map_and_sprite.o $(OBJ_DIR)map.o $(OBJ_DIR)messages.o $(OBJ_DIR)utils.o

# includes
INC		=	-I includes -I libs/libft -I libs/ft_printf -I libs/mlx

# libft
LIBFT_DIR	=	libs/libft/
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_DIR)$(LIBFT_NAME)

# ft_printf
PRINT_F_DIR		=	libs/ft_printf/
PRINT_F_NAME	=	libftprintf.a
PRINT_F			=	$(PRINT_F_DIR)$(PRINT_F_NAME)

# mlx
MLX_DIR		=	libs/mlx/
MLX_NAME	=	libmlx.a
MLX			=	$(MLX_DIR)$(MLX_NAME)

# colors & symbols
GREEN 	= 	\033[0;32m
NC		= 	\033[0m
TICK	=	✅


$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
			@$(CC) $(FLAGS) -c $< -o $@ $(INC)

all:		$(LIBFT) $(PRINT_F) $(MLX) $(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINT_F) $(MLX) $(INC) -lXext -lX11 -lm
			@$(PRINT_LOADING)
			@echo "$(GREEN)Program compilation successful		$(TICK)$(NC)"

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(LIBFT):
			@make -sC $(LIBFT_DIR)

$(PRINT_F):
			@make -sC $(PRINT_F_DIR)

$(MLX):
			@make -sC $(MLX_DIR)

clean:		
			@make clean -sC $(LIBFT_DIR)
			@make clean -sC $(PRINT_F_DIR)
			@make clean -sC $(MLX_DIR)
			@rm -rf $(OBJ_DIR)
			@$(PRINT_LOADING)
			@echo "$(GREEN)Cleaning of of .o files successful	$(TICK)$(NC)"

fclean:		clean
			@rm -f $(NAME) $(LIBFT) $(PRINT_F) $(MLX)
			@echo "$(GREEN)Full cleaning successful		$(TICK)$(NC)"

re:			fclean all

.PHONY:		all clean fclean re