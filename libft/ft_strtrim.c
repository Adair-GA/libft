/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:30:59 by agondan-          #+#    #+#             */
/*   Updated: 2023/10/19 19:00:13 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(char const *str);

static char	*empty(void)
{
	char	*new;

	new = malloc(1);
	if (!new)
		return (NULL);
	new[0] = '\0';
	return (new);
}

static int	char_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		back_cont;
	char	*new;
	int		back_chars;

	if (ft_strlen(s1) == 0)
		return (empty());
	back_chars = 0;
	while (char_in_set(*s1, set))
		s1++;
	back_cont = ft_strlen(s1) - 1;
	if (back_cont <= 0)
		return ((char *)s1);
	while (char_in_set(s1[back_cont], set))
	{
		back_chars++;
		back_cont--;
	}
	new = malloc(ft_strlen(s1) - back_chars + 1);
	if (!new)
		return ((void *)0);
	ft_strlcpy(new, s1, (ft_strlen(s1) - back_chars) + 1);
	return (new);
}
