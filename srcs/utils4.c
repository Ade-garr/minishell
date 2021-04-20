/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:17:09 by ade-garr          #+#    #+#             */
/*   Updated: 2021/04/20 10:17:38 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			skip_to_next_valid_quote(char *s, int *i)
{
	if (s[*i] == '\'' && !is_escaped(s, *i))
	{
		(*i)++;
		while (s[*i])
		{
			if (s[*i] == '\'' && !is_escaped(s, *i))
				break ;
			(*i)++;
		}
	}
	else if (s[*i] == '\"' && !is_escaped(s, *i))
	{
		(*i)++;
		while (s[*i])
		{
			if (s[*i] == '\"' && !is_escaped(s, *i))
				break ;
			(*i)++;
		}
	}
}

t_token		**free_lexer(t_token **lexer)
{
	int			i;

	i = 0;
	while (lexer[i])
	{
		free(lexer[i]->s);
		free(lexer[i]);
		i++;
	}
	free(lexer);
	return (NULL);
}

char		*join_three_str(char *s1, char *s2, char *s3)
{
	int		len1;
	int		len2;
	int		len3;
	char	*dst;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	if (s3)
		len3 = ft_strlen(s3);
	else
		len3 = 0;
	if (!(dst = malloc((len1 + len2 + len3 + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(dst, s1, len1 + 1);
	ft_strlcpy(dst + len1, s2, len2 + 1);
	ft_strlcpy(dst + len1 + len2, s3, len3 + 1);
	return (dst);
}