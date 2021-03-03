/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:30:22 by ade-garr          #+#    #+#             */
/*   Updated: 2021/03/03 15:53:25 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_do_dup_parent(void)
{
	if (close(g_shell->pipefd[0]) == -1)
		ft_error();
	if (dup2(g_shell->pipefd[1], 1) == -1)
		ft_error();
	if (close(g_shell->pipefd[1]) == -1)
		ft_error();
}

void	ft_do_dup_child(void)
{
	if (close(g_shell->pipefd[1]) == -1)
		ft_error();
	if (dup2(g_shell->pipefd[0], 0) == -1)
		ft_error();
	if (close(g_shell->pipefd[0]) == -1)
		ft_error();
	g_shell->tmp = g_shell->tmp->next;
	ft_do_pipes();
}

void	ft_do_pipes(void)
{
	int i;

	if (((t_cmdinfo *)g_shell->tmp->content)->flagpipe == 1)
	{
		i = pipe(g_shell->pipefd);
		if (i == -1)
			ft_error();
		g_shell->pid_pipe = fork();
		if (g_shell->pid_pipe == -1)
			ft_error();
		if (g_shell->pid_pipe == 0)
		{
			g_shell->flagparent = 0;
			ft_do_dup_child();
		}
		else
			ft_do_dup_parent();
	}
}

void	ft_process_cmd(void)
{
	ft_do_pipes();
	ft_do_redirections();

	// // POUR TEST PIPES
	// int status;
	// write(1, ((t_cmdinfo *)g_shell->tmp->content)->exec[0], 14);
	// if (g_shell->flagparent == 0)
	// 	ft_exit();
	// wait(&status);
	// // FIN TEST
}

void	ft_exec_cmd(void)
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
	ft_process_cmd();
	if (dup2(oldstdout, 1) == -1)
		ft_error();
	if (dup2(oldstdin, 0) == -1)
		ft_error();
	if (close(oldstdout) == -1)
		ft_error();
	if (close(oldstdin) == -1)
		ft_error();
}