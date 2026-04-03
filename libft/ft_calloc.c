/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:03:58 by astehl            #+#    #+#             */
/*   Updated: 2024/09/13 11:57:17 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;

	c = malloc(nmemb * size);
	if (c != NULL)
		ft_bzero(c, nmemb * size);
	return (c);
}
/*
#include <stdio.h>
int main(void) {
   int n = 5;
   int i = 0;
   int *array_cal;
   int *array_ft;
   
   array_cal = (int*)calloc(n, sizeof(int));
   printf("calloc:\n");
   while (i < n)
   {
		printf("%d ", array_cal[i]);
		i++;
   }
   free(array_cal);

   i = 0;
   array_ft = (int*)ft_calloc(n, sizeof(int));
   printf("\n\nft_calloc:\n");
   while (i < n)
   {
        printf("%d ", array_ft[i]);
        i++;
   }
   printf("\n");
   free(array_ft);
   return 0;
}
*/
