/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:33:52 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/21 20:25:36 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("retourne 1 si digit ('5') = %d\n", ft_isdigit('5'));
	printf("retourne 0 si pas digit ('a') = %d\n", ft_isdigit('a'));
	return (0);
}*/			
