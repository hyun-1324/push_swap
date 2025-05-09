/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:21:56 by donheo            #+#    #+#             */
/*   Updated: 2025/05/09 01:17:21 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_down(t_number **top, t_number **bottom)
{
	t_number	*prev;
	t_number	*last;

	prev = *top;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *top;
	*top = last;
	*bottom = prev;
}

void	rra(t_info *info)
{
	if (info->size_a < 2)
		return ;
	rotate_down(&info->top_a, &info->bottom_a);
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	if (info->size_b < 2)
		return ;
	rotate_down(&info->top_b, &info->bottom_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	if (info->size_a > 1)
		rotate_down(&info->top_a, &info->bottom_a);
	if (info->size_b > 1)
		rotate_down(&info->top_b, &info->bottom_b);
	write(1, "rrr\n", 4);
}
