/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:28:19 by astehl            #+#    #+#             */
/*   Updated: 2024/10/16 10:50:18 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cs1[i] > cs2[i])
			return (1);
		else if (cs1[i] < cs2[i])
			return (-1);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	printf("FT: ABC ABC 2 -> %i\n", ft_memcmp("ABC", "ABC", 2));
    printf("Orig: ABC ABC 2 -> %i\n\n", memcmp("ABC", "ABC", 2));
    printf("FT: ABC AB 3 -> %i\n", ft_memcmp("ABC", "AB", 3));
    printf("Orig: ABC AB 3 -> %i\n\n", memcmp("ABC", "AB", 3));
    printf("FT: ABA ABZ 3 -> %i\n", ft_memcmp("ABA", "ABZ", 3));
    printf("Orig: ABA ABZ 3 -> %i\n\n", memcmp("ABA", "ABZ", 3));
    printf("FT: ABJ ABC 3 -> %i\n", ft_memcmp("ABJ", "ABC", 3));
    printf("Orig: ABJ ABC 3 -> %i\n\n", memcmp("ABJ", "ABC", 3));
    printf("FT:  ABC 3 -> %i\n", ft_memcmp("", "ABC", 3));
    printf("Orig:  ABC 3 -> %i\n\n", memcmp("", "ABC", 3));
    printf("FT: Test Tast 3 -> %i\n", ft_memcmp("Test", "Tast", 3));
    printf("Orig: Test Tast 3 -> %i\n\n", memcmp("Test", "Tast", 3));
	return (0);
}
*/
