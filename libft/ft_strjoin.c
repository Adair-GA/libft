/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:42:07 by agondan-          #+#    #+#             */
/*   Updated: 2023/10/11 13:25:48 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		st_len;
	char	*new;
	int		cont;

	st_len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (st_len == 0)
		st_len++;
	new = ft_calloc(st_len, 1);
	if (!new)
		return (((void *)0));
	cont = 0;
	while (*s1)
	{
		new[cont] = *s1;
		s1++;
		cont++;
	}
	while (*s2)
	{
		new[cont] = *s2;
		s2++;
		cont++;
	}
	new[cont] = '\0';
	return (new);
}
