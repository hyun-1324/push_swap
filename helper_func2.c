/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:53:45 by donheo            #+#    #+#             */
/*   Updated: 2025/05/09 11:54:15 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_lstadd_back(t_number **lst, t_number *new)
{
	t_number	*current;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}
