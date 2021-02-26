/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:30:22 by ade-garr          #+#    #+#             */
/*   Updated: 2021/02/26 15:48:10 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_do_dup_parent(void)
{

}

void    ft_do_dup_child(void)
{
    if (close(g_shell->pipefd[1] == -1)
        ft_error();
    if (dup2(0, g_shell->pipefd[0]) == -1)
        ft_error();
    g_shell->tmp = g_shell->tmp->next;
    ft_process_cmd();
}

void    ft_do_pipes(void)
{
    int i;

    if (g_shell->tmp->cmdinfo->i == 1)
    {
        i = pipe(g_shell->pipefd);
        if (i == -1)
            ft_error();
        g_shell->pid_pipe = fork();
        if (g_shell->pid_pipe == -1)
            ft_error();
        if (g_shell->pid_pipe == 0)
            ft_do_dup_child();
        else
            ft_do_dup_parent();
    }
}

void    ft_process_cmd(void)
{
    ft_do_pipes();
}

void    ft_exec_cmd(void)
{
    int oldstdout;
    int oldstdin;

    g_shell->tmp = g_shell->cmd;
    oldstdout = dup(1);
    if (oldstdout == -1)
        ft_error();
    oldstdin = dup(0);
    if (oldstdin == -1)
        ft_error();
    while (tmp != NULL)
    {
        ft_process_cmd(void);
    }
    if (dup2(1, oldstdout) == -1)
        ft_error();
    if (dup2(0, oldstdin) == -1
        ft_error();
}