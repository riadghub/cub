/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:31:01 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/27 14:38:52 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>
int main(void)
{
    char	str1[] = "Bonjour, Bonsoir!";
    int		arr[5] = {1, 2, 3, 4, 5};
    int		i;

    //mise a zero d'une chaine partielle
    printf("TEST 1 Avant : \"%s\"\n", str1);
    ft_bzero(str1 + 7, 6);
    printf("TEST 1 Après : \"%s\"\n", str1);
    
    //mise a zero partielle d'un tableau d'entier
    printf("\nTEST 2 Avant: ");
    i = 0;
    while (i < 5)
    {
	    printf("%d ", arr[i]);
	    i++;
    }
    printf("\n");
    ft_bzero(arr, 3 * sizeof(int));
    
    printf("TEST 2 Après: ");
    i = 0;
    while (i < 5)
    {
	    printf("%d ", arr[i]);
	    i++;
    }
    printf("\n");

    return (0);
}*/
