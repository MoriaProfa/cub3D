/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:02:09 by astehl            #+#    #+#             */
/*   Updated: 2024/09/10 18:36:54 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*c;

	i = 0;
	c = (unsigned char *)s;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
#include <strings.h>
int main(void)
{
	char s[50] = "Hello there";
	char c[50] = "Hello there";
    printf("String: %s\n", s);
    ft_bzero(&s[5], 3);
	printf("Changed by ft_bzero: %s\n", s);
	printf("Control: %s\n", c);
	bzero(&c[5], 3);
    printf("Changed by bzero: %s\n", c);
	return (0);
}
*/
