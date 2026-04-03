/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:02:59 by astehl            #+#    #+#             */
/*   Updated: 2024/10/16 14:30:15 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	break_down(int n, int fd)
{
	int	r;

	if (n > 9)
	{
		r = n / 10;
		break_down(r, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
	{
		if (n >= 0 && n <= 9)
			ft_putchar_fd(n + '0', fd);
		else if (n > 9)
			break_down(n, fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		if (n >= -9 && n <= -1)
			ft_putchar_fd(n * -1 + '0', fd);
		else if (n == -2147483648)
		{
			ft_putchar_fd(2 + '0', fd);
			break_down(147483648, fd);
		}
		else if (n < -9)
			break_down(n * -1, fd);
	}
}
/*
int main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	return (0);
}
// ft_putstr_fd(ft_itoa(n), fd);
*/
