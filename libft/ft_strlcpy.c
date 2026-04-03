/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:21:21 by astehl            #+#    #+#             */
/*   Updated: 2024/10/15 13:39:04 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <bsd/string.h> //compile with -lbsd
int main(void)
{
	char dst[100] = "";
	const char src[] = "lorem ipsum dolor sit amet";
	size_t size = 0;

//	printf("FT: %zu %s %s %zu\n", ft_strlcpy(dst, src, size), dst, src, size);
	printf("Original: %zu %s %s %zu\n", strlcpy(dst, src, size), dst, src, size);
	return (0);
}
*/
