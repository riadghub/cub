/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:27:41 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/28 18:42:14 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size > 0 && SIZE_MAX / size < count)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

/*
#include <stdio.h>
int	main(void)
{
	int *arr;
	size_t count = 5;
	size_t size = sizeof(int);
	size_t i = 0;

	arr = (int*)ft_calloc(count, size);
	if (!arr)
	{
		printf("Memory allocation Failed\n");
		return (1);
	}
	i = 0;
	while (i < count)
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
		i++;
	}
	i = 0;
	while (i < count)
        {
                arr[i] = i *10;
                i++;
        }

	printf("After assigning values:\n");
	i = 0;
	while (i < count)
        {
                printf("arr[%zu] = %d\n", i, arr[i]);
                i++;
        }
	free(arr);
	return (0);
}*/
