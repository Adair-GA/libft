/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:38:48 by agondan-          #+#    #+#             */
/*   Updated: 2024/02/01 13:05:53 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cspdiuxX%
#include "ft_printf.h"

int		putstr(char *str);
ssize_t	ft_putnbr(int n);
ssize_t	ft_print_hex_num(unsigned long number, int mayus, int *count);
ssize_t	ft_print_hex_pointer(unsigned long number, int *count);
ssize_t	ft_print_long(unsigned int num);

int	myputchar(char c)
{
	return (write(1, &c, 1));
}

ssize_t	what(char c, va_list args)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (myputchar((int)va_arg(args, int)));
	if (c == 's')
		return (putstr((char *)va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr((int)va_arg(args, int)));
	if (c == 'x' || c == 'X')
		return (ft_print_hex_num((unsigned int)va_arg(args, unsigned int),
				c == 'X', NULL));
	if (c == 'p')
		return (ft_print_hex_pointer((unsigned long)va_arg(args, unsigned long),
				NULL));
	if (c == 'u')
		return (ft_print_long((long)va_arg(args, long)));
	return (0);
}

int	ft_printf(char const *fstr, ...)
{
	int		index;
	va_list	args;
	int		counter;
	int		putc_ret;

	counter = 0;
	index = 0;
	va_start(args, fstr);
	while (fstr[index])
	{
		if (fstr[index] == '%')
			counter += what(fstr[++index], args);
		else
		{
			putc_ret = myputchar(fstr[index]);
			if (putc_ret == -1)
				return (-1);
			counter += putc_ret;
		}
		index++;
	}
	return (counter);
}

// #include <stdio.h>
// #include <limits.h>
// int	main(int argc, char const *argv[])
// {
// 	int mio = ft_printf("Mio: %x\n", LONG_MAX);
// 	int original = printf("No mio: %x\n", LONG_MIN);

// 	printf("Mio: %d Original: %d", mio, original);
// }
