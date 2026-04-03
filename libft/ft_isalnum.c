/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:43:08 by astehl            #+#    #+#             */
/*   Updated: 2024/09/03 17:29:30 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) != 0 || ft_isdigit(c) != 0)
		return (8);
	else
		return (0);
}
/*
//compile ft_isalpha.c and ft_isdigit.c with it!
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	printf("0: FT %i, Original %i\n", ft_isalnum(0), isalnum(0));
	printf("5: FT %i, Original %i\n", ft_isalnum(5), isalnum(5));
	printf("48: FT %i, Original %i\n", ft_isalnum(48), isalnum(48));
	printf("59: FT %i, Original %i\n", ft_isalnum(59), isalnum(59));
	printf("73: FT %i, Original %i\n", ft_isalnum(73), isalnum(73));
	printf("94: FT %i, Original %i\n", ft_isalnum(94), isalnum(94));
	printf("115: FT %i, Original %i\n", ft_isalnum(115), isalnum(115));
	printf("144: FT %i, Original %i\n", ft_isalnum(144), isalnum(144));
	return (0);
}
*/
