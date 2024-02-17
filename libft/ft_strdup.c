/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:30:24 by agondan-          #+#    #+#             */
/*   Updated: 2023/10/19 18:51:27 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		cont;
	char	*mem;

	cont = 0;
	while (s1[cont])
		cont++;
	mem = malloc(cont + 1);
	if (mem == NULL)
		return (NULL);
	cont = 0;
	while (s1[cont])
	{
		mem[cont] = s1[cont];
		cont++;
	}
	mem[cont] = '\0';
	return (mem);
}
