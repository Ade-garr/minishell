/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:40:41 by user42            #+#    #+#             */
/*   Updated: 2021/03/03 15:30:30 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_error(void)
{
	printf("%s\n", strerror(errno));
	ft_exit();
}

void    ft_exit(void)
{
	if (g_shell->env != NULL)
		ft_lstclear_env(&g_shell->env);
	if (g_shell->line != NULL)
	{
		free(g_shell->line);
		g_shell->line = NULL;
	}
	/// FREE CMD ET DIR
	free(g_shell);
	g_shell = NULL;
	exit(0);
}

void    init_shell(void)
{
	g_shell = malloc(sizeof(t_shell) * 1);
	if (g_shell == NULL)
		exit(0);
	g_shell->env = NULL;
	g_shell->line = NULL;
	g_shell->tmp = NULL;
	g_shell->cmd = NULL;
	g_shell->flagparent = 1;
}

void    get_list_env(char **env)
{
	int     i;
	t_list  *tmp;

	i = 0;
	while (env[i] != NULL)
	{
		tmp = ft_lstnew(env[i]);
		if (tmp == NULL)
			ft_exit();
		ft_lstadd_back(&g_shell->env, tmp);
		i++;
	}
}

int     main(int argc, char **argv, char **env)
{
	int ret;
	(void)argc;
	(void)argv;
	init_shell();
	get_list_env(env);

	// POUR TEST PIPES
	// 1er maillon
	t_cmdinfo	new0;
	char		cmd0[] = "test 1eme cmd";
	new0.flagpipe = 1;
	new0.exec = malloc(sizeof(char *) * 2);
	new0.exec[0] = cmd0;
	new0.exec[1] = NULL;
	new0.dir = NULL;
	g_shell->cmd = ft_lstnew(&new0);
	// 2e maillon
	t_cmdinfo	new1;
	char		cmd1[] = "test 2eme cmd";
	new1.flagpipe = 1;
	new1.exec = malloc(sizeof(char *) * 2);
	new1.exec[0] = cmd1;
	new1.exec[1] = NULL;
	new1.dir = NULL;
	ft_lstadd_back(&g_shell->cmd, ft_lstnew(&new1));
	// 3e maillon
	t_cmdinfo	new2;
	char		cmd2[] = "test 3eme cmd";
	new2.flagpipe = 0;
	new2.exec = malloc(sizeof(char *) * 2);
	new2.exec[0] = cmd2;
	new2.exec[1] = NULL;
	new2.dir = NULL;
	ft_lstadd_back(&g_shell->cmd, ft_lstnew(&new2));
	// FIN TEST

	while (1)
	{
		write(2, "$ ", 2);
		ret = get_next_line(1, &g_shell->line);
		// A COMPLETER
		ft_exec_cmd();
		if (ret == -1)
			ft_exit();
		write(2, "\n", 1);
	}

	// //POUR TEST ENV
	// #include <stdio.h>
	// int i;
	// i = 0;
	// printf("char **env :");
	// while (env[i] != NULL)
	// {
	//     printf("%s\n", env[i]);
	//     i++;
	// }
	// printf("-\n-\n-\n");
	// printf("lst env :");
	// while (g_shell->env != NULL)
	// {
	//     printf("%s\n", g_shell->env->content);
	//     g_shell->env = g_shell->env->next;
	// }
	// // FIN TEST

	return (1);
}