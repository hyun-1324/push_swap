/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_numbers_in_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:36:12 by donheo            #+#    #+#             */
/*   Updated: 2025/05/08 15:38:10 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_numbers_in_stack(int *num_array, t_info *info, int total_numbers)
{
	int			i;
	t_number	*initial;
	t_number	*new;
	t_number	*new2;

	i = 0;
	info->array = num_array;
	info->size_a = total_numbers;
	initial = ft_lstnew(num_array[i]);
	if (!initial)
	{
		free(num_array);
		free(info);
		print_error(1);
	}
	info->top_a = initial;
	i++;
	new = initial;
	while (i < total_numbers)
	{
		new2 = ft_lstnew(num_array[i]);
		if (!new2)
		{
			free(num_array);
			free(info);
			ft_lstclear(&initial);
			print_error(1);
		}
		ft_lstadd_back(&new, new2);
		new = new2;
		i++;
	}
	info->bottom_a = new;
}
