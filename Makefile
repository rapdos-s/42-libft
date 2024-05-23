# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 20:57:09 by rapdos-s          #+#    #+#              #
#    Updated: 2024/05/23 18:38:55 by rapdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files ########################################################################

NAME                 = libft.a

headers              = libft.h
headers_bonus        = libft_bonus.h

sources              = ft_isalpha.c
sources             += ft_isdigit.c
sources             += ft_isalnum.c
sources             += ft_isascii.c
sources             += ft_isprint.c
sources             += ft_strlen.c
sources             += ft_memset.c
sources             += ft_bzero.c
sources             += ft_memcpy.c
sources             += ft_memmove.c
sources             += ft_strlcpy.c
sources             += ft_strlcat.c
sources             += ft_toupper.c
sources             += ft_tolower.c
sources             += ft_strchr.c
sources             += ft_strrchr.c
sources             += ft_strncmp.c
sources             += ft_memchr.c
sources             += ft_memcmp.c
sources             += ft_strnstr.c
sources             += ft_atoi.c
sources             += ft_calloc.c
sources             += ft_strdup.c
sources             += ft_substr.c
sources             += ft_strjoin.c
sources             += ft_strtrim.c
sources             += ft_split.c
sources             += ft_itoa.c
sources             += ft_strmapi.c
sources             += ft_striteri.c
sources             += ft_putchar_fd.c
sources             += ft_putstr_fd.c
sources             += ft_putendl_fd.c
sources             += ft_putnbr_fd.c

sources_bonus        = ft_lstnew_bonus.c
sources_bonus       += ft_lstadd_front_bonus.c
sources_bonus       += ft_lstsize_bonus.c
sources_bonus       += ft_lstlast_bonus.c
sources_bonus       += ft_lstadd_back_bonus.c
sources_bonus       += ft_lstdelone_bonus.c
sources_bonus       += ft_lstclear_bonus.c
sources_bonus       += ft_lstiter_bonus.c
sources_bonus       += ft_lstmap_bonus.c

objects              = $(sources:%.c=%.o)
objects_bonus        = $(sources_bonus:%.c=%.o)

# Commands #####################################################################

CC                   = cc
CFLAGS               = -Wall -Wextra -Werror

ar                   = ar -crs
remove               = rm --force --recursive

# Special Targets ##############################################################

.DEFAULT_GOAL = all
.PHONY: all mandatory bonus clean fclean re

# Basic Rules ##################################################################

all: $(NAME)

$(NAME): mandatory bonus

mandatory: $(objects)

bonus: $(objects_bonus)

clean:
	$(remove) $(objects) $(objects_bonus)

fclean: clean
	$(remove) $(NAME)

re: fclean all

# Pattern Rules ################################################################

%.o: %.c $(headers)
	$(CC) $(CFLAGS) -c -o $(@) $(<)
	$(ar) $(NAME) $(@)

%_bonus.o: %_bonus.c $(headers_bonus)
	$(CC) $(CFLAGS) -c -o $(@) $(<)
	$(ar) $(NAME) $(@)

# Code Format ##################################################################

fmt:
	clang-format -i -style="{BasedOnStyle: Google, IndentWidth: 4, TabWidth: 4, UseTab: Always, AlignConsecutiveDeclarations: true, AlignConsecutiveAssignments: true, AlignTrailingComments: true, BreakBeforeBraces: Allman}" *.c *.h
