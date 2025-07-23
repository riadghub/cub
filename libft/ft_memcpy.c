/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:30:20 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/28 15:13:47 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if ((!dst && !src) && size > 0)
		return (NULL);
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
int main(void)
{
    char src1[] = "Bonjour, bonsoir !";
    char dst1[20];
    ft_memcpy(dst1, src1, sizeof(src1));
    printf("TEST 1 copie chaine de caractere \n");
    printf("Source : \"%s\"\n", src1);
    printf("Destination : \"%s\"\n\n", dst1);


    int src2[] = {1, 2, 3, 4, 5};
    int dst2[5];
    int	i;
    ft_memcpy(dst2, src2, 5 * sizeof(int));
    printf("TEST 2 copie d'un tableu d'entier \n");
    printf("Source : {1, 2, 3, 4, 5}\n");
    printf("Destination : {");
   
    i = 0;
    while(i < 5)
    {
	    printf("%d", dst2[i]);
	    if (i < 4)
		    printf(", ");
	    i++;
    }
    printf("}\n\n");

    char src3[] = "Ceci est un test.";
    char dst3[20] = {0};
    ft_memcpy(dst3, src3, 4);
    printf("TEST 3 copie de 4 octets \n");
    printf("Source : \"%s\"\n", src3);
    printf("Destination après copie partielle : \"%s\"\n\n", dst3);
    return (0);
}*/
