/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:59:49 by astehl            #+#    #+#             */
/*   Updated: 2024/10/15 15:43:02 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	dest = (void *)d;
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char dest[20] = "t";
	char c[20] = "t";
	char src[20] = "hello there";
	
	printf("Src: %s\n", src);
	printf("Original dest/control: %s/%s\n", dest, c);
	ft_memcpy(dest, src, 3);
	printf("Changed dest by ft_memcpy %s\n", dest);
	memcpy(c, src, 3);
	printf("Changed control by memcpy: %s\n", c);
	return (0);
}
*/
