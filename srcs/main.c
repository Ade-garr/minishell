/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:40:41 by user42            #+#    #+#             */
/*   Updated: 2021/02/12 16:32:05 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_shell g_shell;

void    ft_exit(void)
{
    if (g_shell->env != NULL)
        ft_lstclear(&g_shell->env, &free);
    exit(0);
}

void    init_shell(void)
{
    g_shell->env = NULL;
}

void    get_list_env(char **env)
{
    int     i;
    t_list  *tmp;

    i = 0;
    if (env == NULL)
        return ;
    while (env[i] != NULL)
    {
        tmp = ft_lstnew(env[i]);
        if (tmp == NULL)
            ft_exit(void);
        ft_lstadd_back(&g_shell->env, tmp);
        i++;
    }
}

int     main(int argc, char *argv, char** env)
{
    init_shell(void);
    get_list_env(env);
    if (g_shell->env == NULL)
        return (0);
    

    //POUR TEST
    int i;
    i = 0;
    printf("char **env :");
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
    printf("\n\n\n");
    printf("lst env :");
    i = 0;
    while (g_shell->env != NULL)
    {
        printf("%s\n", g_shell->env->content);
        g_shell->env = g_shell->env->next;
    }
    //FIN TEST

    return (1);
}