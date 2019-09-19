/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:06:39 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/11 16:06:40 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_put_hex(int n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 16)
	{
		ft_put_hex(n / 16);
		ft_put_hex(n % 16);
	}
	else
	{
		write(1, &(hex[n]), 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			write(1, "\\", 1);
			if (str[i] < 16)
			{
				write(1, "0", 1);
			}
			ft_put_hex(str[i]);
		}
		else
		{
			write(1, &(str[i]), 1);
		}
		i++;
	}
}
