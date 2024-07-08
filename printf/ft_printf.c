/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:32:08 by asomanah          #+#    #+#             */
/*   Updated: 2024/05/16 16:33:55 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list args, const char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_putptr(va_arg(args, unsigned long long));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr((long)va_arg(args, int), 10, specifier);
	else if (specifier == 'u')
		count += ft_putnbr(va_arg(args, unsigned int), 10, 'u');
	else if (specifier == 'x' || specifier == 'X')
		count += ft_putnbr((long)va_arg(args, unsigned int), 16, specifier);
	else if (specifier == '%')
		count += write(1, "%%", 1);
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			count += write (1, &str[i], 1);
		else
		{
			i++;
			count += check_format(args, str[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
