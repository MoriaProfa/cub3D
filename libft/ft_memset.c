/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:28:53 by astehl            #+#    #+#             */
/*   Updated: 2024/09/10 18:42:16 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		s2[i] = c;
		i++;
	}
	s = (void *) s2;
	return (s);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[20] = "Hello there";
    char c[20] = "Hello there";
    printf("String: %s\n", s);
    ft_memset(&s[5], 46, 3);
    printf("Changed by ft_memset: %s\n", s);
    printf("Control: %s\n", c);
    memset(&c[5], 46, 3);
    printf("Changed by memset: %s\n", c);
	return (0);
}
*/
