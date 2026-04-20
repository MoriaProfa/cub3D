/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:53:12 by astehl            #+#    #+#             */
/*   Updated: 2026/04/20 17:21:10 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*grow_array(void *old_array, size_t old_capacity, size_t new_capacity,
		size_t size)
{
	void	*new_array;

	new_array = ft_calloc(new_capacity, size);
	if (!new_array)
		return (NULL);
	ft_memcpy(new_array, old_array, old_capacity * size);
	free(old_array);
	return (new_array);
}

size_t	get_array_size(char **array)
{
	size_t	i;

	i = 0;
	if (!array || !array[0])
		return (0);
	while (array && array[i])
		i++;
	return (i);
}

void	free_array(char **array)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (!array)
		return ;
	size = get_array_size(array);
	while (i < size)
		free(array[i++]);
	free(array);
}
