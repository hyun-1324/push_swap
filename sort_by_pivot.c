/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:13:08 by donheo            #+#    #+#             */
/*   Updated: 2025/05/10 09:49:56 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_three_biggest_nums(t_info *info)
{
	while (info->size_a > 3)
	{
		if (info->top_a->index >= info->num_count - 3)
			ra(info);
		else
			pb(info);
	}
}

void	push_by_pivot(t_info *info)
{
	int		pivot1;
	int		pivot2;
	size_t	i;

	pivot1 = (info->array)[info->num_count / 3 - 1];
	pivot2 = (info->array)[info->num_count * 2 / 3 - 1];
	i = 0;
	while (i < info->num_count)
	{
		if (info->top_a->content < pivot1)
		{
			pb(info);
			rb(info);
		}
		else if (info->top_a->content < pivot2)
			pb(info);
		else
			ra(info);
		i++;
	}
	choose_three_biggest_nums(info);
}

void	rotate_a(t_info *info, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(info);
			a--;
		}
		else
		{
			rra(info);
			a++;
		}
	}
}

void	rotate_b(t_info *info, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(info);
			b--;
		}
		else
		{
			rrb(info);
			b++;
		}
	}
}
