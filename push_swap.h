/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:41:00 by donheo            #+#    #+#             */
/*   Updated: 2025/05/08 23:53:27 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_info
{
	int			*array;
	size_t		num_count;
	int			size_a;
	int			size_b;
	t_number	*top_a;
	t_number	*bottom_a;
	t_number	*top_b;
	t_number	*bottom_b;
}	t_info;

void	print_error(int error_num);
t_info	*init_info(size_t num_count);
int		main(int argc, char **argv);

int		is_int(char	*str);
int		ft_strcmp(char *s1, char *s2);
int		compare_numbers(char **numbers);
int		validate_and_count_numbers(char **argv);
void	validate_numbers_for_args(int argc, char **argv);
int		get_total_numbers(int argc, char **argv);

void	save_args_in_array(char **argv, size_t num_count, int *num_array);
void	save_an_arg_in_array(char *str, int *num_array);
int		*save_nums_in_array(int argc, char **argv, size_t num_count);
void	save_numbers_in_stack(int *num_array, t_info *info);

void	sort_array(int *num_array, t_info *info);

void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info*info);
void	pb(t_info*info);
void	ra(t_info*info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);
void	rotate_down(t_number **top, t_number **bottom);
#endif
