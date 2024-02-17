/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:22:15 by agondan-          #+#    #+#             */
/*   Updated: 2023/09/26 15:13:03 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			tot;
	size_t			i;

	i = 0;
	tot = size * count;
	mem = malloc(tot);
	if (!mem)
		return ((void *)0);
	while (i < tot)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}
