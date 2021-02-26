/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:40:41 by user42            #+#    #+#             */
/*   Updated: 2021/02/26 14:17:31 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell *g_shell;

void    ft_error(void)
{
    printf("%s\n", strerror(errno));
    ft_exit();
}

void    ft_exit(void)
{
    if (g_shell->env != NULL)
        ft_lstclear(&g_shell->env, &free);
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
    while (1)
    {
        write(2, "$ ", 2);
        ret = get_next_line(1, &g_shell->line);
        // A COMPLETER
        ft_exec_cmd();
        if (ret == -1)
            ft_exit();
    }

    // //POUR TEST
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