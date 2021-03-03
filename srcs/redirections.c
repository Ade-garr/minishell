/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:53:42 by ade-garr          #+#    #+#             */
/*   Updated: 2021/03/03 20:16:15 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_do_redirections(void)
{
	(t_cmdinfo *)(g_shell->tmp->content)->tmpdir = 
	(t_cmdinfo *)(g_shell->tmp->content)->dir;
	while ((t_cmdinfo *)(g_shell->tmp->content)->tmpdir != NULL)
	{
		if ((t_dirinfo *)((t_cmdinfo *)(g_shell->tmp->content)->tmpdir->
		content)->flagdir == 0)
		{
			ft_redirect_to();
		}
		else if ((t_dirinfo *)((t_cmdinfo *)(g_shell->tmp->content)->tmpdir->
		content)->flagdir == 1)
		{
			ft_redirect_to_append();
		}
		else if ((t_dirinfo *)((t_cmdinfo *)(g_shell->tmp->content)->tmpdir->
		content)->flagdir == 2)
		{
			ft_redirect_from();
		}
	}
}