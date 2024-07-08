/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:08:30 by asomanah          #+#    #+#             */
/*   Updated: 2024/05/10 14:24:27 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	check_format(va_list args, const char specifier);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(long nbr, int base, char c);
int	ft_putptr(unsigned long long ptr);

#endif
