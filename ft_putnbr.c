/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:09:32 by agondan-          #+#    #+#             */
/*   Updated: 2023/12/05 15:26:08 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static ssize_t	ft_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

static int	ft_abs(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar('-', fd);
		nb = nb * -1;
	}
	return (nb);
}

static int	ft_get_digits(int nb, char *buff)
{
	int	dig;
	int	cont;

	cont = 0;
	while (nb > 9)
	{
		dig = nb % 10;
		nb = nb / 10;
		buff[cont] = '0' + dig;
		cont++;
	}
	buff[cont] = '0' + nb;
	return (cont);
}

ssize_t	ft_putnbr(int n)
{
	int		characters;
	char	buffer[10];
	ssize_t	written;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	written = n < 0;
	n = ft_abs(n, 1);
	characters = ft_get_digits(n, buffer);
	while (characters >= 0)
	{
		written += ft_putchar(buffer[characters], 1);
		characters--;
	}
	return (written);
}
