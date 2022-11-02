/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademurge <ademurge@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:08:50 by ademurge          #+#    #+#             */
/*   Updated: 2022/11/02 15:14:55 by ademurge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	ft_putchar_mem(int nbr, char *base, int *count)
{
	write(1, &base[nbr], 1);
	*count += 1;
}

static void	ft_putmem(unsigned long nbr, int *count)
{
	if (nbr > 15)
		ft_putmem(nbr / 16, count);
	ft_putchar_mem((nbr % 16), "0123456789abcdef", count);
}

void	ft_print_address(void *add, int *count)
{
	unsigned long	hex;

	hex = (unsigned long)add;
	printf_putstr("0x", count);
	ft_putmem(hex, count);
}
