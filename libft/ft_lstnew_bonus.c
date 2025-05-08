/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:40:19 by donheo            #+#    #+#             */
/*   Updated: 2025/05/08 14:54:43 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_number	*ft_lstnew(int content)
{
	t_number	*new;

	new = (t_number *)malloc(sizeof(t_number));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
