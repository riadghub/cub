/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:31:46 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/28 18:41:37 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str);
	return (NULL);
}
/*
#include <stdio.h>
int main(void)
{
    const char str1[] = "Bonjour, merci !";
    char c1 = 'm';
    char *result = ft_strchr(str1, c1);
    printf("TEST 1 caractere unique dans la chaine :\n");
    printf("Chaîne : \"%s\"\n", str1);
    printf("Premier Caractere recherché : '%c'\n", c1);
    printf("Résultat : \"%s\"\n\n", result ? result : "NULL");

    const char str2[] = "Bonjour, merci !";
    char c2 = 'z';
    result = ft_strchr(str2, c2);
    printf("TEST 2 caractere absent de la chaine :\n");
    printf("Chaîne : \"%s\"\n", str2);
    printf("Caractère recherché : '%c'\n", c2);
    printf("Résultat : \"%s\"\n\n", result ? result : "NULL");
    return (0);
}*/
