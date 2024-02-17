/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:48:40 by agondan-          #+#    #+#             */
/*   Updated: 2023/10/19 18:53:29 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		cont;

	cont = 0;
	new = malloc(ft_strlen(s) + 1);
	if (!new)
	{
		return (NULL);
	}
	while (s[cont])
	{
		new[cont] = f(cont, s[cont]);
		cont++;
	}
	new[cont] = '\0';
	return (new);
}
