SHELL = /bin/bash

CC = c++ -Wall -Wextra -Werror -std=c++98

NAME = 

SRC = *.cpp

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) -o $(NAME)
	@echo -n "  Compiling"
	@$(MAKE) -s loading
	@clear
	@echo -e "\033[32m ✓ \033[0m Compilation successful!"


clean:
	@rm -rf $(NAME)

fclean: clean
	@echo -n "  Cleaning"
	@$(MAKE) -s loading
	@rm -f $(NAME)
	@echo -e "\033[32m ✓ \033[0m Clean complete!"

re: fclean all

loading:
	@spin=("⠁" "⠃" "⠇" "⠧" "⠷" "⠿" "⠷" "⠧" "⠇" "⠃"); \
	for i in {1..1}; do \
		for j in $${spin[@]}; do \
			echo -ne "$$j\r"; \
			sleep 0.1; \
		done; \
	done

.PHONY:	all clean fclean re