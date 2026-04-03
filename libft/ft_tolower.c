/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:31:05 by astehl            #+#    #+#             */
/*   Updated: 2024/09/03 19:36:16 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	printf("0: FT %i, Original %i\n", ft_tolower(0), tolower(0));
	printf("78: FT %i, Original %i\n", ft_tolower(78), tolower(78));
	printf("'Z': FT %i, Original %i\n", ft_tolower('Z'), tolower('Z'));
	printf("265: FT %i, Original %i\n", ft_tolower(265), tolower(265));
	return (0);
}
*/
