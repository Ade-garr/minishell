/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:53:42 by ade-garr          #+#    #+#             */
/*   Updated: 2021/04/17 17:02:11 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redirect_to(void)
{
	
}

void	ft_do_redirections(void)
{
	g_shell->tmpdir = ((t_cmd *)g_shell->tmp_cmd->content)->rdir_lst;
	while (g_shell->tmpdir != NULL)
	{
		if (((t_rdir *)g_shell->tmpdir->content)->flagdir == 1)
		{
			ft_redirect_to();
		}
		else if (((t_rdir *)g_shell->tmpdir->content)->flagdir == 3)
		{
			ft_redirect_to_append();
		}
		else if (((t_rdir *)g_shell->tmpdir->content)->flagdir == 2)
		{
			ft_redirect_from();
		}
	}
}