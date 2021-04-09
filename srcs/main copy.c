/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:09:59 by vlugand-          #+#    #+#             */
/*   Updated: 2021/04/09 19:45:32 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av)
{
	t_token		**lexer;
	t_node		*ast;

	(void)ac;
	if (!(lexer = ft_lexer(av[1])))
		return (0); 
	print_lexer(lexer, av[1]); // print to debug
	if(!(ast = parser(lexer)))
		return (0);
	print_parser(ast); // print to debug
	free_ast(ast);
//	system("leaks minishell");// uncomment to test leaks on mac os
	return (0);
}

/*ATTENTION VAR 

check les chifres et symboles spe
difference avec ou sans export
peut concat avec +=
*/