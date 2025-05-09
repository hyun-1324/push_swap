/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:13:08 by donheo            #+#    #+#             */
/*   Updated: 2025/05/09 01:49:05 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void sort_three(t_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->top_a->content;
	b = info->top_a->next->content;
	c = info->top_a->next->next->content;
	if (a > b && b < c && a < c)
		sa(info);
	else if (a > b && b > c && a > c)
	{
		sa(info);
		rra(info);
	}
	else if (a > b && b < c && a > c)
		ra(info);
	else if (a < b && b > c && a < c)
	{
		sa(info);
		ra(info);
	}
	else if (a < b && b > c && a > c)
		rra(info);
}

void sort_two(t_info *info)
{
	if (info->top_a->content > info->bottom_a->content)
		sa(info);
}
