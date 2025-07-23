/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:31:31 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/21 21:33:36 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;

	last = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
		{
			last = (char *)str;
		}
		str++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)str);
	}
	return (last);
}

/*
#include <stdio.h>
int main()
{
    
    const char str1[] = "Bonjour, bonjour, merci !";
    char c1 = 'o';
    char *result = ft_strrchr(str1, c1);
    printf("TEST 1 caractere present plusieurs fois :\n");
    printf("Chaîne : \"%s\"\n", str1);
    printf("Dernier caractere recherché : '%c'\n", c1);
    printf("Resultat : \"%s\"\n\n", result ? result : "NULL");

    
    const char str2[] = "Bonjour, merci !";
    char c2 = 'm';
    result = ft_strrchr(str2, c2);
    printf("TEST 2 caractere unique dans la chaine :\n");
    printf("Chaîne : \"%s\"\n", str2);
    printf("Dernier caractere recherche : '%c'\n", c2);
    printf("Resultat : \"%s\"\n\n", result ? result : "NULL");

    
    const char str3[] = "Bonjour, merci !";
    char c3 = 'z';
    result = ft_strrchr(str3, c3);
    printf("TEST 3 caractere absent de la chaine :\n");
    printf("Chaîne : \"%s\"\n", str3);
    printf("Caractere recherche : '%c'\n", c3);
    printf("Resultat : \"%s\"\n\n", result ? result : "NULL");
    return (0);
}*/
