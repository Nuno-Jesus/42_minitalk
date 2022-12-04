#! Colors
RESET = \033[0m       # Text Reset
BLACK = \033[1;30m       # Black
RED = \033[1;31m         # Red
GREEN = \033[1;32m       # Green
YELLOW = \033[1;33m      # Yellow
BLUE = \033[1;34m       # Blue
PURPLE = \033[1;35m     # Purple
CYAN = \033[1;36m        # Cyan
WHITE = \033[1;37m       # White

#! Commands
CC = cc
RM = rm -f
AR = ar -rc

#! Folders
DEPS = includes
SRCS = .

#! Flags
CFLAGS = -Wall -Wextra -Werror
MKFLAGS = --no-print-directory
TARGET = 	ft_printf.o ft_printf_utils.o ft_convert_char.o ft_convert_string.o ft_convert_integer.o \
			ft_convert_hexa.o ft_convert_module.o ft_convert_pointer.o ft_convert_unsigned.o \
			flags.o
NAME = libftprintf.a

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

all: $(NAME)

$(NAME): $(TARGET)
	@echo "[${CYAN}Compiling${RESET}] ${GREEN}libft${RESET}"
	@make bonus -C libft
	@cp libft/libft.a $(NAME)
	@echo "[${CYAN}Linking${RESET}] ${GREEN}ft_printf${RESET}"
	@$(AR) $(NAME) $(TARGET)

clean:
	@echo "[${CYAN}Cleaning${RESET}] ${GREEN}ft_printf${RESET}"
	@make clean -C libft
	@$(RM) $(TARGET) $(BONUS_TARGET)

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME) $(BONUS_TARGET)

bonus: all

re: fclean all