/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:30:22 by ade-garr          #+#    #+#             */
/*   Updated: 2021/02/26 11:34:25 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void       ft_do_pipes(void)
{
    int i;

    if (g_shell->cmdinfo->i == 1)
    {
        i = pipe(g_shell->pipefd);
        if (i == -1)
            ft_error();
        g_shell->pid_pipe = fork();
        if (g_shell->pid_pipe == -1)
            ft_error();

    }
}

void    ft_process_cmd(void)
{
    ft_do_pipes();
}

void    ft_exec_cmd(void)
{
    t_list  *tmp;

    tmp = g_shell->cmd;
    while (tmp != NULL)
    {
        ft_process_cmd(void);
    }
}