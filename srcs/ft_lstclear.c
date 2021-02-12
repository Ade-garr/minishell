/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:54:12 by ade-garr          #+#    #+#             */
/*   Updated: 2021/02/12 21:03:37 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;

	if (!lst)
		return ;
	while ((*lst))
	{
		if (del != NULL)
			del((*lst)->content);
		t = *lst;
		*lst = (*lst)->next;
		free(t);
	}
}
