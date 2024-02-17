/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:28:59 by agondan-          #+#    #+#             */
/*   Updated: 2023/12/06 17:54:12 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define HEXBASEUPPER "0123456789ABCDEF"
#define HEXBASELOWER "0123456789abcdef"

ssize_t	ft_print_hex_num(unsigned int number, int mayus, int *count)
{
	unsigned int	n;
	int				written;

	if (!count)
	{
		written = 0;
		count = &written;
	}
	n = number / 16;
	if (n > 0)
		ft_print_hex_num(n, mayus, count);
	if (mayus)
		write(1, &HEXBASEUPPER[number % 16], 1);
	else
		write(1, &HEXBASELOWER[number % 16], 1);
	if (count)
		*count += 1;
	return (*count);
}

ssize_t	ft_print_hex_pointer_rec(unsigned long number, int *count)
{
	unsigned long	n;
	int				written;

	if (!count)
	{
		written = 0;
		count = &written;
	}
	n = number / 16;
	if (n > 0)
		ft_print_hex_pointer_rec(n, count);
	write(1, &HEXBASELOWER[number % 16], 1);
	if (count)
		*count += 1;
	return (*count + 2);
}

ssize_t	ft_print_hex_pointer(unsigned long number, int *count)
{
	write(1, "0x", 2);
	return (ft_print_hex_pointer_rec(number, count));
}
