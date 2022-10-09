##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

SRC			=	main.c

CC			=	gcc

CFLAGS		=	-lm -Llib -lmy -Iinclude -g -lncurses

OBJS		=	$(SRC:.c=.o)
EXEC 		=	my_sokoban

all: ${EXEC}

${EXEC}: ${OBJS}
	$(MAKE) -C lib/my
	${CC}  -o ${EXEC} ${OBJS} ${CFLAGS}

clean:
	rm -f ${OBJS}
	make -C lib/my clean

fclean: clean
	rm -f ${EXEC}
	make -C lib/my fclean

re: fclean all
