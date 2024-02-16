#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 07:41:41 by rapdos-s          #+#    #+#              #
#    Updated: 2024/02/16 09:33:09 by rapdos-s         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SOURCES_DIR			 = tests
BONUS_DIR			 = tests_bonus
LIBFT_DIR			 = libft
BUILD_DIR			 = build

NAME				 = libft_tests.out
NAME_BONUS			 = libft_bonus_tests.out
LIBFT				 = ${LIBFT_DIR}/libft.a

SOURCES				 = ${wildcard ${SOURCES_DIR}/*.c}
OBJECTS				 = ${patsubst ${SOURCES_DIR}/%.c, ${BUILD_DIR}/%.o, ${SOURCES}}
DEPENDENCIES		 = ${OBJECTS:.o=.d}

BONUS				 = ${wildcard ${BONUS_DIR}/*.c}
OBJECTS_BONUS		 = ${patsubst ${BONUS_DIR}/%.c, ${BUILD_DIR}/%.o, ${BONUS}}
DEPENDENCIES_BONUS	 = ${OBJECTS_BONUS:.o=.d}

CC					 = cc
CFLAGS				 = -Wall -Wextra -Werror -Wpedantic
DEPFLAGS			 = -MMD -MF
INCLUDES			 = -I./${SOURCES_DIR} -I./${BONUS_DIR} -I./${LIBFT_DIR}

VALGRIND			 = valgrind
VALFLAGS			 = --show-error-list=yes \
					   --leak-check=full \
					   --show-leak-kinds=all \
					   --track-origins=yes \
					   --track-fds=yes

DEL					 = rm -rf
MKDIR				 = mkdir -p

MAKE				 = make
MKFLAGS				 = --no-print-directory -C

.DEFAULT_GOAL		 = all

################################################################################

${NAME}: ${OBJECTS} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDES} ${OBJECTS} ${LIBFT} -o ${NAME}

${NAME_BONUS}: ${OBJECTS_BONUS} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDES} ${OBJECTS_BONUS} ${LIBFT} -o ${NAME_BONUS}

all: mandatory bonus

mandatory: ${NAME}

bonus: ${NAME_BONUS}

clean:
	${DEL} ${BUILD_DIR}
	${MAKE} ${MKFLAGS} ${LIBFT_DIR} clean

fclean: clean
	${DEL} ${NAME} ${NAME_BONUS}
	${MAKE} ${MKFLAGS} ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all mandatory bonus clean fclean re

################################################################################

-include ${DEPENDENCIES}

-include ${DEPENDENCIES_BONUS}

${BUILD_DIR}/%.o: ${SOURCES_DIR}/%.c | ${BUILD_DIR}
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@ ${DEPFLAGS} ${@:.o=.d}

${BUILD_DIR}/%.o: ${BNS_DIR}/%.c | ${BUILD_DIR}
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@ ${DEPFLAGS} ${@:.o=.d}

${LIBFT}: force
	${MAKE} ${MKFLAGS} ${LIBFT_DIR}

${BUILD_DIR}:
	${MKDIR} ${BUILD_DIR}

################################################################################

test: all
	./${NAME}
	./${NAME_BONUS}

test_mandatory: ${NAME}
	./${NAME}

test_bonus: ${NAME_BONUS}
	./${NAME_BONUS}

.PHONY: test test_mandatory test_bonus

################################################################################

valgrind: all
	${VALGRIND} ${VALFLAGS} ./${NAME}
	${VALGRIND} ${VALFLAGS} ./${NAME_BONUS}

valgrind_mandatory: ${NAME}
	${VALGRIND} ${VALFLAGS} ./${NAME}

valgrind_bonus: ${NAME_BONUS}
	${VALGRIND} ${VALFLAGS} ./${NAME_BONUS}

.PHONY: valgrind valgrind_mandatory valgrind_bonus

################################################################################

force:

.PHONY: force

################################################################################

duck:
	@echo "Furious quacking noises!"

.PHONY: duck

print:
	@echo "SOURCES: ${SOURCES}"
	@echo "OBJECTS: ${OBJECTS}"
	@echo "DEPENDENCIES: ${DEPENDENCIES}"
	@echo "BONUS: ${BONUS}"
	@echo "OBJECTS_BONUS: ${OBJECTS_BONUS}"
	@echo "DEPENDENCIES_BONUS: ${DEPENDENCIES_BONUS}"