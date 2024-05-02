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

NAME = libft.a

SOURCES			 = ft_isalpha.c \
				   ft_isdigit.c \
				   ft_isalnum.c \
				   ft_isascii.c \
				   ft_isprint.c \
				   ft_strlen.c \
				   ft_memset.c \
				   ft_bzero.c \
				   ft_memcpy.c \
				   ft_memmove.c \
				   ft_strlcpy.c \
				   ft_strlcat.c \
				   ft_toupper.c \
				   ft_tolower.c \
				   ft_strchr.c \
				   ft_strrchr.c \
				   ft_strncmp.c \
				   ft_memchr.c \
				   ft_memcmp.c \
				   ft_strnstr.c \
				   ft_atoi.c \
				   ft_calloc.c \
				   ft_strdup.c \
				   ft_substr.c \
				   ft_strjoin.c \
				   ft_strtrim.c \
				   ft_split.c \
				   ft_itoa.c \
				   ft_strmapi.c \
				   ft_striteri.c \
				   ft_putchar_fd.c \
				   ft_putstr_fd.c \
				   ft_putendl_fd.c \
				   ft_putnbr_fd.c
BONUS_SOURCES	 = ft_lstnew.c \
				   ft_lstadd_front.c \
				   ft_lstsize.c \
				   ft_lstlast.c \
				   ft_lstadd_back.c \
				   ft_lstdelone.c \
				   ft_lstclear.c \
				   ft_lstiter.c \
				   ft_lstmap.c

OBJECTS			 =	$(SOURCES:%.c=%.o)
BONUS_OBJECTS	 =	$(BONUS_SOURCES:%.c=%.o)

DEPENDENCIES		 = $(OBJECTS:.o=.d)
DEPENDENCIES_BONUS	 = $(BONUS_OBJECTS:.o=.d)

CC			 = cc
CFLAGS		 = -Wall -Wextra -Werror -Wpedantic
DEPFLAGS	 = -MMD -MF

AR		 = ar
ARFLAGS	 = crs

DEL = rm -rf

.DEFAULT_GOAL = all

################################################################################

all: mandatory bonus

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS) $(DEPENDENCIES) $(DEPENDENCIES_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

################################################################################

mandatory: $(OBJECTS)

bonus: $(BONUS_OBJECTS)

$(NAME): mandatory

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(DEPFLAGS) $(@:.o=.d)
	$(AR) $(ARFLAGS) $(NAME) $@

################################################################################

-include $(DEPENDENCIES)

-include $(DEPENDENCIES_BONUS)

################################################################################

duck:
	@echo "Furious quacking noises!"

.PHONY: all clean fclean re mandatory bonus duck
