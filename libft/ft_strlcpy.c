/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:24:48 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/21 21:37:49 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
#include <stdio.h>
int	main(void)

{
	char	src[] = "welcome !";
	char	dst[10];
	size_t size = 10;
	size_t result = ft_strlcpy(dst, src, size);
	
	printf("Source : %s\n", src);
	printf("Destination : %s\n", dst);
	printf("Longueur de la Source : %zu\n", result);
	return (0);
}*/
