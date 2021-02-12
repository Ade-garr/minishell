/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:40:41 by user42            #+#    #+#             */
/*   Updated: 2021/02/12 12:12:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_shell g_shell;

void    init_shell(void)
{
    g_shell->env = NULL;
}

void    get_list_env(char **env)
{
    
}

int     main(int argc, char *argv, char** env)
{
    init_shell(void);
    get_list_env(env);
}