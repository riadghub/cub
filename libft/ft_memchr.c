/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:29:16 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/21 21:12:30 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t count)
{
	unsigned char		*ptr;
	unsigned char		c_char;
	size_t				i;

	ptr = (unsigned char *)s;
	c_char = (unsigned char)c;
	i = 0;
	while (i < count)
	{
		if (ptr[i] == c_char)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main(void)
{
    char str1[] = "Bonjour, merci !";
    char c = 'm';
    char *result;

    result = ft_memchr(str1, c, sizeof(str1));
    if (result)
    {
        printf("Test 1 :\n");
        printf("Chaîne : \"%s\"\n", str1);
        printf("Caractère recherché : '%c'\n", c);
        printf("Résultat : \"%s\"\n\n", result);
    }

    c = 'z';
    result = ft_memchr(str1, c, sizeof(str1));
    if (result)
    {
        printf("Test 2 :\n");
        printf("Chaîne : \"%s\"\n", str1);
        printf("Caractère recherché : '%c'\n", c);
        printf("Résultat : \"%s\"\n\n", result);
    }
    else
    {
        printf("Test 2 :\n");
        printf("Caractère '%c' non trouvé dans la chaîne \"%s\"\n\n", c, str1);
    }

    int arr[] = {1, 2, 3, 4, 5};
    int target = 5;
    int *int_result;
//    sizeof(target);
    
    int_result = ft_memchr(arr, target, 5 * sizeof(target));
    if (int_result)
    {
        printf("Test 3 :\n");
        printf("Tableau : {1, 2, 3, 4, 5}\n");
        printf("Entier recherché : %lu\n", sizeof(target));
        printf("Résultat : %d\n\n", *int_result);
    }
    
    c = 'B';
    result = ft_memchr(str1, c, 0);
    if (result)
    {
        printf("Test 4 :\n");
        printf("Chaîne : \"%s\"\n", str1);
        printf("Caractère recherché : '%c'\n", c);
        printf("Résultat : \"%s\"\n\n", result);
    } 
    else
    {
        printf("Test 4 :\n");
        printf("Aucune recherche effectuée avec une taille 0\n\n"); 
    }
}	
*/
