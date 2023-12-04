##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile
##

OUT = corewar
COMP = gcc
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c $(SRC_DIR)/*/*/*.c \
	$(SRC_DIR)/*/*/*/*.c $(SRC_DIR)/*/*/*/*/*.c)
OBJ = $(SRC:.c=.o)
COMP_FLAGS = -Wall -Wextra -L ../lib/my -lmy -I ./include -I ../lib/my/include \
		-lm -ffast-math -O3 -Wno-unused-parameter -Wno-unused-result \

all: $(OUT)

%.o : %.c
	@ $(COMP) -o $@ -c $< $(COMP_FLAGS) && echo "\e[0;32mDone: \e[0;37m$<\
	 -> $@\e[0m" || echo "\e[0;31mError : \e[0;37m$< -> $@\n\e[0m"

LIB:
	@ make -C ../lib/my --no-print-directory

$(OUT): LIB $(OBJ)
	@ $(COMP) -o $(OUT) $(OBJ) $(COMP_FLAGS) -Llib -lmy && echo "\e[0;32m\
	\nProcess completed, executable name: \e[0;35m$(OUT)\e[0m" || echo "\e\
	[0;31m\nError during the process !\e[0m"

run: $(OUT)
	@ echo "\e[0;32mRunning \e[0;35m$(OUT)\e[0;32m...\n\e[0m"
	@ ./$(OUT)

clean:
	@ make clean -C ../lib/my --no-print-directory
	@ rm -f $(OBJ) *.gcno *.gcda && \
	echo "\e[0;32mCleaned !\n\e[0m" || \
	echo "\e[0;31mError during the process !\n\e[0m"

fclean:
	@ make clean --no-print-directory
	@ make -C ../lib/my fclean --no-print-directory
	@ rm -f $(OUT) *.g* && \
	echo "\e[0;32mExecutable deleted\n\e[0m" || \
	echo "\e[0;31mError during the process !\n\e[0m"

re: fclean $(OUT)

-include $(OBJ:.o=.d)

debug:
	@ $(COMP) -o $(OUT) $(SRC) $(COMP_FLAGS) -g -Llib -lmy && \
	echo "\e[0;32m\nProcess completed, executable name: \e[0;35m$(OUT)\e[0m" \
	|| echo "\e[0;31m\nError during the process !\e[0m"

.PHONY: all clean fclean re debug cstyle check_banned
