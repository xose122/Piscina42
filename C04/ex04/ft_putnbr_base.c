/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:46:28 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/12 18:46:31 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int		len;
	char	c;

	len = 0;
	c = str[len];
	while (c != '\0')
	{
		len++;
		c = str[len];
	}
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int size;

	size = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nbr, base);
	}
	else if (nbr < size)
	{
		write(1, &(base[nbr]), 1);
	}
	else
	{
		ft_putnbr_base(nbr / size, base);
		ft_putnbr_base(nbr % size, base);
	}
}

int main(){
	ft_putnbr_base(-10, "01");
}
