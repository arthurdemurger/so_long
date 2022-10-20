/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:24:10 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/20 15:28:05 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_conversion(char c)
{
	char	*lst_conv;

	lst_conv = "cspdiuxX%";
	while (*lst_conv)
		if (c == *lst_conv++)
			return (1);
	return (0);
}

void	do_conversion(char c, va_list args, int *count)
{
	if (c == 'c')
		printf_putchar(va_arg(args, int), count);
	else if (c == 's')
		printf_putstr(va_arg(args, void *), count);
	else if (c == 'p')
		ft_print_address(va_arg(args, void *), count);
	else if (c == 'd' || c == 'i')
		printf_putnbr_base(va_arg(args, int), SIGNED, DECIMAL, count);
	else if (c == 'u')
		printf_putnbr_base(va_arg(args, int), UNSIGNED, DECIMAL, count);
	else if (c == 'x')
		printf_putnbr_base(va_arg(args, int), UNSIGNED, LOW_HEXADECIMAL, count);
	else if (c == 'X')
		printf_putnbr_base(va_arg(args, int), UNSIGNED, UP_HEXADECIMAL, count);
	else if (c == '%')
		printf_putchar('%', count);
}
