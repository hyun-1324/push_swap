/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:39:45 by donheo            #+#    #+#             */
/*   Updated: 2025/05/09 13:55:56 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int error_num)
{
	if (error_num == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	exit(0);
}

t_info	*init_info(size_t num_c)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		print_error(1);
	info->array = NULL;
	info->size_a = num_c;
	info->size_b = 0;
	info->num_count = num_c;
	info->top_a = NULL;
	info->bottom_a = NULL;
	info->top_b = NULL;
	info->bottom_b = NULL;
	return (info);
}

int	get_total_numbers(int argc, char **argv)
{
	size_t	num_count;

	if (argc == 2)
		num_count = validate_and_count_numbers(argv);
	else
	{
		validate_numbers_for_args(argc, argv);
		num_count = argc - 1;
	}
	return (num_count);
}

int	main(int argc, char **argv)
{
	size_t	num_count;
	int		*num_array;
	t_info	*info;

	if (argc < 2)
		print_error(0);
	num_count = get_total_numbers(argc, argv);
	num_array = save_nums_in_array(argc, argv, num_count);
	info = init_info(num_count);
	save_numbers_in_stack(num_array, info);
	sort_array(num_array, info);
	sort_list(info);
	free(info->array);
	ft_lstclear(&(info->top_a));
	free(info);
	return (0);
}
