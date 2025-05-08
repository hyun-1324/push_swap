/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:22:18 by donheo            #+#    #+#             */
/*   Updated: 2025/05/08 15:21:10 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_number **lst)
{
	t_number	*cur;

	while (*lst)
	{
		cur = *lst;
		*lst = (*lst)->next;
		free(cur);
	}
	*lst = NULL;
}
