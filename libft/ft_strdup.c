/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:01:01 by astehl            #+#    #+#             */
/*   Updated: 2026/04/21 19:38:02 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (dest != NULL)
	{
		while (s[i])
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	const char *s = "teststring";
	char *result_strdup = strdup(s);	
	char *result_ft = ft_strdup(s);

	printf("strdup: %s\n", result_strdup);
	printf("ft_strdup: %s\n", result_ft);
	
	free(result_strdup);
	free(result_ft);
	return (0);
}
*/
