/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:54:54 by manu              #+#    #+#             */
/*   Updated: 2020/02/16 19:56:20 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This putnbr returns the number of characters printed (usefull for printf)
*/

int     ft_putnbr(int nb)
{
	long	int		num;
	unsigned int	len;

	num = nb;
	len = 0;
	if (num < 0)
	{
		ft_putchar('-');
		len++;
		num *= -1;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
	    ft_putchar(num % 10 + '0');
		len++;
	}
	else
	{
		ft_putchar(num + '0');
		len++;
	}
    return (len);
}