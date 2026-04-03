/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:16:38 by astehl            #+#    #+#             */
/*   Updated: 2024/10/02 10:45:03 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_size(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n > 9)
	{
		size++;
		n /= 10;
	}
	size++;
	return (size);
}

static char	*fill_negative_result(char *result, int size, int n)
{
	result[0] = '-';
	if (n == -2147483648)
	{
		result[size - 1] = '8';
		n /= 10;
		size--;
	}
	n *= -1;
	while (size-- > 1)
	{
		result[size] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;

	size = get_size(n);
	result = malloc(sizeof(char) * (size + 1));
	if (result != NULL)
	{
		result[size] = '\0';
		if (n >= 0)
		{
			while (size-- > 0)
			{
				result[size] = n % 10 + '0';
				n /= 10;
			}
		}
		else
			fill_negative_result(result, size, n);
	}
	return (result);
}
/*
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	int n1 = 0;
	char *c_n1 = ft_itoa(n1);
	printf("%i is %s\n", n1, c_n1);
	free(c_n1);

	int n2 = -165464;
	char *c_n2 = ft_itoa(n2);
    printf("%i is %s\n", n2, c_n2);
	free(c_n2);

	int n3 = 5468413;
	char *c_n3 = ft_itoa(n3);
    printf("%i is %s\n", n3, c_n3);
	free(c_n3);

	int max = INT_MAX;
	char *c_max = ft_itoa(max);
	printf("INT_MAX %i is %s\n", max, c_max);
	free(c_max);

	int min = INT_MIN;
	char *c_min = ft_itoa(min);
	printf("INT_MIN %i is %s\n", min, c_min);
	free(c_min);

	return (0);
}
*/
