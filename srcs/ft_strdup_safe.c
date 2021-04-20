/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:15:39 by ade-garr          #+#    #+#             */
/*   Updated: 2021/04/20 12:06:32 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	if (src != NULL)
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
}

char		*ft_strdup_safe(const char *s)
{
	char *s2;

	if (!(s2 = malloc(sizeof(char) * (ft_strlen_safe(s) + 1))))
		return (NULL);
	ft_strcpy(s2, s);
	return (s2);
}
