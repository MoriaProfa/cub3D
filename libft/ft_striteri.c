/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:09:37 by astehl            #+#    #+#             */
/*   Updated: 2024/10/03 14:25:58 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
#include <stdio.h>
#include <string.h>

void	ft_printstr(unsigned int i, char *s)
{
	unsigned int j = 0;
	(void)i;
	while (s[j])
	{
		write(1, &s[j], 1);
		j++;
	}
	write(1, "\n", 1);
}
int main(void)
{
    ft_striteri("testing", ft_printstr);
    return (0);
}
*/
