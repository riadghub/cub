# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 16:42:45 by lsadi             #+#    #+#              #
#    Updated: 2025/07/16 14:33:57 by reeer-aa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = src/main.c \
	src/parse_file.c \
	src/clean.c \
	src/map.c \
	src/parse_map.c \
	src/render.c \
	src/game.c \
	src/textures.c \
	src/player.c \
	src/draw.c \
	src/ray.c \
	src/image.c \
	src/utils.c \
	src/is_valid.c \
	src/flood_fill.c \
	src/parse_texture.c \
	src/parse_color.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c 

HEADERS = ./includes/

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./minilibx-linux

MLX = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

get_next_line/%.o: get_next_line/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Couleurs ANSI
RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
RESET = \033[0m

# Règle principale
all: ${NAME}

# Règle pour compiler les fichiers objets
%.o : %.c
	@echo "$(BLUE)Compiling $(CYAN)$< $(RESET)..."
	@${CC} ${CFLAGS} -I ${HEADERS} -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

# Règle pour compiler la MiniLibX
$(MLX):
	@echo "$(CYAN)Compiling MiniLibX...$(RESET)"
	@make -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(GREEN)MiniLibX compiled!$(RESET)"

# Règle pour compiler libft
$(LIBFT):
	@echo "$(PURPLE)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR) --no-print-directory
	@echo "$(GREEN)Libft compiled!$(RESET)"

# Règle pour lier le programme final
${NAME}: ${OBJS} $(MLX) $(LIBFT)
	@echo "$(GREEN)Linking objects into $(CYAN)${NAME}$(RESET)..."
	@${CC} ${CFLAGS} -I ${HEADERS} ${OBJS} ${MLX_FLAGS} -L$(LIBFT_DIR) -lft -o ${NAME}
	@echo "$(GREEN)Build complete!$(RESET)"

# Règle pour nettoyer les fichiers objets
clean :
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f ${OBJS}
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(GREEN)Clean complete!$(RESET)"

# Règle pour nettoyer les fichiers objets et l'exécutable
fclean : clean
	@echo "$(RED)Removing $(CYAN)${NAME}$(RESET)..."
	@rm -f ${NAME}
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(GREEN)Full clean complete!$(RESET)"

# Règle pour recompiler entièrement le projet
re : fclean all
	@echo "$(GREEN)Rebuild complete!$(RESET)"

dev : re
		make clean
		clear
		valgrind -s --show-leak-kinds=all  --track-origins=yes --leak-check=full ./cub3D maps/map.cub
		
.PHONY: all clean fclean re dev
