NAME		=	philo
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g 
#-fsanitize=thread

SRCS		=	src/philo.c\
				src/philo_utils.c\
				src/timer.c\
				src/parsing.c\
				src/routine.c\
				src/ft_atoi.c\

OBJS		=	$(SRCS:.c=.o)

all		: 	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) -o $(NAME) $(FLAGS) $(OBJS) -lpthread 

%.o		:	%.c
			$(CC) $(FLAGS) -o $@ -c $<

clean	:	
				rm -rf $(OBJS)

fclean	:	clean
				rm -rf $(NAME)

re		:	fclean all

r:
	make re && clear && ./philo 4 410 200 200
.PHONY	:	all clean fclean re

#5 800 200 200 7 | grep "2 is eating" | wc -l
#tenho de rever os tempos para 4 410 200 200
