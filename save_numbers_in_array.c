/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:04:25 by donheo            #+#    #+#             */
/*   Updated: 2025/05/08 14:35:10 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_args_in_array(char **argv, int total_numbers, int *num_array)
{
	int	i;

	i = 1;
	while(i < total_numbers + 1)
	{
		num_array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
}

void	save_an_arg_in_array(char *str, int *num_array)
{
	char	**num_string;
	int		i;

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

int	*save_nums_in_array(int argc, char **argv, int total_numbers)
{
	int	*num_array;

	num_array = malloc(total_numbers * sizeof(int));
	if (!num_array)
		print_error(1);
	if (argc == 2)
		save_an_arg_in_array(argv[1], num_array);
	else
		save_args_in_array(argv, total_numbers, num_array);
	return (num_array);
}
