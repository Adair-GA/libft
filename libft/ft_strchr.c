/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:07:39 by agondan-          #+#    #+#             */
/*   Updated: 2023/10/10 17:13:38 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	to_find;

	to_find = (unsigned char)c;
	while (*s)
	{
		if (*s == to_find)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == to_find)
		return ((char *)s);
	return (NULL);
}
