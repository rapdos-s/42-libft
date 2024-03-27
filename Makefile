BUILD_DIR = build
LIBFT_DIR = libft
SOURCES_DIR = tests

NAME = libft_tester.out
LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_OBJS = $(wildcard $(LIBFT_DIR)/*.o)
LIBFT_SOURCES = $(patsubst $(LIBFT_DIR)/%.o, $(SOURCES_DIR)/test_%.c, $(LIBFT_OBJS))
COMPATIBLE_SOURCES = $(wildcard $(SOURCES_DIR)/*.c)

MAIN_SOURCE = $(SOURCES_DIR)/main.c
UTILS_SOURCE = $(SOURCES_DIR)/utils.c
SOURCES = $(MAIN_SOURCE) $(filter $(LIBFT_SOURCES), $(COMPATIBLE_SOURCES))
MAIN_OBJECT = $(patsubst $(SOURCES_DIR)/%.c, $(BUILD_DIR)/%.o, $(MAIN_SOURCE))
UTILS_OBJECT = $(patsubst $(SOURCES_DIR)/%.c, $(BUILD_DIR)/%.o, $(UTILS_SOURCE))
OBJECTS = $(patsubst $(SOURCES_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))
DEPENDENCIES = $(OBJECTS:.o=.d)
TESTS_OUT = $(patsubst $(SOURCES_DIR)/%.c, $(BUILD_DIR)/%.out, $(SOURCES))

ARGS = $(filter $(LIBFT_SOURCES), $(COMPATIBLE_SOURCES))
ARGS := $(ARGS:$(SOURCES_DIR)/%.c=$(BUILD_DIR)/%.out)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wpedantic
DEPFLAGS = -MMD -MF

INCLUDES = -I./$(SOURCES_DIR) -I./$(LIBFT_DIR)

MAKE = make
MAKE_FLAGS = --no-print-directory -C

MKDIR = mkdir
MKDIR_FLAGS = -p

RM = rm -fr

ECHO = echo -e

COLOR_RESET = "\033[0m"
COLOR_PURPLE = "\033[0;35m"

MESSAGE =  $(COLOR_PURPLE)"[ MAKE ]"$(COLOR_RESET)

REMOVE_OUTPUT = > /dev/null

.DEFAULT_GOAL = test

################################################################################

all: $(NAME)

clean:
	@$(ECHO) $(MESSAGE) "Cleaning libft intermediate files"
	@$(MAKE) $(MAKE_FLAGS) $(LIBFT_DIR) clean $(REMOVE_OUTPUT)
	@$(ECHO) $(MESSAGE) "Cleaning tests intermediate files"
	@$(RM) $(BUILD_DIR)

fclean:
	@$(ECHO) $(MESSAGE) "Cleaning libft intermediate and output files"
	@$(MAKE) $(MAKE_FLAGS) $(LIBFT_DIR) fclean $(REMOVE_OUTPUT)
	@$(ECHO) $(MESSAGE) "Cleaning tests intermediate and output files"
	@$(RM) $(BUILD_DIR) $(NAME)

re: fclean all

################################################################################

$(LIBFT): force
	@if [ $(MAKELEVEL) -eq 0 ]; then \
		$(ECHO) $(MESSAGE) "Building libft"; \
		$(MAKE) $(MAKE_FLAGS) $(LIBFT_DIR) all $(REMOVE_OUTPUT); \
	fi

$(NAME): $(LIBFT) $(OBJECTS) $(MAIN_OBJECT)
	@if [ $(MAKELEVEL) -eq 0 ]; then \
		$(ECHO) $(MESSAGE) "Building $(NAME)"; \
		$(CC) $(CFLAGS) $(MAIN_OBJECT) $(INCLUDES) -o $(NAME); \
	fi

$(BUILD_DIR):
	@$(MKDIR) $(MKDIR_FLAGS) $(BUILD_DIR)

################################################################################

$(BUILD_DIR)/%.o: $(SOURCES_DIR)/%.c $(UTILS_OBJECT) $(LIBFT) | $(BUILD_DIR)
#	@$(ECHO) $(MESSAGE) "Building $@"
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(BUILD_DIR)/$*.d $(INCLUDES) -c $< -o $@
#	@$(ECHO) $(MESSAGE) "Building $(@:.o=.out)"
	@$(CC) $(CFLAGS) $(INCLUDES) $< $(LIBFT) $(UTILS_OBJECT) -o $(@:.o=.out)

$(UTILS_OBJECT): $(UTILS_SOURCE) | $(BUILD_DIR)
#	@$(ECHO) $(MESSAGE) "Building $@"
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(BUILD_DIR)/utils.d $(INCLUDES) -c $< -o $@

################################################################################

test: $(NAME)
#	@$(ECHO) $(MESSAGE) "Calling test"
	@$(MAKE) $(MAKE_FLAGS) . run
	@$(ECHO) $(MESSAGE) "Done"

run: $(NAME)
	@$(ECHO) $(MESSAGE) "Running tests"
	@./$(NAME) $(ARGS)

################################################################################

-include $(DEPENDENCIES)

################################################################################

force:

################################################################################

duck:
	@$(ECHO) $(MESSAGE) "Furious quacking sound effect!"

################################################################################

.PHONY: all clean fclean re test run force duck
