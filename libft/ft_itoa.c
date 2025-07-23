/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:53:35 by lsadi             #+#    #+#             */
/*   Updated: 2025/03/11 14:31:09 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*result;
	size_t			len;
	unsigned int	num;

	len = get_len(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
	{
		return (NULL);
	}
	result[len] = '\0';
	if (n < 0)
		num = -n;
	else
		num = n;
	while (len > 0)
	{
		len--;
		result[len] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
    int		test[] = {-2147483648, 0,  2147483647};
    size_t	num;
    size_t	i;
    int		n;
    char	*result;

    num = sizeof(test) / sizeof(test[0]);
    i = 0;
    while (i < num)
    {
	    printf("Test de la valeur n = %d\n", test[i]);
	    n = test[i];
	    result = ft_itoa(n);
	    if (result)
	    {
	    	printf("RESULT (%d) = \"%s\"\n\n", n, result);
	    	free(result);
	    }
	    else
	    {
		    printf("ft_itoa(%d) a echoue (retourne NULL)\n", n);
	    }
	    i++;
    }
    return (0);
}*/
