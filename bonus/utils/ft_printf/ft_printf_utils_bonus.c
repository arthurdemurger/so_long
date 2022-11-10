/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:54:39 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/10 13:29:42 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	printf_putchar(char c, int *count)
{
	*count += 1;
	write (1, &c, 1);
}

void	printf_putstr(char *str, int *count)
{
	if (!str)
		printf_putstr("(null)", count);
	while (str && *str)
		printf_putchar(*str++, count);
}

void	printf_putnbr(int n, int *count)
{
	long	ln;

	ln = n;
	if (n < 0)
	{
		ln *= -1;
		printf_putchar('-', count);
	}
	if (ln > 9)
		printf_putnbr(ln / 10, count);
	printf_putchar(ln % 10 + 48, count);
}
