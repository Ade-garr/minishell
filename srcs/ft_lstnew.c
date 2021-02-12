/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:39:28 by ade-garr          #+#    #+#             */
/*   Updated: 2021/02/12 21:03:48 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*begin;

	if (!(begin = malloc(sizeof(t_list) * 1)))
		return (NULL);
	begin->content = content;
	begin->next = 0;
	return (begin);
}
