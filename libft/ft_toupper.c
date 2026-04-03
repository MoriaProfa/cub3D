/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:22:28 by astehl            #+#    #+#             */
/*   Updated: 2024/09/03 19:29:50 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	printf("0: FT %i, Original %i\n", ft_toupper(0), toupper(0));
	printf("100: FT %i, Original %i\n", ft_toupper(100), toupper(100));
	printf("'z': FT %i, Original %i\n", ft_toupper('z'), toupper('z'));
	printf("265: FT %i, Original %i\n", ft_toupper(265), toupper(265));
	return (0);
}
*/
