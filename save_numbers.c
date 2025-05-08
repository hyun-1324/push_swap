/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:04:25 by donheo            #+#    #+#             */
/*   Updated: 2025/05/08 23:03:04 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_args_in_array(char **argv, size_t num_count, int *num_array)
{
	size_t	i;

	i = 1;
	while (i < num_count + 1)
	{
		num_array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
}

void	save_an_arg_in_array(char *str, int *num_array)
{
	char		**num_string;
	size_t		i;

	num_string = ft_split(str, ' ');
	if (!num_string)
	{
		free(num_array);
		print_error(1);
	}
	i = 0;
	while (num_string[i])
	{
		num_array[i] = ft_atoi(num_string[i]);
		free(num_string[i]);
		i++;
	}
	free(num_string);
}

int	*save_nums_in_array(int argc, char **argv, size_t num_count)
{
	int	*num_array;

	num_array = malloc(num_count * sizeof(int));
	if (!num_array)
		print_error(1);
	if (argc == 2)
		save_an_arg_in_array(argv[1], num_array);
	else
		save_args_in_array(argv, num_count, num_array);
	return (num_array);
}

void	save_numbers_in_stack(int *num_array, t_info *info)
{
	size_t		i;
	t_number	*initial;
	t_number	*new;
	t_number	*new2;

	i = 0;
	initial = ft_lstnew(num_array[i]);
	if (!initial)
		return (free(num_array), free(info), print_error(1));
	info->top_a = initial;
	i++;
	new = initial;
	while (i < info->num_count)
	{
		new2 = ft_lstnew(num_array[i]);
		if (!new2)
			return (free(num_array), free(info), \
			ft_lstclear(&initial), print_error(1));
		ft_lstadd_back(&new, new2);
		new = new2;
		i++;
	}
	info->bottom_a = new;
	info->size_a = info->num_count;
}

void	sort_array(int *num_array, t_info *info)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < info->num_count)
	{
		j = 0;
		while (j < info->num_count -1)
		{
			if (num_array[j] > num_array[j + 1])
			{
				tmp = num_array[j];
				num_array[j] = num_array[j + 1];
				num_array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	info->array = num_array;
}
