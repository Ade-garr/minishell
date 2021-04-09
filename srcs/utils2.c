/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:58:56 by ade-garr          #+#    #+#             */
/*   Updated: 2021/04/09 19:47:07 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(void)
{
	printf("%s\r\n", strerror(errno));
	ft_exit();
}

char	*ft_get_history(void)
{
	t_list	*tmp_lst;
	int		i;

	i = g_shell->nb_hist;
	tmp_lst = g_shell->hist;
	while (ft_lstsize(g_shell->hist) - i > 0)
	{
		tmp_lst = tmp_lst->next;
		i++;
	}
	return ((char *)tmp_lst->content);
}