/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:13:08 by donheo            #+#    #+#             */
/*   Updated: 2025/05/09 11:48:55 by donheo           ###   ########.fr       */
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
