/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:53:48 by astehl            #+#    #+#             */
/*   Updated: 2024/09/03 17:35:26 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	printf("0: FT %i, Original %i\n", ft_isprint(0), isprint(0));
	printf("15: FT %i, Original %i\n", ft_isprint(15), isprint(15));
	printf("32: FT %i, Original %i\n", ft_isprint(32), isprint(32));
	printf("100: FT %i, Original %i\n", ft_isprint(100), isprint(100));
	printf("144: FT %i, Original %i\n", ft_isprint(144), isprint(144));
	return (0);
}
*/
