/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:45:10 by esali             #+#    #+#             */
/*   Updated: 2022/10/16 18:53:28 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	g_count;

void	ft_putchar(int c)
{
	g_count++;
	write(1, &c, 1);
}

void	distribute(const char c, va_list ap)
{
	if (c == '%')
		ft_putchar('%');
	if (c == 'c')
		ft_putchar(va_arg(ap, int));
	if (c == 's')
		ft_putstr(va_arg(ap, char *));
	if (c == 'i')
		ft_putint(va_arg(ap, int));
	if (c == 'd')
		ft_putint(va_arg(ap, int));
	if (c == 'u')
		ft_putu(va_arg(ap, unsigned int));
	if (c == 'x')
		dectohex(va_arg(ap, int));
	if (c == 'X')
		dectohex_up(va_arg(ap, int));
	if (c == 'p')
		ft_putptr(va_arg(ap, void *));
}

int	ft_printf(const char *c, ...)
{
	va_list	ap;
	int		i;

	g_count = 0;
	va_start(ap, c);
	i = 0;
	while (c[i] != 0)
	{
		if (c[i] == '%')
		{
			i++;
			distribute(c[i], ap);
		}
		else
			ft_putchar(c[i]);
		i++;
	}
	return (g_count);
}
