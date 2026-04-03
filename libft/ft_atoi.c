/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:33:57 by astehl            #+#    #+#             */
/*   Updated: 2024/10/16 12:53:28 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	numcheck(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

static int	signcheck(char c)
{
	if (c == 45)
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ((nptr[i] == 43 || nptr[i] == 45))
	{
		sign = signcheck(nptr[i]);
		i++;
	}
	while (numcheck(nptr[i]) != 0)
	{
		result *= 10;
		result += (nptr[i] - '0');
		if (numcheck(nptr[i + 1]) == 0)
			break ;
		i++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	printf("FT %i\n", ft_atoi("    +-125 25"));
	printf("Orig %i\n\n", atoi("    +-125 25"));
	printf("FT %i\n", ft_atoi("        -125 klo"));
    printf("Orig %i\n\n", atoi("        -125 klo"));
	printf("FT %i\n", ft_atoi("---256"));
    printf("Orig %i\n\n", atoi("---256"));
	printf("FT %i\n", ft_atoi("as-256"));
    printf("Orig %i\n\n", atoi("as-256"));
	printf("FT %i\n", ft_atoi("-256ksa"));
    printf("Orig %i\n\n", atoi("-256ksa"));
	printf("FT %i\n", ft_atoi("+256"));
    printf("Orig %i\n\n", atoi("+256"));
	printf("FT %i\n", ft_atoi("     +256"));
    printf("Orig %i\n\n", atoi("     +256"));
	printf("FT %i\n", ft_atoi("++256"));
    printf("Orig %i\n\n", atoi("++256"));
	printf("FT %i\n", ft_atoi("+256    285"));
    printf("Orig %i\n\n", atoi("+256    285"));
	return (0);
}*/
