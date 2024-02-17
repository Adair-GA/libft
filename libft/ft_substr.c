/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:11:38 by agondan-          #+#    #+#             */
/*   Updated: 2023/10/10 17:28:48 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(char *str);

static char	*empty(void)
{
	char	*new;

	new = malloc(1);
	if (!new)
		return (NULL);
	new[0] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			cont;
	char			*new;

	cont = 0;
	if (start >= ft_strlen((char *)s))
		return (empty());
	while (cont < start)
	{
		s++;
		cont++;
	}
	if (len > ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	cont = 0;
	while (*s && cont < len)
	{
		new[cont] = *s;
		s++;
		cont++;
	}
	new[cont] = '\0';
	return (new);
}
