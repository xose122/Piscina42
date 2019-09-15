/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01 main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:14:08 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/14 11:14:12 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str, int *n_str);
void	ft_rec_allcomb(int *conditions, int **mat, int fila, int column);

int		ft_atoi(char *str)
{
	int i;
	int mult;
	int result;

	result = 0;
	mult = 1;
	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' ||
	str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] > '0' && str[i] < '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * mult);
}

int		main(int argc, char **argv)
{
	int i;
	int nparameters;
	int *bordes;
	char **strsplitted;
	int **mat;

	if(argc > 1)
	{
		bordes = malloc(sizeof(int) * 16);
		mat = (int **)malloc(4 * sizeof(int *));
		i = 0;
    	while(i < 4)
    	{
        	mat[i] = (int *)malloc(4 * sizeof(int));
        	i++;
    	}
		i = 0;
		nparameters = 0;
		strsplitted = ft_split(argv[1], &nparameters);
		while (i < nparameters)
		{
			bordes[i] = ft_atoi(strsplitted[i]);
			i++;
		}
		ft_rec_allcomb(bordes, mat, 3, 3);
	}
}
