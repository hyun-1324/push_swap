NAME = push_swap

SRCS	=  ft_split.c helper_func.c helper_func2.c data_validation.c \
		  main.c operations1.c operations2.c operations3.c\
		  sort_by_pivot.c sort_greedy.c sort_utils.c save_numbers.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.SECONDARY: $(OBJS)
all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
