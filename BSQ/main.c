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

int 	ft_max_pos_cuad(int **tab, int nrow, t_point *actual)
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

void	ft_max_cuad(int **tab, int ncol, int nrow, t_point *actual)
{
	int i;
	int j;
	int max;
	int cont;

	max = ft_max_pos_cuad(tab, nrow, actual);
	j = 0;
	while (j < max && j + (*actual).j < ncol){
		i = 0;
		cont = 0;
		while (i < max && i == cont){
			if(tab[i + (*actual).i][j + (*actual).j] == 0){
				cont++;
			}
			i++;
		}
		max = i - 1;
		j++;
	}
	if(j < max)
		max = j;
	(*actual).value = max;
	printf("En el punto i:%d j:%d el cuadrado es: %d\n", (*actual).i, (*actual).j, (*actual).value);
}

int		**ft_nombre1(int **tab, int ncol, int nrow, char *cset)
{
	int i;
	int j;
	t_point max;
	t_point actual;

	max.value = 0;
	i = 0;
	while (i < nrow)
	{
		j = 0;
		while (j < ncol)
		{
			actual.i = i;
			actual.j = j;
			if(tab[i][j] == 0)
			{
				ft_max_cuad(tab, ncol, nrow, &actual);
				if(actual.value > max.value)
					max = actual;
				}
			j++;
		}
		i++;
	}
	printf("En el punto i:%d j:%d el cuadrado es: %d\n", max.i, max.j, max.value);
}

int		main(int argc, char **argv)
{
	int		**tab;
	int		nrow;
	int		ncol;
	char	*cset;

	if (argc == 2)
	{
		tab = parse_file(argv[1], &ncol, &nrow, &cset);
		ft_nombre1(tab, ncol, nrow, cset);
	}
}
