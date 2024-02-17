/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:19:52 by agondan-          #+#    #+#             */
/*   Updated: 2023/10/10 15:52:11 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_start_end(char c, int *start, int *end, char *s)
{
	int	cont;

	s = &s[*start];
	cont = 0;
	while (*s && *s == c)
	{
		*start = *start + 1;
		s++;
	}
	if (!*s)
		return (-1);
	while (*s && *s != c)
	{
		s++;
		cont++;
	}
	*end = *start + cont;
	return (cont);
}

static int	word_count(char const *s, char c)
{
	int	word_cont;
	int	start;
	int	end;

	start = 0;
	end = 0;
	word_cont = 0;
	while (get_start_end(c, &start, &end, (char *)s) > 0)
	{
		word_cont++;
		start = end;
	}
	return (word_cont);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		arr_cont;
	int		start;
	int		end;

	arr_cont = 0;
	start = 0;
	end = 0;
	if (!s)
		return (NULL);
	new = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (get_start_end(c, &start, &end, (char *)s) > 0)
	{
		new[arr_cont] = malloc(end - start + 1);
		if (!new[arr_cont])
			return (NULL);
		ft_strlcpy(new[arr_cont], &s[start], end - start + 1);
		start = end;
		arr_cont++;
	}
	return (new);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	new[] = "hello!";
// 	char	**ret;

// 	ret = ft_split(new, ' ');
// 	while (*ret)
// 	{
// 		printf("%s\n", *ret);
// 		ret++;
// 	}
// }
