/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:07:39 by agondan-          #+#    #+#             */
/*   Updated: 2023/09/12 17:45:34 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	to_find;
	int				index;

	index = 0;
	to_find = (unsigned char)c;
	while (s[index])
		index++;
	while (index >= 0)
	{
		if (s[index] == to_find)
			return ((char *)&s[index]);
		index--;
	}
	return (NULL);
}
