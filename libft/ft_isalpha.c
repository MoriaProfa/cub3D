/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:12:09 by astehl            #+#    #+#             */
/*   Updated: 2024/09/03 17:22:59 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	printf("0: FT %i, Original %i\n", ft_isalpha(0), isalpha(0));
	printf("5: FT %i, Original %i\n", ft_isalpha(5), isalpha(5));
	printf("90: FT %i, Original %i\n", ft_isalpha(90), isalpha(90));
	printf("105: FT %i, Original %i\n", ft_isalpha(105), isalpha(105));
	printf("144: FT %i, Original %i\n", ft_isalpha(144), isalpha(144));
	printf("545: FT %i, Original %i\n", ft_isalpha(545), isalpha(545));
	return (0);
}
*/
