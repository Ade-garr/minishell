/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:30:22 by ade-garr          #+#    #+#             */
/*   Updated: 2021/02/24 13:41:01 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void       ft_do_pipes(void)
{

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