# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 02:53:19 by rotrojan          #+#    #+#              #
#    Updated: 2021/06/21 18:34:34 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################### SOURCES ####################################

SRCS_DIR		=	./srcs/
SRCS 			=	ft_memset.c									\
					ft_bzero.c									\
					ft_memcpy.c									\
					ft_memccpy.c								\
					ft_memmove.c								\
					ft_memchr.c									\
					ft_memcmp.c									\
					ft_strlen.c									\
					ft_strnlen.c								\
					ft_isalpha.c								\
					ft_isdigit.c								\
					ft_isalnum.c								\
					ft_isascii.c								\
					ft_isprint.c								\
					ft_toupper.c								\
					ft_tolower.c								\
					ft_strchr.c									\
					ft_strrchr.c								\
					ft_strncmp.c								\
					ft_strlcpy.c								\
					ft_strlcat.c								\
					ft_strnstr.c								\
					ft_atoi.c									\
					ft_atoll.c									\
					ft_atod.c									\
					ft_strdup.c									\
					ft_calloc.c									\
					ft_realloc.c								\
					ft_strnlen.c								\
					ft_strndup.c								\
					ft_strcmp.c									\
					ft_strstr.c									\
					ft_isspace.c								\
					ft_substr.c									\
					ft_strjoin.c								\
					ft_strtrim.c								\
					ft_split.c									\
					ft_split_whitespaces.c						\
					ft_swap.c									\
					ft_itoa.c									\
					ft_strmapi.c								\
					ft_putchar_fd.c								\
					ft_putstr_fd.c								\
					ft_putendl_fd.c								\
					ft_putnbr_fd.c								\
					ft_memdel.c									\
					ft_lstnew.c									\
					ft_lstadd_front.c							\
					ft_lstsize.c								\
					ft_lstlast.c								\
					ft_lstadd_back.c							\
					ft_lstdelone.c								\
					ft_lstclear.c								\
					ft_circularlstclear.c						\
					ft_lstiter.c								\
					ft_lstmap.c									\
					get_next_line.c								\
					gc_malloc.c									\
					gc_free.c									\
					gc_free_all.c								\
					gc_exit.c									\
					ft_printf.c									\
					parsing.c									\
					conversion.c								\
					convert_char.c								\
					convert_str.c								\
					convert_int.c								\
					convert_uint.c								\
					convert_ptr.c								\
					convert_hexa.c								\
					ft_printf_utils.c							\
					digits_displaying_utils.c

OBJS			=	$(SRCS:%.c=$(OBJS_DIR)/%.o)
DEPENDENCIES	=	$(OBJS:.o=.d)

################################ MISCELLANEOUS #################################

INCLUDES_DIR	=	./includes/
OBJS_DIR		=	./.objs

CFLAGS			+=	-Wall -Wextra -Werror -MMD $(INCLUDES_DIR:%=-I%)

NAME			=	libft.a

##################################### BIN ######################################

CC				=	clang
AR				=	ar rcs
MKDIR			=	mkdir -p

#################################### RULES #####################################

vpath %.c $(SRCS_DIR) $(SRCS_DIR)/garbage_collector \
	$(SRCS_DIR)/lst_functions_templates $(SRCS_DIR)/ft_printf

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(AR) $@ $^

-include $(DEPENDENCIES)
$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

clean	:
	$(RM) -r $(OBJS_DIR)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:			re			\
					all			\
					clean		\
					fclean
