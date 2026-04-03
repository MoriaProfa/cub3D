/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:55:17 by astehl            #+#    #+#             */
/*   Updated: 2024/10/15 16:41:18 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;

	i = ft_strlen(s);
	cc = (char) c;
	if (cc == '\0')
		return ((char *) &s[ft_strlen(s)]);
	while (*s && i >= 0)
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	const char *s = "hello world!";
	int c = 90;

	printf("FT: %s\n", ft_strrchr(s, c));
	printf("Orig: %s\n", strrchr(s, c));
	return (0);
}
*/
