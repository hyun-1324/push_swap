NAME = push_swap

SRCS	=   src/main.c \
			src/parse/parse_input.c \
			src/parse/data_validation.c \
			src/stack/stack_ops.c \
			src/stack/stack_rotate.c \
			src/stack/stack_reverse.c \
			src/sort/sort_by_pivot.c \
			src/sort/sort_greedy.c \
			src/sort/sort_utils.c \
			src/utils/ft_split.c \
			src/utils/common_utils.c \
			src/utils/common_utils2.c

OBJS = $(SRCS:.c=.o)

INCLUDE = -Iinclude

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.SECONDARY: $(OBJS)
all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
