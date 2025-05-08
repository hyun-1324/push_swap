#include "push_swap.h"
#include "libft/libft.h"

void	print_error(int error_num)
{
	if (error_num == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	exit(0);
}

t_info	*init_info(void)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		print_error(1);
	info->array = NULL;
	info->size_a = 0;
	info->top_a = NULL;
	info->bottom_a = NULL;
	info->size_b = 0;
	info->top_b = NULL;
	info->bottom_b = NULL;
	return (info);
}

int	is_number(char	*str)
{
	int	i;

	i = 0;
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
	int	len1;
	int	len2;

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
	int	i;
	int	is_valid_num;

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
	int		total_numbers;
	int		is_valid_num;
	char	**numbers;

	is_valid_num = 1;
	total_numbers = 0;
	numbers = ft_split(argv[1], ' ');
	if (!numbers)
		print_error(1);
	is_valid_num = compare_numbers(numbers);
	while (numbers[total_numbers])
	{
		if (is_valid_num)
			is_valid_num = is_number(numbers[total_numbers]);
		free(numbers[total_numbers]);
		total_numbers++;
	}
	free(numbers);
	if (!is_valid_num)
		print_error(1);
	return (total_numbers);
}


void	validate_numbers_for_args(int argc, char **argv)
{
	int	i;
	int	is_valid_num;
	int	j;

	is_valid_num = 1;
	i = argc - 1;
	while (i - 1>= 0)
	{
		is_valid_num = is_number(argv[i--]);
		if (!is_valid_num)
			print_error(1);
	}
	i = 0;
	while (i < argc - 2)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			is_valid_num = ft_strcmp(argv[i], argv[j]);
			if (!is_valid_num)
				print_error(1);
			j++;
		}
		i++;
	}
}


int	get_total_numbers(int argc, char **argv)
{
	int	total_numbers;

	if (argc == 2)
		total_numbers = validate_and_count_numbers(argv);
	else
	{
		validate_numbers_for_args(argc, argv);
		total_numbers = argc - 1;
	}
	return (total_numbers);
}

int	main(int argc, char **argv)
{
	int		total_numbers;
	// int		*num_array;
	t_info	*info;

	if (argc < 2)
		print_error(0);
	info = init_info();
	total_numbers = get_total_numbers(argc, argv);



	free(info);
	return (0);
}
