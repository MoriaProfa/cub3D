/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:20:18 by astehl            #+#    #+#             */
/*   Updated: 2024/09/11 14:07:10 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char dest[50] = "testing the test";
    char c[50] = "testing the test";
    char src[50] = "hello there";
    
    printf("Src: %s\n", src);
    printf("Original dest/control: %s/%s\n", dest, c);
    ft_memmove(dest, src, 50);
    printf("Changed dest by ft_memmove %s\n", dest);
    memmove(c, src, 50);
    printf("Changed control by memmove: %s\n", c);
	
	return (0);
}
*/
