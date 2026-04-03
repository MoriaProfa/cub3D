/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:21:18 by astehl            #+#    #+#             */
/*   Updated: 2024/10/21 16:45:20 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1);
	if (s1 != NULL && set != NULL)
	{
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (start < end && s1[end - 1] && ft_strchr(set, s1[end - 1]))
			end--;
	}
	result = malloc(sizeof(char) * (end - start + 1));
	if (result != NULL)
		ft_strlcpy(result, &s1[start], end - start + 1);
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
	char const *s1 = "loolhello World!ollo";
	char const *set = "ol";
	char *result = ft_strtrim(s1, set);
	printf("result is %s", result); //hello World!
	free(result);
	return (0);
}
*/
