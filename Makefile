# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 00:27:22 by rapdos-s          #+#    #+#              #
#    Updated: 2024/11/13 02:18:10 by rapdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files ########################################################################

NAME                 = libft.a

headers              = libft.h
headers_bonus        = libft_bonus.h

sources              = ft_isalpha.c
# sources             += ft_isdigit.c
# sources             += ft_isalnum.c
# sources             += ft_isascii.c
# sources             += ft_isprint.c
# sources             += ft_strlen.c
# sources             += ft_memset.c
# sources             += ft_bzero.c
# sources             += ft_memcpy.c
# sources             += ft_memmove.c
# sources             += ft_strlcpy.c
# sources             += ft_strlcat.c
# sources             += ft_toupper.c
# sources             += ft_tolower.c
# sources             += ft_strchr.c
# sources             += ft_strrchr.c
# sources             += ft_strncmp.c
# sources             += ft_memchr.c
# sources             += ft_memcmp.c
# sources             += ft_strnstr.c
# sources             += ft_atoi.c
# sources             += ft_calloc.c
# sources             += ft_strdup.c
# sources             += ft_substr.c
# sources             += ft_strjoin.c
# sources             += ft_strtrim.c
# sources             += ft_split.c
# sources             += ft_itoa.c
# sources             += ft_strmapi.c
# sources             += ft_striteri.c
# sources             += ft_putchar_fd.c
# sources             += ft_putstr_fd.c
# sources             += ft_putendl_fd.c
# sources             += ft_putnbr_fd.c

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

dependencies         = $(sources:%.c=%.d)
dependencies_bonus   = $(sources_bonus:%.c=%.d)

# colors #######################################################################

gray                 = \033[0;30m
red                  = \033[0;31m
green                = \033[0;32m
yellow               = \033[1;33m
blue                 = \033[0;34m
magenta              = \033[0;35m
cyan                 = \033[0;36m
reset                = \033[0m
main_color           = $(cyan)
tag                  = "[ $(main_color)$(NAME)$(reset) ]"

# Commands #####################################################################

CC                   = $$(which clang)
CFLAGS               = -Wall -Wextra -Werror -Wpedantic

ar                   = $$(which ar) -crs
echo                 = $$(which echo) -e $(tag)
make                 = $$(which make) --no-print-directory
remove               = $$(which rm) -f
depflags             = -MMD -MF $(@:%.o=%.d)

# Special Targets ##############################################################

-include $(dependencies)
-include $(dependencies_bonus)
.DEFAULT_GOAL = all
.PHONY: all clean fclean re
.PHONY: mandatory bonus duck

# Basic Rules ##################################################################

all:
	@$(echo) "make all"
	@$(make) mandatory
	@$(make) bonus
	@$(echo) "make all done."

$(NAME):
	@$(echo) "make $(NAME)"
	@$(make) mandatory
	@$(make) bonus
	@$(echo) "make $(NAME) done."

clean:
	@$(echo) "make clean"
	@$(echo) "removing object files..."
	@$(remove) $(objects)
	@$(echo) "removing bonus object files..."
	@$(remove) $(objects_bonus)
	@$(echo) "removing dependency files..."
	@$(remove) $(dependencies)
	@$(echo) "removing bonus dependency files..."
	@$(remove) $(dependencies_bonus)
	@$(echo) "make clean done."

fclean:
	@$(echo) "make fclean"
	@$(make) clean
	@$(remove) $(NAME)
	@$(echo) "make fclean done."

re:
	@$(echo) "make re"
	@$(make) fclean
	@$(make) all
	@$(echo) "make re done."

# Compilation Rules ############################################################

mandatory: $(objects)

bonus: $(objects_bonus)

%.o: %.c
	@$(echo) "Compiling $(<)..."
	@$(CC) -c $(CFLAGS) $(depflags) $(<) -o $(@)
	@$(echo) "$(<) compiled."
	@$(echo) "Linking $(@)..."
	@$(ar) $(NAME) $(@)
	@$(echo) "$(@) linked."

# Other Rules ##################################################################

duck:
	@$(echo) "Furious Quacking Sound Effect"

################################################################################