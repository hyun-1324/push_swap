/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:23:30 by donheo            #+#    #+#             */
/*   Updated: 2025/05/09 09:39:17 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_by_pivot(t_info *info)
{
	int		pivot1;
	int		pivot2;
	size_t	i;
	int		value;

	pivot1 = (info->array)[info->num_count / 3];
	pivot2 = (info->array)[info->num_count * 2 / 3];
	i = 0;
	value = info->top_a->content;
	while (i < info->num_count - 3)
	{
		value = info->top_a->content;
		if (value < pivot1)
		{
			pb(info);
			rb(info);
		}
		else if (value < pivot2)
			pb(info);
		else
			ra(info);
		i++;
	}
	while (info->size_a > 3)
		pb(info);
}

int	find_insert_pos_a(int num, t_info *info)
{
	t_number	*tmp;
	int			i;

	i = 0;
	tmp = info->top_a;
	while (tmp && tmp->content < num)
	{
		i++;
		tmp = tmp->next;
	}
	if (i >= ((int)info->size_a + 1) / 2)
		i = ((int)info->size_b - i) * (-1);
	return (i);
}

int	is_better_move(int a, int b, int new_a, int new_b)
{
	int	current_cost;
	int	new_cost;

	if (a * b > 0)
	{
		if (abs(a) > abs(b))
			current_cost = abs(a);
		else
			current_cost = abs(b);
	}
	else
		current_cost = abs(a) + abs(b);
	if (new_a * new_b > 0)
	{
		if (abs(new_a) > abs(new_b))
			new_cost = abs(new_a);
		else
			new_cost = abs(new_b);
	}
	else
		new_cost = abs(new_a) + abs(new_b);
	return (new_cost < current_cost);
}

void	get_best_rotate(t_info *info, int *a, int *b)
{
	int			insert_pos_in_a;
	int			steps_to_top_in_b;
	size_t		i;
	int			num;
	t_number	*stack_b;

	i = 0;
	stack_b = info->top_b;
	while (i < info->size_b)
	{
		num = stack_b->content;
		insert_pos_in_a = find_insert_pos_a(num, info);
		if (i >= (info->size_b + 1) / 2)
			steps_to_top_in_b = (info->size_b - i) * (-1);
		else
			steps_to_top_in_b = i;
		if (i == 0 || \
			is_better_move(*a, *b, insert_pos_in_a, steps_to_top_in_b))
		{
			*a = insert_pos_in_a;
			*b = steps_to_top_in_b;
		}
		stack_b = stack_b->next;
		i++;
	}
}

void	is_sorted(t_info *info)
{
	int			is_sorted;
	size_t		i;
	t_number	*num_to_check;

	is_sorted = 1;
	i = 0;
	num_to_check = info->top_a;
	while (i < info->num_count)
	{
		if ((info->array)[i] == num_to_check->content)
			is_sorted = 1;
		else
			is_sorted = 0;
		i++;
		num_to_check = num_to_check->next;
	}
	if (is_sorted)
		print_error(0);
}

void	rotate_a_to_min(t_info *info)
{
	size_t	i;

	i = 0;
	 while ((info->array)[i] > info->top_a->content)
		i++;
	 if (i > info->num_count / 2)
	 	while (info->top_a->content != (info->array)[0])
			ra(info);
	 else
		while (info->top_a->content != (info->array)[0])
			rra(info);
}

void	sort_list(t_info *info)
{
	int	a;
	int	b;

	is_sorted(info);
	if (info->num_count > 3)
	{
		push_by_pivot(info);
		sort_three(info);
		while (info->size_b)
		{
			a = 0;
			b = 0;
			get_best_rotate(info, &a, &b);
			perform_joint_rotation(info, &a, &b);
			rotate_a(info, a);
			rotate_b(info, b);
			pa(info);
		}
		rotate_a_to_min(info);
	}
	else if (info->num_count == 3)
		sort_three(info);
	else if (info->num_count == 2)
		sort_two(info);
}
