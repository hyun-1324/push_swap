/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:53:05 by donheo            #+#    #+#             */
/*   Updated: 2025/05/08 23:45:28 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	t_number	*tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->top_a->next;
	info->top_a->next = info->top_a->next->next;
	tmp->next = info->top_a;
	info->top_a = tmp;
	write(1, "sa\n", 3);
}
void	sb(t_info *info)
{
	t_number	*tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->top_b->next;
	info->top_b->next = info->top_b->next->next;
	tmp->next = info->top_b;
	info->top_b = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_info *info)
{
	t_number	*tmp;

	if (info->size_a > 1)
	{
		tmp = info->top_a->next;
		info->top_a->next = info->top_a->next->next;
		tmp->next = info->top_a;
		info->top_a = tmp;
	}
	if (info->size_b > 1)
	{
		tmp = info->top_b->next;
		info->top_b->next = info->top_b->next->next;
		tmp->next = info->top_b;
		info->top_b = tmp;
	}
	write(1, "ss\n", 3);
}

void	pa(t_info*info)
{
	t_number	*tmp;

	if (info->size_b < 1)
		return ;
	tmp = info->top_b;
	info->top_b = info->top_b->next;
	if (info->size_a == 0)
	{
		tmp->next = NULL;
		info->top_a = tmp;
		info->bottom_a = tmp;
	}
	else
	{
		tmp->next = info->top_a;
		info->top_a = tmp;
	}
	info->size_a += 1;
	info->size_b -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_info*info)
{
	t_number	*tmp;

	if (info->size_a < 1)
		return ;
	tmp = info->top_a;
	info->top_a = info->top_a->next;
	if (info->size_b == 0)
	{
		tmp->next = NULL;
		info->top_b = tmp;
		info->bottom_b = tmp;
	}
	else
	{
		tmp->next = info->top_b;
		info->top_b = tmp;
	}
	info->size_b += 1;
	info->size_a -= 1;
	write(1, "pb\n", 3);
}
