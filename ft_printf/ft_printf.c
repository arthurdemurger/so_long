/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:23:38 by ademurge          #+#    #+#             */
/*   Updated: 2022/10/20 15:27:12 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%' && is_conversion(str[i + 1]))
			do_conversion(str[++i], args, &count);
		else if (str[i] == '%' && !is_conversion(str[i + 1]))
			i++;
		else
			printf_putchar(str[i], &count);
	}
	va_end(args);
	return (count);
}
