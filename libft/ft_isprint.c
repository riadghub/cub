/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:38:16 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/21 20:46:54 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("caractere imprimable OUI (65) = %d\n", ft_isprint(65));
	printf("caractere imprimable NON(129) = %d\n", ft_isprint(129));
	return (0);
}
*/
