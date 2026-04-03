/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:33:13 by astehl            #+#    #+#             */
/*   Updated: 2024/09/03 17:32:33 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	printf("0: FT %i, Original %i\n", ft_isdigit(0), isdigit(0));
	printf("5: FT %i, Original %i\n", ft_isdigit(5), isdigit(5));
	printf("50: FT %i, Original %i\n", ft_isdigit(50), isdigit(50));
	printf("57: FT %i, Original %i\n", ft_isdigit(57), isdigit(57));
	printf("100: FT %i, Original %i\n", ft_isdigit(100), isdigit(100));
	return (0);
}
*/
