/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:30:11 by mpascual          #+#    #+#             */
/*   Updated: 2022/09/25 12:22:33 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_u(unsigned int nb, int len, t_var *var)
{
	if (var->is_precision && !var->precision)
		return (0);
	while (var->precision > len)
	{
		var->printed_chars += ft_putchar('0');
		var->precision--;
	}
	if (nb != 4294959296)
		ft_printnbr_u(nb, var);
	else
		var->printed_chars += write(1, "4294959296", 10);
	return (0);
}

void	print_u(unsigned int nb, t_var *var)
{
	int		len;
	int		pre_printed;

	len = (var->is_precision && !var->precision) ? 0 : ft_nbrlen(nb, 10);
	pre_printed = (var->precision > len) ? (var->precision - len) : 0;
	if (var->minus)
		put_u(nb, len, var);
	while (var->width > (len + pre_printed))
	{
		if (var->zero && !var->is_precision)
			var->printed_chars += ft_putchar('0');
		else
			var->printed_chars += ft_putchar(' ');
		var->width--;
	}
	if (var->minus == false)
		put_u(nb, len, var);
}

int	minus(t_var *var)
{
	int	i;

	i = 1;
	var->zero = false;
	var->minus = true;
	return (i);
}

void	ft_printnbr(int nb, t_var *var)
{
	long int	num;

	num = nb;
	if (num < 0)
	{
		ft_putchar('-');
		var->printed_chars++;
		num *= -1;
	}
	if (num >= 10)
	{
		ft_printnbr(num / 10, var);
		ft_putchar(num % 10 + '0');
		var->printed_chars++;
	}
	else
		var->printed_chars += ft_putchar(num + '0');
}

void	ft_printnbr_u(unsigned int nb, t_var *var)
{
	unsigned int	num;

	num = nb;
	if (num >= 10)
	{
		ft_printnbr(num / 10, var);
		ft_putchar(num % 10 + '0');
		var->printed_chars++;
	}
	else
		var->printed_chars += ft_putchar(num + '0');
}
