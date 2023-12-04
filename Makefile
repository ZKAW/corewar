##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile
##

CC	= gcc
OBJ	= $(SRC:.c=.o)
LIBFLAG	= -Wall -Wextra -L ./lib/my -lmy -I ./include
MAKEFLAGS += --no-print-directory

AUTHORIZED_FUNCS = fopen,open,fread,read,fwrite,write,lseek,fseek,fclose, \
close,malloc,realloc,free,exit,getline,PASS_ARGS,GET_PARAM_BYTE,func, \
SWAP_UINT16

all:
	@make -C ./corewar/
	@make -C ./asm/

clean:
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C ./corewar/
	@make fclean -C ./asm/
	@rm -f ./corewar/corewar
	@rm -f ./asm/asm

tests_run:
	@make re
	@cd tests && ./tester.sh

tests_run_win:
	@make re
	@cd tests && ./tester.sh -L

check_banned:
	@python3 ./tests/ban_checker.py -a "$(AUTHORIZED_FUNCS)" .

check_banned_git:
	@python3 ./tests/ban_checker.py --github-actions -a "$(AUTHORIZED_FUNCS)" .

cstyle:
	@make fclean
	@cstyle
	@echo ""
	@make check_banned -i

re: fclean all

debug:
	@make -C ./corewar/ debug
	@make -C ./asm/ debug

.PHONY: all clean fclean re debug cstyle check_banned check_banned_git tests_run
