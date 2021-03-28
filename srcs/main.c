/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:40:41 by user42            #+#    #+#             */
/*   Updated: 2021/03/28 16:36:03 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(void)
{
	printf("%s\r\n", strerror(errno));
	ft_exit();
}

void	ft_exit(void)	// a revoir selon parsing et code
{
	if (g_shell->env != NULL)
		ft_lstclear_env(&g_shell->env);
	if (g_shell->line != NULL)
	{
		free(g_shell->line);
		g_shell->line = NULL;
	}
	/// FREE CMD ET DIR
	if (g_shell->flag_termios == 1)
	{
		if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_shell->orig_termios) == -1)
			printf("%s\r\n", strerror(errno));
	}
	free(g_shell);
	g_shell = NULL;
	exit(1);
}

void    init_shell(void)
{
	g_shell = malloc(sizeof(t_shell) * 1);
	if (g_shell == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	g_shell->env = NULL;
	g_shell->line = NULL;
	g_shell->tmp = NULL;
	g_shell->cmd = NULL;
	g_shell->flagparent = 1;
	g_shell->flag_termios = 0;
	g_shell->pos_x = 3;
	g_shell->nb_hist = 0;
	g_shell->hist = NULL;
	g_shell->saved_line = NULL;
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
			ft_error();
		ft_lstadd_back(&g_shell->env, tmp);
		i++;
	}
}

int     main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	init_shell(); // a revoir selon parsing et code
	enable_raw_mode();
	get_list_env(env);
	param_termcap();
	ft_readline();
	return (0);
}