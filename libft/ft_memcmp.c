/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:40:41 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/28 17:28:10 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < size && str1[i] == str2[i])
		i++;
	if (i == size)
		return (0);
	return (str1[i] - str2[i]);
}
/*
#include <stdio.h>

int main(void)
{

    char str1[] = "Bonjour, bonsoir !";
    char str2[] = "Bonjour, bonsoir !";
    int result = ft_memcmp(str1, str2, sizeof(str1));
    printf("TEST 1 chaines identiques :\n");
    printf("Chaîne 1 : \"%s\"\n", str1);
    printf("Chaîne 2 : \"%s\"\n", str2);
    printf("Résultat : %d\n\n", result);


    char str3[] = "Bonjour, bonsoir !";
    char str4[] = "Bonjour, bonsoir ?";
    result = ft_memcmp(str3, str4, sizeof(str3));
    printf("TEST 2 difference de chaines :\n");
    printf("Chaîne 1 : \"%s\"\n", str3);
    printf("Chaîne 2 : \"%s\"\n", str4);
    printf("Résultat : %d\n\n", result);


    char str5[] = "bonjour";
    char str6[] = "bonsoir";
    result = ft_memcmp(str5, str6, 7);
    printf("TEST 3 Comparaison :\n");
    printf("Chaîne 1 : \"%s\"\n", str5);
    printf("Chaîne 2 : \"%s\"\n", str6);
    printf("Résultat : %d\n\n", result);

    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 0, 4, 5};
    result = ft_memcmp(arr1, arr2, 3 * sizeof(int));
    printf("TEST 4 tableau d'entier :\n");
    printf("Tableau 1 : {1, 2, 3, 4, 5}\n");
    printf("Tableau 2 : {1, 2, 0, 4, 5}\n");
    printf("Résultat : %d\n\n", result);
    return (0);
}*/
