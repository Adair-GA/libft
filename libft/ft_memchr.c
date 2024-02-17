/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:07:39 by agondan-          #+#    #+#             */
/*   Updated: 2023/09/15 16:41:19 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	to_find;
	size_t			index;
	unsigned char	*str;

	index = 0;
	to_find = (unsigned char)c;
	str = (unsigned char *)s;
	while (index < n)
	{
		if (str[index] == to_find)
			return ((void *)&str[index]);
		index++;
	}
	return (NULL);
}
