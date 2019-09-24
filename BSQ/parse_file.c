#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_lib.h"

int		*parse_line(char *line)
{

}

int		**merge(char *buffer)
{
	char	**str_spl;
	int		strc;
	int 	i;
	int		**tab;

	i = 0;
	str_spl = ft_split(buffer, &strc, '\n');
	while (i < strc)
	{
		printf("l%d: %s\n", i, str_spl[i]);
		i++;
	}
}

int		**parse_file(char *pathname)
{
	int 	fd;
	int 	sz;
	char	*strin;
	int 	**ret;

	strin = (char *) malloc(10000 * sizeof(char));
	fd = open(pathname, O_RDONLY);
	sz = read(fd, strin, 10000);
	strin[sz] = '\0';
	ret = merge(strin);
  	return (ret);
}