# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 15:20:47 by lsadi             #+#    #+#              #
#    Updated: 2025/07/16 10:31:11 by reeer-aa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strcmp.c \
      ft_str_len.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
      ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_str_chr.c \
      ft_strrchr.c ft_strncmp.c ft_memchr.c ft_strnstr.c ft_atoi.c \
      ft_itoa.c ft_substr.c ft_str_join.c ft_strtrim.c ft_strdup.c \
      ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c free_split.c \
      ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_memcmp.c ft_calloc.c ft_strjoin_three.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

# Couleurs ANSI
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
CYAN = \033[1;36m
RESET = \033[0m

# Règle principale
all: ${NAME}

# Règle pour compiler les fichiers objets
%.o : %.c
	@echo "$(BLUE)Compiling $(CYAN)$< $(RESET)..."
	@${CC} ${CFLAGS} -c $< -o $@

# Règle pour créer la bibliothèque statique
${NAME}: ${OBJS}
	@echo "$(GREEN)Creating static library $(CYAN)${NAME}$(RESET)..."
	@${AR} ${NAME} ${OBJS}
	@echo "$(GREEN)Build complete!$(RESET)"

# Règle pour nettoyer les fichiers objets
clean :
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f ${OBJS}
	@echo "$(GREEN)Clean complete!$(RESET)"

# Règle pour nettoyer les fichiers objets et l'exécutable
fclean : clean
	@echo "$(RED)Removing $(CYAN)${NAME}$(RESET)..."
	@rm -f ${NAME}
	@echo "$(GREEN)Full clean complete!$(RESET)"

# Règle pour recompiler entièrement le projet
re : fclean all
	@echo "$(GREEN)Rebuild complete!$(RESET)"

.PHONY: all clean fclean re