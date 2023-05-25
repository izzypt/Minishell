/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:52:12 by esali             #+#    #+#             */
/*   Updated: 2022/06/07 14:13:49 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nb(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	putnbr(char *ret, int i, int n)
{
	char	p;

	if (n > 0)
	{
		i--;
		putnbr(ret, i, n / 10);
		p = (n % 10);
		ret[i] = p + 48;
	}
}

static char	*create_malloc(int i, int n)
{
	char	*ret;

	ret = (char *) malloc(sizeof(char) * i);
	if (ret == NULL)
		return (NULL);
	if (n == -2147483648)
		ft_strlcpy(ret, "-2147483648", 12);
	else if (n < 0)
	{
		ret[0] = '-';
		putnbr(ret, i - 1, n * -1);
		ret[i - 1] = '\0';
	}
	else if (n == 0)
		ft_strlcpy(ret, "0", 2);
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;

	i = count_nb(n);
	if (n == -2147483648)
		ret = create_malloc(12, n);
	else if (n < 0)
		ret = create_malloc(i + 2, n);
	else if (n == 0)
		ret = create_malloc(2, n);
	else
	{
		ret = create_malloc(i + 1, n);
		if (ret == NULL)
			return (NULL);
		putnbr(ret, i, n);
		ret[i] = '\0';
	}
	if (ret == NULL)
		return (NULL);
	return (ret);
}
