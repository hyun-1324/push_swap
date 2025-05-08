/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:21:56 by donheo            #+#    #+#             */
/*   Updated: 2025/05/08 23:40:27 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_info *info)
{
	t_number	*prev;
	t_number	*last;

	if (info->size_a < 2)
		return ;
	prev = info->top_a;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = info->top_a;
	info->top_a = last;
	info->bottom_a = prev;
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	t_number	*prev;
	t_number	*last;

	if (info->size_b < 2)
		return ;
	prev = info->top_b;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = info->top_b;
	info->top_b = last;
	info->bottom_b = prev;
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	t_number	*prev;
	t_number	*last;

	if (info->size_a > 1)
	{
		prev = info->top_a;
		while (prev->next && prev->next->next)
			prev = prev->next;
		last = prev->next;
		prev->next = NULL;
		last->next = info->top_a;
		info->top_a = last;
		info->bottom_a = prev;
	}
	if (info->size_b > 1)
	{
		prev = info->top_b;
		while (prev->next && prev->next->next)
			prev = prev->next;
		last = prev->next;
		prev->next = NULL;
		last->next = info->top_b;
		info->top_b = last;
		info->bottom_b = prev;
	}
	write(1, "rrr\n", 4);
}
