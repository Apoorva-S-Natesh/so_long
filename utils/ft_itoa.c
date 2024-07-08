/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:35:24 by asomanah          #+#    #+#             */
/*   Updated: 2024/07/08 11:39:35 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_digits(long num);
static char	*set_space(int len);

char	*ft_itoa(int n)
{
	long	nbr;
	int		c;
	char	*str;
	int		i;

	nbr = n;
	c = count_digits(nbr);
	str = set_space(c);
	if (!str)
		return (NULL);
	if (nbr < 0)
		nbr *= -1;
	i = c - 1;
	while (nbr != 0)
	{
		str[i] = ((nbr % 10) + 48);
		nbr /= 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	str[c] = 0;
	return (str);
}

static int	count_digits(long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count++;
		num = -num;
	}
	if (num == 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static char	*set_space(int len)
{
	char	*tmp;

	tmp = (char *)malloc((len +1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}
