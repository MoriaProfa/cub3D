/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:10:53 by astehl            #+#    #+#             */
/*   Updated: 2024/10/16 09:49:05 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while ((cs1[i] || cs2[i]) && i < n)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	printf("FT: ABC ABC 2 -> %i\n", ft_strncmp("ABC", "ABC", 2));
	printf("Orig: ABC ABC 2 -> %i\n\n", strncmp("ABC", "ABC", 2));
	printf("FT: ABC AB 3 -> %i\n", ft_strncmp("ABC", "AB", 3));
    printf("Orig: ABC AB 3 -> %i\n\n", strncmp("ABC", "AB", 3));
	printf("FT: ABA ABZ 3 -> %i\n", ft_strncmp("ABA", "ABZ", 3));
    printf("Orig: ABA ABZ 3 -> %i\n\n", strncmp("ABA", "ABZ", 3));
	printf("FT: ABJ ABC 3 -> %i\n", ft_strncmp("ABJ", "ABC", 3));
    printf("Orig: ABJ ABC 3 -> %i\n\n", strncmp("ABJ", "ABC", 3));
	printf("FT:  ABC 3 -> %i\n", ft_strncmp("", "ABC", 3));
    printf("Orig:  ABC 3 -> %i\n\n", strncmp("", "ABC", 3));
	printf("FT: Test Tast 3 -> %i\n", ft_strncmp("Test", "Tast", 3));
    printf("Orig: Test Tast 3 -> %i\n\n", strncmp("Test", "Tast", 3));
	return (0);
}
*/
