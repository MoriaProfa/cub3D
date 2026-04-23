/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:52:47 by astehl            #+#    #+#             */
/*   Updated: 2026/04/23 14:52:19 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	numcheck(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

static int	signcheck(char c)
{
	if (c == 45)
		return (-1);
	else
		return (1);
}

int	cub3d_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ((nptr[i] == 43 || nptr[i] == 45))
	{
		sign = signcheck(nptr[i]);
		i++;
	}
	while (numcheck(nptr[i]) != 0)
	{
		result *= 10;
		if (result > 255)
			return (result);
		result += (nptr[i] - '0');
		if (numcheck(nptr[i + 1]) == 0)
			break ;
		i++;
	}
	return (result * sign);
}
