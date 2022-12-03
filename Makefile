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
PRINTF = ft_printf/libftprintf.a

#! Rules

all: $(CLIENT) $(SERVER)

$(CLIENT): $(TARGET)
	make $(MKFLAGS) -C ft_printf
	$(CC) $(CFLAGS) client.c $(TARGET) $(PRINTF) -o client -I $(DEPS)

$(SERVER): $(TARGET)
	$(CC) $(CFLAGS) server.c $(TARGET) $(PRINTF) -o server -I $(DEPS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

clean:
	make clean $(MKFLAGS) -C ft_printf
	$(RM) $(TARGET)

fclean: clean
	make fclean $(MKFLAGS) -C ft_printf
	$(RM) $(CLIENT) $(SERVER)

re: fclean all
