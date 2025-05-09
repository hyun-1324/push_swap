/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:44:19 by donheo            #+#    #+#             */
/*   Updated: 2025/05/09 13:03:55 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_info *info)
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

void	sort_two(t_info *info)
{
	if (info->top_a->content > info->bottom_a->content)
		sa(info);
}

void	is_sorted(t_info *info)
{
	size_t		i;
	t_number	*num_to_check;

	i = 0;
	num_to_check = info->top_a;
	while (i < info->num_count)
	{
		if ((info->array)[i] != num_to_check->content)
			return ;
		i++;
		num_to_check = num_to_check->next;
	}
	free(info->array);
	return (ft_lstclear(&info->top_a), free(info), print_error(0));
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
