/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:39:50 by donheo            #+#    #+#             */
/*   Updated: 2025/05/10 09:36:36 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char	*str)
{
	int		i;
	long	num;

	i = 0;
	num = ft_atoi(str);
	if (num < INT_MIN || INT_MAX < num)
		return (0);
	if ((str[0] == '+' || str[0] == '-') && (str[1] >= '1' && str[1] <= '9'))
		i++;
	else if ((str[0] >= '1' && str[0] <= '9'))
		i++;
	else if (((str[0] == '+' || str[0] == '-') && (str[1] >= '0') && \
	!str[2]) || (str[0] == '0' && !str[1]))
		return (1);
	else
		return (0);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		i++;
	}
	if (str[i])
		return (0);
	else
		return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 != len2)
		return (1);
	if (ft_strncmp(s1, s2, len1) == 0)
		return (0);
	return (1);
}

int	compare_numbers(char **numbers)
{
	size_t	i;
	int		is_valid_num;

	i = 1;
	is_valid_num = 1;
	while (numbers[i] && numbers[i + 1])
	{
		is_valid_num = ft_strcmp(numbers[i], numbers[i + 1]);
		if (is_valid_num == 0)
			return (is_valid_num);
		i++;
	}
	return (is_valid_num);
}

int	validate_and_count_numbers(char **argv)
{
	size_t	num_count;
	int		is_valid_num;
	char	**numbers;

	is_valid_num = 1;
	num_count = 0;
	if (!ft_memcmp(argv[1], " ", 2) || !ft_memcmp(argv[1], "", 1))
		print_error(1);
	numbers = ft_split(argv[1], ' ');
	if (!numbers)
		print_error(1);
	is_valid_num = compare_numbers(numbers);
	while (numbers[num_count])
	{
		if (is_valid_num)
			is_valid_num = is_int(numbers[num_count]);
		free(numbers[num_count]);
		num_count++;
	}
	free(numbers);
	if (!is_valid_num)
		print_error(1);
	return (num_count);
}

void	validate_numbers_for_args(int argc, char **argv)
{
	int	i;
	int	is_valid_num;
	int	j;

	is_valid_num = 1;
	i = argc - 1;
	while (i >= 1)
	{
		is_valid_num = is_int(argv[i--]);
		if (!is_valid_num)
			print_error(1);
	}
	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			is_valid_num = ft_strcmp(argv[i], argv[j]);
			if (!is_valid_num)
				print_error(1);
			j++;
		}
		i++;
	}
}
