/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:11:10 by esali             #+#    #+#             */
/*   Updated: 2022/10/16 18:49:07 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	convert(unsigned long int n)
{
	if (n > 0)
	{
		convert(n / 16);
		ft_putchar("0123456789abcdef"[n % 16]);
	}
}

void	dectohex(int n)
{
	long	l;

	if (n == 0)
		ft_putchar('0');
	if (n == -2147483648)
		ft_putstr("80000000");
	else if (n < 0)
	{
		l = 4294967296 + n;
		convert(l);
	}
	else
		convert((long) n);
}

void	dectohex_up(int n)
{
	long	l;

	if (n == 0)
		ft_putchar('0');
	if (n == -2147483648)
		ft_putstr("80000000");
	else if (n < 0)
	{
		l = 4294967296 + n;
		convert_up(l);
	}
	else
		convert_up((long) n);
}

void	convert_up(long n)
{
	if (n > 0)
	{
		convert_up(n / 16);
		ft_putchar("0123456789ABCDEF"[n % 16]);
	}
}
