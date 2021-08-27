# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 16:26:22 by rotrojan          #+#    #+#              #
#    Updated: 2021/08/25 15:25:45 by bigo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = srcs
OBJS_DIR = .objs

NAME = fdf
SRCS = main.c \
	error_management.c \
	parsing_utils.c \
	utils.c \
	parsing.c \
	mlx_hooks.c \
	mlx_utils.c \
	display_projection.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
DEPENDENCIES = $(OBJS:%.o=%.d)

CC = clang
MKDIR = mkdir -p
RM = rm -f

LIBS = ft

MLX_DIR = minilibx-linux

CFLAGS = -MMD -Wall -Wextra -Werror -I includes/ -I libft/includes/ -I $(MLX_DIR)
LDFLAGS = -L libft/ -lft -L $(MLX_DIR) -lmlx -lXext -lX11

vpath %.c $(addprefix $(SRCS_DIR), /. /mlx)
vpath %.a $(LIBS:%=lib%) minilibx-$(MLX_DIR)

all:
	$(foreach LIB, $(LIBS), $(MAKE) -C lib$(LIB) ;)
	$(MAKE) -C $(MLX_DIR) 2> /dev/null
	$(MAKE) $(NAME)

$(NAME): $(OBJS) $(LIBS:%=lib%.a)
	$(foreach LIB, $(LIBS), $(MAKE) -C lib$(LIB) ;)
	$(MAKE) -C $(MLX_DIR) 2> /dev/null
	$(CC) $^ -o $@ $(LDFLAGS)

lib%.a:
	$(MAKE) -C $(@:%.a=%)

-include $(DEPENDENCIES)
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $@

clean:
	$(RM) -r $(OBJS_DIR)
	$(foreach LIB, $(LIBS), $(MAKE) clean -C lib$(LIB) ;)
	$(MAKE) clean -C $(MLX_DIR) 2> /dev/null

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CHECKER_NAME)
	$(foreach LIB, $(LIBS), $(MAKE) fclean -C lib$(LIB) ;)

re: fclean all

.PHONY: all clean fclean re
