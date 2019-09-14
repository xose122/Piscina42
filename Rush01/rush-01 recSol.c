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

int		valid_cardinal_point(int i, int **mat)
{
	int j;
	int valid;

	valid = 1;
	j = 0;
	if (i / 4 == 0)
	{
		while (valid && j < conditions[i])
		{
			if(mat[i%4][j] >= mat[i%4][j+1])
				valid = 0;
			j++;
		}
	}
	else if (i / 4 == 1)
	{
		while (valid && j < conditions[i])
		{
			if(mat[i%4][3-j] >= mat[i%4][3-j-1])
				valid = 0;
			j++;
		}
	}
}

int		valid_pos(int *conditions, int **mat)
{
	int i;
	int j;
	int valid;

	valid = 1;
	i = 0;
	while(valid && i < 16)
	{
		j = 0;
		if(i / 4 == 0)
		{
			while(valid && j < conditions[i] - 1)
			{
				if(mat[i%4][j] >= mat[i%4][j+1])
					valid = 0;
			}
		}
	}
}

void	ft_rec_allcomb(int *conditions, int **mat, int fila, int column)
{
	if(fila < 4)
	{

	}
}
