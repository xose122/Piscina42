/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:59:35 by jgomez-b          #+#    #+#             */
/*   Updated: 2019/09/24 13:59:36 by jgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_lib.h"

int		ft_ndigit(int nb)
{
	int n;

	n = 1;
	while (nb > 9)
	{
		nb /= 10;
		n++;
	}
	return (n);
}

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int		*parse_line(char *line, char *cset)
{
	int i;
	int *row;

	row = (int*)malloc(sizeof(int) * ft_strlen(line));
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == cset[0])
			row[i] = 0;
		else if (line[i] == cset[1])
			row[i] = 1;
		else if (line[i] == cset[2])
			row[i] = 2;
		i++;
	}
	return (row);
}

int		**merge(char *buffer, int *ncol, int *nrow, char **cset)
{
	char	**str_spl;
	int		strc;
	int		i;
	int		**tab;

	i = 0;
	str_spl = ft_split(buffer, &strc, '\n');
	tab = (int**)malloc(sizeof(int*) * (strc - 1));
	*cset = (char*)malloc(sizeof(char) * 3);
	*nrow = strc - 1;
	*ncol = ft_strlen(str_spl[2]);
	while (i < 3)
	{
		(*cset)[i] = str_spl[0][ft_ndigit(*nrow) + i];
		i++;
	}
	i = 0;
	while (i < strc - 1)
	{
		tab[i] = parse_line(str_spl[i + 1], *cset);
		i++;
	}
	return (tab);
}

int		**parse_file(char *pathname, int *ncol, int *nrow, char **cset)
{
	int		fd;
	int		sz;
	char	*strin;
	int		**ret;

	strin = (char *)malloc(10000 * sizeof(char));
	fd = open(pathname, O_RDONLY);
	sz = read(fd, strin, 10000);
	strin[sz] = '\0';
	ret = merge(strin, ncol, nrow, cset);
	return (ret);
}