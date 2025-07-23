/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:26:53 by lsadi             #+#    #+#             */
/*   Updated: 2024/11/28 15:16:43 by lsadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <fcntl.h>
int	main(void)
{
	int fd = open("fd.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
	{
		return(1);
	}
	ft_putchar_fd('c', fd);
	close(fd);
}*/
