/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:58:16 by astehl            #+#    #+#             */
/*   Updated: 2026/04/21 19:39:16 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (result != NULL)
	{
		while (i < ft_strlen(s1))
		{
			result[i] = s1[i];
			i++;
		}
		while (j < ft_strlen(s2))
		{
			result[i] = s2[j];
			j++;
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
	char const *s1 = "hello ";
	char const *s2 = "World!";
	char *result = ft_strjoin(s1, s2);
	printf("result is %s", result);
	free(result);
	return(0);
}
*/
