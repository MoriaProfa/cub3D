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
	size_t i;

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
