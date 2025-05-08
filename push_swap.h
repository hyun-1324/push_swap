/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:41:00 by donheo            #+#    #+#             */
/*   Updated: 2025/05/08 11:41:01 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

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

void	print_error(int error_num);
t_info	*init_info(void);
int		is_number(char	*str);
int		ft_strcmp(char *s1, char *s2);
int		compare_numbers(char **numbers);
int		validate_and_count_numbers(char **argv);
void	validate_numbers_for_args(int argc, char **argv);
int		get_total_numbers(int argc, char **argv);
int		main(int argc, char **argv);
#endif
