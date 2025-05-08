/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:53:08 by donheo            #+#    #+#             */
/*   Updated: 2025/05/08 23:39:36 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info*info)
{
	t_number	*tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->bottom_a->next = tmp;
	info->bottom_a = tmp;
	info->bottom_a->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	t_number	*tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->top_b;
	info->top_b = info->top_b->next;
	info->bottom_b->next = tmp;
	info->bottom_b = tmp;
	info->bottom_b->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	t_number	*tmp;

	if (info->size_a > 1)
	{
		tmp = info->top_a;
		info->top_a = info->top_a->next;
		info->bottom_a->next = tmp;
		info->bottom_a = tmp;
		info->bottom_a->next = NULL;
	}
	if (info->size_b > 1)
	{
		tmp = info->top_b;
		info->top_b = info->top_b->next;
		info->bottom_b->next = tmp;
		info->bottom_b = tmp;
		info->bottom_b->next = NULL;
	}
	write(1, "rr\n", 3);
}


