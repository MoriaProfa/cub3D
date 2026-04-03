/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:13:38 by astehl            #+#    #+#             */
/*   Updated: 2024/10/16 10:47:36 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;

	i = 0;
	cs = (unsigned char *)s;
	while (i < n)
	{
		if (cs[i] == (unsigned char)c)
			return (&cs[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	const char *s = "test";
	const char c = 'i';
	int n = 3;
	char *ret1 = ft_memchr(s, c, n);
	char *ret2 = memchr(s, c, n);
	printf("FT: %s\n", ret1);
	printf("Original: %s\n", ret2);
	return (0);
}
*/
