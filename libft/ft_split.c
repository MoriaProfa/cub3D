/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:39:22 by astehl            #+#    #+#             */
/*   Updated: 2026/04/21 17:44:27 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strings(char const *s, char c)
{
	size_t			count;
	unsigned int	i;

	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	if (s[0] == c)
		count--;
	if (s[ft_strlen(s) - 1] == c)
		count--;
	return (count);
}

static unsigned int	get_len(char const *s, char c, unsigned int start)
{
	size_t	len;
	size_t	strlen;

	len = 0;
	strlen = ft_strlen(s);
	while (s[start] != c && s[start] != '\0' && len <= strlen)
	{
		len++;
		start++;
	}
	return (len);
}

static void	free_result(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
}

static char	**fill_array(char const *s, char c, char **result, size_t size)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	len;

	i = 0;
	start = 0;
	while (s[start] == c)
		start++;
	while (i < size)
	{
		len = get_len(s, c, start);
		result[i] = ft_substr(s, start, len);
		if (result[i] == NULL)
			return (free_result(result, (int) i), NULL);
		start += len;
		while (s[start] == c)
			start++;
		i++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	size_t			size;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
		size = 0;
	else
		size = count_strings(s, c);
	result = malloc(sizeof (char *) * (size + 1));
	if (result != NULL)
	{
		result = fill_array(s, c, result, size);
		if (result == NULL)
			return (NULL);
		result[size] = NULL;
	}
	return (result);
}
/*
#include <stdio.h>

int main(void)
{
	int i = 0;
	char **result = ft_split("xxxxxxxxhello!", 'x');
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
*/
