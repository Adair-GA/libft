/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:45:20 by agondan-          #+#    #+#             */
/*   Updated: 2023/09/26 15:31:00 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (ptr2 < ptr)
	{
		while (len--)
		{
			ptr[len] = ptr2[len];
		}
	}
	else
	{
		while (len--)
		{
			*ptr++ = *ptr2++;
		}
	}
	return (dst);
}
