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

void	ft_putchar(char c)
{
	write(1, &c, sizeof(c));
}

int		ft_valid_base(char *str)
{
	int	i;
	int	j;

	if (str[0] == '\0')
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_write_nbr(int nb, char *str, unsigned int nbase)
{
	unsigned int nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= nbase)
		ft_write_nbr(nbr / nbase, str, nbase);
	ft_putchar(str[nbr % nbase]);
}

void	ft_putnbr_base(int nb, char *str)
{
	unsigned int str_length;

	str_length = ft_valid_base(str);
	if (str_length == 0)
		return ;
	ft_write_nbr(nb, str, str_length);
}

int main()
{
	ft_putnbr_base(10, "01234567");
}