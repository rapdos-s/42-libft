#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 06:58:34 by rapdos-s          #+#    #+#              #
#    Updated: 2024/02/16 09:45:28 by rapdos-s         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			 = libft.a

SOURCES				 =	ft_isalpha.c
BONUS_SOURCES		 = 

OBJECTS				 =	${SOURCES:%.c=%.o}
BONUS_OBJECTS		 =	${BONUS_SOURCES:%.c=%.o}

DEPENDENCIES		 = ${OBJECTS:.o=.d}
DEPENDENCIES_BONUS	 = ${BONUS_OBJECTS:.o=.d}

CC					 = cc
CFLAGS				 = -Wall -Wextra -Werror -Wpedantic
DEPFLAGS			 = -MMD -MF

AR					 = ar
ARFLAGS				 = crs

DEL					 = rm -rf

.DEFAULT_GOAL		 = all

################################################################################

all: ${NAME} bonus

$(NAME): ${OBJECTS}

mandatory: ${NAME}

bonus: ${BONUS_OBJECTS}

clean:
	${RM} ${OBJECTS} ${B_OBJECTS} ${DEPENDENCIES} ${DEPENDENCIES_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all mandatory bonus clean fclean re

################################################################################

-include ${DEPENDENCIES}

-include ${DEPENDENCIES_BONUS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ ${DEPFLAGS} ${@:.o=.d}
	${AR} ${ARFLAGS} ${NAME} $@

################################################################################

duck:
	@echo "Furious quacking noises!"

.PHONY: duck
