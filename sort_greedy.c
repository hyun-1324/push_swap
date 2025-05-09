/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:23:30 by donheo            #+#    #+#             */
/*   Updated: 2025/05/09 21:24:02 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_insert_pos_a(int num, t_info *info)
{
	t_number	*tmp;
	int			i;
	int			next;

	i = 0;
	tmp = info->top_a;
	while (tmp)
	{
		if (tmp->next)
			next = tmp->next->content;
		else
			next = info->top_a->content;
		if ((num > tmp->content && num < next) ||
			(tmp->content > next && (num > tmp->content || num < next)))
			break;
		tmp = tmp->next;
		i++;
	}
	if (i + 1 >= (int)(info->size_a + 1) / 2)
		return ((int)info->size_a - (i + 1)) * -1;
	return (i + 1);
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

void	perform_joint_rotation(t_info *info, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(info);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(info);
		*a = *a + 1;
		*b = *b + 1;
	}
}
