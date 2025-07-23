/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:02:58 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/25 17:20:25 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
static void	to_upper(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		*c = *c - 32;
	}
}

static void	my_index(unsigned int i, char *c)
{
	if (*c != '\0')
	{
		*c = *c + (i % 10);
	}	
}

#include <stdio.h>

int main(void)
{
    char str1[] = "bonjour, bonjour";
    char str2[] = "abcdef";

    printf("avant upper: %s\n", str1);
    ft_striteri(str1, to_upper);
    printf("apres upper: %s\n", str1);

    printf("avant index : %s\n", str2);
    ft_striteri(str2, my_index);
    printf("apres index : %s\n", str2);
    return (0);
}
*/
