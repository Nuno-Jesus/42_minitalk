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

#! Flags
CFLAGS = -Wall -Wextra -Werror
MKFLAGS = --no-print-directory

#! Folders
DEPS = includes
SRCS = .

#! Files
TARGET = utils.o
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
PRINTF = ft_printf/libftprintf.a

#! Rules

all: $(CLIENT) $(SERVER)

$(CLIENT): $(TARGET)
	@echo "[${CYAN}Compiling${RESET}] ${GREEN}ft_printf${RESET}"
	@make $(MKFLAGS) -C ft_printf
	$(CC) $(CFLAGS) client.c $(TARGET) $(PRINTF) -o $(CLIENT) -I $(DEPS)

$(SERVER): $(TARGET)
	$(CC) $(CFLAGS) server.c $(TARGET) $(PRINTF) -o $(SERVER) -I $(DEPS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

clean:
	@echo "[${CYAN}Cleaning${RESET}] ${GREEN}minitalk *.c${RESET}"
	@make clean $(MKFLAGS) -C ft_printf
	@$(RM) $(TARGET)

fclean: clean
	@make fclean $(MKFLAGS) -C ft_printf
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(TARGET)
	@echo "[${CYAN}Compiling${RESET}] ${GREEN}ft_printf${RESET}"
	@make $(MKFLAGS) -C ft_printf
	$(CC) $(CFLAGS) client_bonus.c $(TARGET) $(PRINTF) -o $(CLIENT_BONUS) -I $(DEPS)

$(SERVER_BONUS): $(TARGET)
	$(CC) $(CFLAGS) server_bonus.c $(TARGET) $(PRINTF) -o $(SERVER_BONUS) -I $(DEPS)

re: fclean all
