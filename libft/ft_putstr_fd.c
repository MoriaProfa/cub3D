/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:11:18 by astehl            #+#    #+#             */
/*   Updated: 2024/10/02 15:23:45 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	l;

	l = ft_strlen(s);
	write(fd, s, l);
}
/*
int main(void)
{
	ft_putstr_fd("hello world!", 1);
	return (0);
}
*/
