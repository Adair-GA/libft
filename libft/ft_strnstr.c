/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:18:40 by agondan-          #+#    #+#             */
/*   Updated: 2023/10/09 20:31:04 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	j = 0;
	str = (char *)haystack;
	if (needle[0] == '\0')
		return (str);
	while (str[i] && i < len)
	{
		while (str[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return (&str[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
