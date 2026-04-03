/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:28:44 by astehl            #+#    #+#             */
/*   Updated: 2024/10/16 12:31:30 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] != '\0' && big[i + j] == little[j])
		{
			if (i + j < len && little[j + 1] == '\0')
				return ((char *) &big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <bsd/string.h> //compile with -lbsd
int main(void)
{
	printf("FT: %s\n", ft_strnstr("helloworldowo", "", 10));
	printf("Orig: %s\n\n", strnstr("helloworldowo", "", 10));
	return (0);
}
*/
