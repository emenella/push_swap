GCC := gcc -Wall -Wextra -Werror
SRC := ./srcs/swap.c ./srcs/push.c ./srcs/rotate.c ./srcs/utils.c ./srcs/list.c ./srcs/ft_atoi.c ./srcs/get_next_line.c ./srcs/sort.c ./srcs/reverse_rotate.c ./srcs/lst.c ./srcs/cmd.c
SRCCHECK := ./srcs/checker.c
SRCPUSHSWAP := ./srcs/push_swap.c
PUSHSWAP := push_swap
CHECKER := checker
OBJ=$(SRC:.c=.o)
OBJPUSHSWAP=$(SRCPUSHSWAP:.c=.o)
OBJBCHECK=$(SRCCHECK:.c=.o)

all: $(CHECKER) $(PUSHSWAP)

$(PUSHSWAP): $(OBJ) $(OBJPUSHSWAP)
		$(GCC) -o $(PUSHSWAP) $(OBJ) $(OBJPUSHSWAP)

$(CHECKER): $(OBJ) $(OBJBCHECK)
		$(GCC) -o $(CHECKER) $(OBJ) $(OBJBCHECK)

%.o: %.c
		$(GCC) -o $@ -c $<

clean:
		rm -f $(OBJ) $(OBJBCHECK) $(OBJPUSHSWAP)

fclean:
		rm -f $(PUSHSWAP) $(CHECKER) $(OBJ) $(OBJBCHECK) $(OBJPUSHSWAP)

re: fclean all