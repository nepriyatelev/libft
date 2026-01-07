# Libft Makefile

# Program/Archive name
NAME		:= libft.a

# Tools
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -MMD -MP
AR			:= ar
ARFLAGS		:= rcs
RM			:= rm -f
RMDIR		:= rm -rf

# Paths
BUILD_DIR	:= build
INCLUDES	:= -I .

# Sources and objects
SOURCES		:= $(wildcard *.c)

# Split sources into mandatory and bonus by naming convention *_bonus.c
MANDATORY_SOURCES	:= $(filter-out %_bonus.c,$(SOURCES))
BONUS_SOURCES		:= $(filter %_bonus.c,$(SOURCES))

OBJ_MANDATORY		:= $(patsubst %.c,$(BUILD_DIR)/%.o,$(MANDATORY_SOURCES))
OBJ_BONUS			:= $(patsubst %.c,$(BUILD_DIR)/%.o,$(BONUS_SOURCES))

DEPS_MANDATORY		:= $(OBJ_MANDATORY:.o=.d)
DEPS_BONUS		:= $(OBJ_BONUS:.o=.d)

# Default target
all: $(NAME)

# Create placeholder archive when no sources yet
ifeq ($(strip $(OBJ_MANDATORY)),)
$(NAME):
	@echo "[info] No mandatory sources in $(SRCDIR); creating placeholder $(NAME)"
	@touch $(NAME)
else
$(NAME): $(OBJ_MANDATORY)
	@echo "[ar] $@"
	@$(AR) $(ARFLAGS) $@ $(OBJ_MANDATORY)
endif

# Object build rule
$(BUILD_DIR)/%.o: %.c libft.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Bonus: build archive including bonus objects
bonus: $(OBJ_MANDATORY) $(OBJ_BONUS)
	@if [ -z "$(OBJ_MANDATORY)$(OBJ_BONUS)" ]; then \
		echo "[info] No sources (mandatory/bonus) in $(SRCDIR); creating placeholder $(NAME)"; \
		touch $(NAME); \
	else \
		echo "[ar] $(NAME) (+bonus)"; \
		$(AR) $(ARFLAGS) $(NAME) $(OBJ_MANDATORY) $(OBJ_BONUS); \
	fi

# Cleaning
clean:
	@$(RMDIR) $(BUILD_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Norminette check
norm:
	@command -v norminette >/dev/null 2>&1 || { \
		echo ""; \
		echo "norminette is not installed. To install it:"; \
		echo ""; \
		echo "  Option 1 - Using pip (recommended):"; \
		echo "    pip install norminette"; \
		echo ""; \
		echo "  Option 2 - Using python3:"; \
		echo "    python3 -m pip install norminette"; \
		echo ""; \
		echo "  Option 3 - For this project with venv:"; \
		echo "    python3 -m venv .venv"; \
		echo "    source .venv/bin/activate"; \
		echo "    pip install norminette"; \
		echo ""; \
		exit 127; \
	}
	@norminette .

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - build libft.a (mandatory)"
	@echo "  bonus   - build with *_bonus.c"
	@echo "  clean   - remove build/ objects"
	@echo "  fclean  - remove build/ and libft.a"
	@echo "  re      - fclean then all"
	@echo "  norm    - run norminette"
	@echo "  help    - show this help"

.PHONY: all clean fclean re bonus norm help

# Include auto-generated dependency files if present
-include $(DEPS_MANDATORY) $(DEPS_BONUS)
