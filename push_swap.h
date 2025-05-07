#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_number
{
	int				content;
	struct s_number	*next;
}	t_number;

typedef struct s_info
{
	int			*array;
	int			size_a;
	t_number	*top_a;
	t_number	*bottom_a;
	int			size_b;
	t_number	*top_b;
	t_number	*bottom_b;
}	t_info;

#endif
