/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:59:28 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/24 13:59:30 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_print_sol(int **tab, int *borders, char *cset, t_point max)
{
	int i;
	int j;

	i = 0;
	while (i < borders[0])
	{
		j = 0;
		while (j < borders[1])
		{
			if (i >= max.i && i < max.i + max.value &&
			j >= max.j && j < max.j + max.value)
			{
				write(1, &(cset[2]), 1);
			}
			else
			{
				write(1, &(cset[tab[i][j]]), 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		ft_max_pos_cuad(int **tab, int nrow, t_point *actual)
{
	int i;
	int j;
	int max;

	max = 0;
	i = (*actual).i;
	j = (*actual).j;
	while (i < nrow && tab[i][j] == 0)
	{
		max++;
		i++;
	}
	return (max);
}

void	ft_max_cuad(int **tab, int *borders, t_point *actual)
{
	int i;
	int j;
	int max;
	int cont;

	max = ft_max_pos_cuad(tab, borders[0], actual);
	j = 0;
	cont = 1;
	while (j < max && j < i && j + (*actual).j < borders[1])
	{
		i = 0;
		cont = 0;
		while (i == cont && i < max)
		{
			if (tab[i + (*actual).i][j + (*actual).j] == 0)
			{
				cont++;
			}
			i++;
		}
		max = cont;
		if (cont > j)
			j++;
	}
	(*actual).value = j;
}

void	ft_calc_max_cuad(int **tab, int *borders, char *cset)
{
	int		i;
	int		j;
	t_point max;
	t_point actual;

	max.value = 0;
	i = 0;
	while (i < borders[0])
	{
		j = 0;
		while (j < borders[1])
		{
			actual.i = i;
			actual.j = j;
			if (tab[i][j] == 0)
			{
				ft_max_cuad(tab, borders, &actual);
				if (actual.value > max.value)
					max = actual;
			}
			j++;
		}
		i++;
	}
	ft_print_sol(tab, borders, cset, max);
}

int		main(int argc, char **argv)
{
	int		**tab;
	int		*borders;
	char	*cset;

	if (argc > 1)
	{
		borders = (int*)malloc(2 * sizeof(int));
		tab = parse_file(argv[1], &borders[1], &borders[0], &cset);
		ft_calc_max_cuad(tab, borders, cset);
	}
	else if (argc == 1)
	{
		borders = (int*)malloc(2 * sizeof(int));
		printf("%s\n", ft_read(0, 10000));
		//tab = parse_file(ft_read(0, 10000), &borders[1], &borders[0], &cset);
		//ft_calc_max_cuad(tab, borders, cset);
	}
	return (0);
}
