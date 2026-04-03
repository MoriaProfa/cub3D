/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:01:37 by astehl            #+#    #+#             */
/*   Updated: 2024/10/11 18:28:15 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	printf("0: FT %i, Original %i\n", ft_isascii(0), isascii(0));
	printf("5: FT %i, Original %i\n", ft_isascii(5), isascii(5));
	printf("180: FT %i, Original %i\n", ft_isascii(180), isascii(180));
	return (0);
}
*/
