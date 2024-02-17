/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:23:22 by agondan-          #+#    #+#             */
/*   Updated: 2023/10/17 18:24:15 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
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

void	ft_putnbr_fd(int n, int fd)
{
	int		characters;
	char	buffer[10];

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	n = ft_abs(n, fd);
	characters = ft_get_digits(n, buffer);
	while (characters >= 0)
	{
		ft_putchar(buffer[characters], fd);
		characters--;
	}
}

// int main()
// {
// 	ft_putnbr_fd(-987441, 1);
// }
