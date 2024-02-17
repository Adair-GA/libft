/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:59:57 by agondan-          #+#    #+#             */
/*   Updated: 2023/12/06 18:23:49 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

ssize_t	ft_print_long(unsigned int num)
{
	int		written;

	written = 0;
	if (num > 9)
		written += ft_print_long(num / 10);
	write(1, &"0123456789"[num % 10], 1);
	written++;
	return (written);
}
