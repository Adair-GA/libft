/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:04:07 by agondan-          #+#    #+#             */
/*   Updated: 2023/12/06 16:58:39 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include "libft/libft.h"
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h> //va_list va_start va_arg va_end

int	ft_printf(char const *src, ...);

#endif
