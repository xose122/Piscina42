/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:47:20 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/06 12:47:24 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_number(int d00, int d01, int d10, int d11)
{
	char comma;
	char space;
	char *str;

	comma = ',';
	space = ' ';
	str = "0123456789";
	if (!(d00 == d10 && d01 == d11))
	{
		write(1, &str[d00], 1);
		write(1, &str[d01], 1);
		write(1, &space, 1);
		write(1, &str[d10], 1);
		write(1, &str[d11], 1);
		if (!(d00 == 9 && d01 == 8 && d10 == 9 && d11 == 9))
		{
			write(1, &comma, 1);
			write(1, &space, 1);
		}
	}
}

void	ft_generate_second_number(int d00, int d01)
{
	int d10;
	int d11;

	if (d01 < 9)
	{
		d11 = d01 + 1;
		d10 = d00;
	}
	else
	{
		d10 = d00 + 1;
		d11 = 0;
	}
	while (d10 <= 9)
	{
		while (d11 <= 9)
		{
			ft_print_number(d00, d01, d10, d11);
			d11++;
		}
		d10++;
		d11 = 0;
	}
}

void	ft_print_comb2(void)
{
	int d00;
	int d01;

	d00 = 0;
	while (d00 <= 9)
	{
		d01 = 0;
		while (d01 <= 9)
		{
			ft_generate_second_number(d00, d01);
			d01++;
		}
		d00++;
	}
}

int main()
{
	ft_print_comb2();
}
