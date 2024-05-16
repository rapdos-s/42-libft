# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 20:57:09 by rapdos-s          #+#    #+#              #
#    Updated: 2024/03/27 20:57:09 by rapdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files ########################################################################

NAME       = libft.a

HDR        = libft.h
HDR_B      = libft_bonus.h

SRC        = ft_isalpha.c
SRC       += ft_isdigit.c
SRC       += ft_isalnum.c
SRC       += ft_isascii.c
SRC       += ft_isprint.c
SRC       += ft_strlen.c
SRC       += ft_memset.c
SRC       += ft_bzero.c
SRC       += ft_memcpy.c
SRC       += ft_memmove.c
SRC       += ft_strlcpy.c
SRC       += ft_strlcat.c
SRC       += ft_toupper.c
SRC       += ft_tolower.c
SRC       += ft_strchr.c
SRC       += ft_strrchr.c
SRC       += ft_strncmp.c
SRC       += ft_memchr.c
SRC       += ft_memcmp.c
SRC       += ft_strnstr.c
SRC       += ft_atoi.c
SRC       += ft_calloc.c
SRC       += ft_strdup.c
SRC       += ft_substr.c
SRC       += ft_strjoin.c
SRC       += ft_strtrim.c
SRC       += ft_split.c
SRC       += ft_itoa.c
SRC       += ft_strmapi.c
SRC       += ft_striteri.c
SRC       += ft_putchar_fd.c
SRC       += ft_putstr_fd.c
SRC       += ft_putendl_fd.c
SRC       += ft_putnbr_fd.c

SRC_B      = ft_lstnew_bonus.c
SRC_B     += ft_lstadd_front_bonus.c
SRC_B     += ft_lstsize_bonus.c
SRC_B     += ft_lstlast_bonus.c
SRC_B     += ft_lstadd_back_bonus.c
SRC_B     += ft_lstdelone_bonus.c
SRC_B     += ft_lstclear_bonus.c
SRC_B     += ft_lstiter_bonus.c
SRC_B     += ft_lstmap_bonus.c

OBJ        = $(SRC:%.c=%.o)
OBJ_B      = $(SRC_B:%.c=%.o)

# Commands #####################################################################

CC         = cc
CFLAGS     = -Wall -Wextra -Werror

AR         = ar -crs
DEL        = rm -rf

# Special Targets ##############################################################

.DEFAULT_GOAL = all
.PHONY: all clean fclean re mandatory bonus

# Basic Rules ##################################################################

all: $(NAME)

$(NAME): mandatory bonus

mandatory: $(OBJ)

bonus: $(OBJ_B)

clean:
	$(DEL) $(OBJ) $(OBJ_B)

fclean: clean
	$(DEL) $(NAME)

re: fclean all

# Pattern Rules ################################################################

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c -o $(@) $(<)
	$(AR) $(NAME) $(@)

%_bonus.o: %_bonus.c $(HDR_B)
	$(CC) $(CFLAGS) -c -o $(@) $(<)
	$(AR) $(NAME) $(@)
