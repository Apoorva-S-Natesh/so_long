/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:33:11 by asomanah          #+#    #+#             */
/*   Updated: 2024/05/10 12:33:44 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (*s != '\0')
	{
		count += ft_putchar((int)*s);
		++s;
	}
	return (count);
}

int	ft_putnbr(long nbr, int base, char c)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-nbr, base, c) + 1);
	}
	if (c == 'u' && (nbr > (unsigned int) - 1))
		return (write (1, "0", 1));
	else if (nbr < base)
	{
		if (c == 'X' && (nbr >= 10 && nbr <= 15))
			return (ft_putchar(symbols[nbr] - 32));
		else
			return (ft_putchar(symbols[nbr]));
	}
	else
	{
		count = ft_putnbr(nbr / base, base, c);
		return (count + ft_putnbr(nbr % base, base, c));
	}
}

void	ft_print_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_print_ptr(num / 16);
		ft_print_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	if (ptr == 0)
		count += write (1, "0", 1);
	else
	{
		ft_print_ptr(ptr);
		while (ptr != 0)
		{
			count++;
			ptr = ptr / 16;
		}
	}
	return (count);
}
