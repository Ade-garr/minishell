/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:33:39 by vlugand-          #+#    #+#             */
/*   Updated: 2021/04/20 10:45:39 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_match_in_env(char *s, int *len, t_list *env)
{
	int		i;
	
	i = 0;
	while (s[i])
	{
		if ((s[i] == '\'' && !is_escaped(s, i))
		|| (s[i] == '\"' && !is_escaped(s, i))
		|| (s[i] == '$' && !is_escaped(s, i)))
			break ;
		i++;
	}
	*len = i;
	while (env)
	{
		if (i > 0 && ft_strncmp(s, (char *)(env->content), i) == 0 && ((char *)(env->content))[i] == '=')
			return ((char *)(env->content) + i + 1);
		env = env->next;
	}
	return (NULL);
}

char	*replace_var(char *s, int i, t_list *env)
{
	char	*match;
	char	*dst;
	int		len;

	len = 0;
	match = find_match_in_env(s + i + 1, &len, env);
	s[i] = '\0';
	if (match)
		dst = join_three_str(s, match, s + i + len + 1);
	else
		dst = join_three_str(s, "", s + i + len + 1);
	free(s);
	return (dst);
}

char	*expand_content(char *s, t_list *env)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' && !is_escaped(s, i))
		{
			skip_to_next_valid_quote(s, &i);
			i++;
		}
		if (s[i] == '$' && !is_escaped(s, i))
			s = replace_var(s, i, env);
		else
			i++;
	}
	return (s);
}

int		check_dollar_sign(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && !is_escaped(s, i))
			return (1);
		i++;
	}
	return (0);
}

void		replace_elem(t_token **content, t_list *elem, t_list *prev)
{
	int			i;
	t_list		*lst;

	i = 0;
	lst = NULL;
	while (content[i])
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(content[i]->s)));
		i++;
	}
	ft_lstadd_back(&lst, elem->next);
	free_lexer(content);
	free(elem->content);
	free(elem);
	prev->next = lst;
}
