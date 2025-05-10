/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:41:00 by donheo            #+#    #+#             */
/*   Updated: 2025/05/10 10:11:42 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_number
{
	int				content;
	size_t			index;
	struct s_number	*next;
}	t_number;

typedef struct s_info
{
	int			*array;
	size_t		num_count;
	size_t		size_a;
	size_t		size_b;
	t_number	*top_a;
	t_number	*bottom_a;
	t_number	*top_b;
	t_number	*bottom_b;
}	t_info;

void		print_error(int error_num);
t_info		*init_info(size_t num_c);
int			main(int argc, char **argv);

int			is_int(char	*str);
int			ft_strcmp(char *s1, char *s2);
int			compare_numbers(char **numbers);
int			validate_and_count_numbers(char **argv);
void		validate_numbers_for_args(int argc, char **argv);
int			get_total_numbers(int argc, char **argv);

void		save_args_in_array(char **argv, size_t num_count, int *num_array);
void		save_an_arg_in_array(char *str, int *num_array);
int			*save_nums_in_array(int argc, char **argv, size_t num_count);
void		save_numbers_in_stack(int *num_array, t_info *info);
void		sort_array(int *num_array, t_info *info);
void		get_index_from_value(int *sorted_a, t_info *info);

void		choose_three_biggest_nums(t_info *info);
void		push_by_pivot(t_info *info);
int			find_insert_pos_a(int num, t_info *info);
int			is_better_move(int a, int b, int new_a, int new_b);
void		get_best_rotate(t_info *info, int *a_steps, int *b_steps);
void		perform_joint_rotation(t_info *info, int *a, int *b);
void		rotate_a(t_info *info, int a);
void		rotate_b(t_info *info, int b);
void		rotate_a_to_min(t_info *info);
void		is_sorted(t_info *info);
void		sort_three(t_info *info);
void		sort_two(t_info *info);
void		sort_list(t_info *info);

void		sa(t_info *info);
void		sb(t_info *info);
void		ss(t_info *info);
void		pa(t_info*info);
void		pb(t_info*info);
void		ra(t_info*info);
void		rb(t_info *info);
void		rr(t_info *info);
void		rra(t_info *info);
void		rrb(t_info *info);
void		rrr(t_info *info);
void		rotate_down(t_number **top, t_number **bottom);

char		**ft_split(char const *s, char c);
long		ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dsize);
t_number	*ft_lstnew(int content);
void		ft_lstclear(t_number **lst);
void		ft_lstadd_back(t_number **lst, t_number *new);

#endif
