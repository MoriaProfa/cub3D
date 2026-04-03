/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:39:18 by astehl            #+#    #+#             */
/*   Updated: 2024/10/24 12:16:57 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			len_dst;
	unsigned int	i;
	size_t			len;

	len_dst = ft_strlen(dst);
	if (len_dst > size)
		len = ft_strlen(src) + size;
	else
		len = len_dst + ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] && len_dst < size - 1)
		{
			dst[len_dst] = src[i];
			len_dst++;
			i++;
		}
		dst[len_dst] = '\0';
	}
	return (len);
}
/*
#include <stdio.h>
#include <bsd/string.h> //compile with -lbsd
int main(void)
{
	char dst[10] = "a";
    const char src[] = "lorem ipsum dolor sit amet";
    size_t size = 0;

// 	printf("FT: %zu %s %s %zu\n", ft_strlcat(dst, src, size), dst, src, size);
 	printf("FO: %zu %s %s %zu\n", strlcat(dst, src, size), dst, src, size);
	return (0);
}
*/
