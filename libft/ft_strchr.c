/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:31:40 by astehl            #+#    #+#             */
/*   Updated: 2024/10/15 16:38:22 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	i = 0;
	cc = (char) c;
	if (cc == '\0')
		return ((char *) &s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	const char *s = "hello world!";
	int c = 108;

	printf("FT: %s\n", ft_strchr(s, c));
	printf("Orig: %s\n", strchr(s, c));	
	return (0);
}
*/
