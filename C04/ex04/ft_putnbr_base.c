/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:46:28 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/12 18:46:31 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

int		ft_contains(char *str, char coincidence, int n)
{
	int found;
	int i;

	i = n;
	found = -1;
	while (str[i] != '\0' && found == -1)
	{
		if (str[i] == coincidence)
		{
			found = i;
		}
		i++;
	}
	return (found);
}

int		ft_valid_base(char *base)
{
	int i;
	int valid;

	valid = 1;
	i = 0;
	if (ft_contains(base, '+', 0) != -1 || ft_contains(base, '-', 0) != -1 ||
	ft_strlen(base) < 2)
	{
		valid = 0;
	}
	while (valid && base[i] != '\0')
	{
		if (ft_contains(base, base[i], i + 1) != -1)
		{
			valid = 0;
		}
		i++;
	}
	return (valid);
}

void	ft_rec_putnbr_base(int nbr, char *base)
{
	int size;

	size = ft_strlen(base);
	if (nbr == -2147483648)
	{
		ft_rec_putnbr_base(nbr / 10, base);
		write(1, &(base[8]), 1);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_rec_putnbr_base(-nbr, base);
	}
	else if (nbr < size)
	{
		write(1, &(base[nbr]), 1);
	}
	else
	{
		ft_rec_putnbr_base(nbr / size, base);
		ft_rec_putnbr_base(nbr % size, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_valid_base(base))
	{
		ft_rec_putnbr_base(nbr, base);
	}
}
