/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:37:59 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/21 20:43:51 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("represente par ascii OUI (42) = %d\n", ft_isascii(42));
	printf("represente par ascii NON (128) = %d\n", ft_isascii(128));
	return (0);
}*/
