/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:25:32 by astehl            #+#    #+#             */
/*   Updated: 2026/04/21 19:43:36 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (result != NULL)
	{
		while (s[i])
		{
			result[i] = (*f)(i, s[i]);
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
/*
#include <stdio.h>
#include <string.h>

char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

int main(void)
{
	char *s;
	printf("Will put the string to upper case\n");
	s = ft_strmapi("test", to_upper);
	printf("%s\n", s);
	free(s);
	return (0);
}
*/
