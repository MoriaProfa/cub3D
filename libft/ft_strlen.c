/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:52:14 by astehl            #+#    #+#             */
/*   Updated: 2024/09/10 18:41:07 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	printf("Test: FT %zu, Original %lu\n", ft_strlen("Test"), strlen("Test"));
	printf("Hello I am here: FT %zu, ", ft_strlen("Hello I am here"));
	printf("Original %lu\n", strlen("Hello I am here"));
	return (0);
}
*/
