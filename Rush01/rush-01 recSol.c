/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01 recSol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:12:33 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/14 11:12:36 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		valid_cardinal_point(int i, int condition, int **mat)
{
	int j;
	int valid;

	valid = 1;
	j = 0;
	while (valid && j < condition - 1)
	{
		if(i / 4 == 0 && mat[i%4][condition - 1] <= mat[i%4][condition] && mat[i % 4][j] >= mat[i % 4][j + 1])
			valid = 0;
		else if(i / 4 == 1 && mat[i%4][condition - 1] <= mat[i%4][condition] && mat[i % 4][3 - j] >= mat[i % 4][3 - j - 1])
			valid = 0;
		else if(i / 4 == 2 && mat[i%4][condition - 1] <= mat[i%4][condition] && mat[j][i % 4] >= mat[j + 1][i % 4])
			valid = 0;
		else if(i / 4 == 3 && mat[i%4][condition - 1] <= mat[i%4][condition] && mat[3-j][i % 4] >= mat[3 - j - 1][i % 4])
			valid = 0;
		j++;
	}
	return (valid);
}

int		valid_pos(int *conditions, int **mat)
{
	int i;
	int valid;

	valid = 1;
	i = 0;
	while(valid && i < 16)
	{
		valid = valid_cardinal_point(i, conditions[i], mat);
		i++;
	}
	return (valid);
}

void	print_arr(int **mat)
{
	int i;
	int j;
	i = 0;
	while (i < 4){
		j = 0;
		while (j < 4){
			printf("%d ", mat[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
}

void	ft_rec_allcomb(int *conditions, int **mat, int fila, int column)
{
	while(mat[fila][column] < 3)
	{
		mat[fila][column]++;
		if (column > 0)
			ft_rec_allcomb(conditions, mat, fila, column - 1);
		else if (fila > 0)
			ft_rec_allcomb(conditions, mat, fila - 1, 3);
	}
	print_arr(mat);
	mat[fila][column] = 0;
	if(column < 3)
		ft_rec_allcomb(conditions, mat, fila, column + 1);
	else if(fila < 3)
		ft_rec_allcomb(conditions, mat, fila + 1, 0);
}
