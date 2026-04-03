/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:38:05 by astehl            #+#    #+#             */
/*   Updated: 2024/10/21 17:00:03 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (len > ft_strlen(s) || start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	result = malloc(sizeof(char) * (len + 1));
	if (result != NULL)
	{
		while (i < len)
		{
			result[i] = s[start + i];
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
	char const *s = "teststring";
	char *result = ft_substr(s, 5, 6);
	printf("result is %s", result);
	free(result);
	return (0);
}
*/
