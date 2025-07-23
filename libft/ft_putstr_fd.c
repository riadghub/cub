/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:51:56 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/24 20:58:38 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s++, 1);
	}
}
/*
#include <fcntl.h>
int	main(void)
{

	int fd = open("fd.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
		return (1);
	ft_putstr_fd("Bonsoir !", fd);
	close(fd);
}*/
