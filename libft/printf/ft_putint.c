/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:41:59 by esali             #+#    #+#             */
/*   Updated: 2022/10/16 18:49:49 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putint(int n)
{
	char	p;

	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 0)
	{
		putint(n / 10);
		p = (n % 10) + 48;
		ft_putchar(p);
	}
}

void	ft_putint(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n == 0)
		ft_putchar('0');
	else if (n < 0 || n > 0)
		putint(n);
}

void	ft_putu(unsigned int n)
{
	if (n == 0)
		ft_putchar('0');
	else if (n > 0)
		putu(n);
}

void	putu(unsigned int n)
{
	char	p;

	if (n > 0)
	{
		putu(n / 10);
		p = (n % 10) + 48;
		ft_putchar(p);
	}
}
