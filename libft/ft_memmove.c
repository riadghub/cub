/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:51:28 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/28 14:32:41 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if ((!dst && !src) && size > 0)
		return (NULL);
	if (d > s)
	{
		while (size--)
		{
			d[size] = s[size];
		}
	}
	else
	{
		while (size--)
		{
			*d++ = *s++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
int main(void)
{

    char src1[] = "Bonbon, chocolat !";
    char dst1[30];
    ft_memmove(dst1, src1, sizeof(src1));
    printf("Test 1 :\n");
    printf("Source : \"%s\"\n", src1);
    printf("Destination: \"%s\"\n\n", dst1);

    char str2[] = "Bonbon, chocolat !";
    ft_memmove(str2 + 7, str2,  6);
    printf("Test 2 :\n");
    printf("chevauchement source < destination : \"%s\"\n\n", str2);


    char str3[] = "bonbon, chocolat !";
    ft_memmove(str3, str3 + 7, 6);
    printf("Test 3 :\n");
    printf("chevauchement destination < source : \"%s\"\n", str3);

    printf("\n");
    return (0);
}*/
