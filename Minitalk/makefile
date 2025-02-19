NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c

GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
RESET = \033[0m

all: $(NAME_CLIENT) $(NAME_SERVER)
	@echo "✅ $(GREEN)Make successfully completed!$(RESET)"

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	@echo "🎉 $(GREEN)Bonus successfully compiled!$(RESET)"

$(NAME_CLIENT): $(SRC_CLIENT)	
	@$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_SERVER)
	@$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT_BONUS): $(SRC_CLIENT_BONUS)
	@$(CC) $(CFLAGS) $(SRC_CLIENT_BONUS) client_util_bonus.c -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(SRC_SERVER_BONUS)
	@$(CC) $(CFLAGS) $(SRC_SERVER_BONUS) -o $(NAME_SERVER_BONUS)

clean:
	@rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	@echo "🗑️ $(YELLOW)Cleaned up!$(RESET)"

fclean: clean
	@echo "🚮 $(RED)Full cleanup done!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
