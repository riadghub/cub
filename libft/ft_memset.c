/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:30:33 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/21 21:30:52 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t count)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < count)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>
int	main(void)
{
	char buffer[50] = " ceci est un test ";
	int c = '*';
	size_t count = 10;

	printf("avant memset: %s\n", buffer);
	ft_memset(buffer, c, count);
	printf("apres memset: %s\n", buffer);
	printf("\n");
	return(0);
}
*/
