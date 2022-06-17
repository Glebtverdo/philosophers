NAME  = philo_bonus

PHILO = ./main.c\
\
./utils/free_all.c ./utils/dead_cheker.c\
./utils/utils.c ./utils/make_sem_name.c\
\
./parser/parser.c\
./philos_logic/philos_init.c ./philos_logic/philos_start.c\
\
./time_funcs/time_funcs.c\

OBJS  = ${PHILO:.c=.o}
DEPS = ${PHILO:.c=.d}
CC   = gcc

CFLAGS  = -Werror -Wextra -Wall -MMD 

all:  $(NAME)

-include $(DEPS)

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I.

$(NAME) : ${OBJS} Makefile
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

bonus: all

clean:
	rm -f ${OBJS}
	
fclean: clean
	rm -f $(NAME)
	rm -f $(DEPS)
	rm -f libft.so

re :  fclean all

.PHONY:  all clean fclean re .c.o test