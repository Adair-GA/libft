/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:59:37 by agondan-          #+#    #+#             */
/*   Updated: 2023/09/12 18:12:39 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*bs1;
	unsigned char	*bs2;

	bs1 = (unsigned char *)s1;
	bs2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && bs1[i] == bs2[i])
	{
		i++;
	}
	if (i < n)
	{
		return (bs1[i] - bs2[i]);
	}
	return (0);
}
