/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:14:51 by agondan-          #+#    #+#             */
/*   Updated: 2023/10/08 20:08:55 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	absol(int *n)
{
	if (*n < 0)
	{
		*n = -*n;
		return (1);
	}
	return (0);
}

static int	char_count(int n)
{
	int	cont;

	cont = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		cont++;
		n = n / 10;
	}
	return (cont);
}

static char	*min(void)
{
	char	*buff;

	buff = malloc(12);
	buff[0] = '-';
	buff[1] = '2';
	buff[2] = '1';
	buff[3] = '4';
	buff[4] = '7';
	buff[5] = '4';
	buff[6] = '8';
	buff[7] = '3';
	buff[8] = '6';
	buff[9] = '4';
	buff[10] = '8';
	buff[11] = '\0';
	return (buff);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		cont;
	int		is_neg;

	if (n == -2147483648)
		return (min());
	is_neg = absol(&n);
	cont = char_count(n) + 1 + is_neg;
	str = malloc(cont);
	if (!str)
		return (NULL);
	cont -= 1;
	str[cont] = '\0';
	if (n == 0)
		str[--cont] = '0';
	while (n > 0)
	{
		cont--;
		str[cont] = (n % 10) + '0';
		n = n / 10;
	}
	if (is_neg)
		str[--cont] = '-';
	return (str);
}

/* #include "libft.h"
#include <stdio.h>

int	main(void)
{
	int		n;
	char	*str;

	n = -12;
	str = ft_itoa(n);
	printf("The integer %d as a string is: %s\n", n, str);
	free(str);
	return (0);
} */
