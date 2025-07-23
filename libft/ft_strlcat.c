/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:25:02 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/29 17:14:15 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)

{
	unsigned int	dlen;
	unsigned int	slen;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	dlen = j;
	slen = ft_str_len(src);
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (src[i] != '\0' && i < size - dlen -1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dlen + slen);
}
/*
#include <stdio.h>
int	main(void)
{
	char dest[20] = "bonjour";
	char src[] = "merci";
	size_t size;

	printf("Avant strlcat = \n");
	printf("dest : %s\n", dest);
	printf("src : %s\n", src);

	size_t result = ft_strlcat(dest, src, size);

	printf("\nApres strlcat = \n");
        printf("dest : %s\n", dest);
        printf("result : %zu\n", result);
	return (0);
}
*/
