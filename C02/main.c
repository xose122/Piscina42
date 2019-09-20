#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_str_is_alpha(char *str);
int		ft_str_is_numeric(char *str);
int		ft_str_is_lowercase(char *str);
int		ft_str_is_uppercase(char *str);
int		ft_str_is_printable(char *str);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void	ft_putstr_non_printable(char *str);

int     main(void)
{
	char *dest = (char *) malloc(100);
	char *src;

	/*Ex00*/
	src = "Ex00";
	ft_strcpy(dest, src);
	printf("Ex00 (Mi resultado): %s\n", dest);
	strcpy(dest, src);
	printf("Ex00 (Resultado a obtener): %s\n", dest);

	/*Ex01*/
	src = "Ex01";
	dest = (char *) malloc(100);
	ft_strncpy(dest, src, 2);
	printf("Ex01 (Mi resultado): %s\n", dest);
	strncpy(dest, src, 2);
	printf("Ex01 (Resultado a obtener): %s\n", dest);

	/*Ex02*/
	src = "asdfgAsdfAS";
	if(ft_str_is_alpha(src)){
		printf("Ex02: La cadena (%s) es alpha\n", src);
	}else{
		printf("Ex02: La cadena (%s) NO es alpha\n", src);
	}

	/*Ex03*/
	src = "01234";
	if(ft_str_is_numeric(src)){
		printf("Ex03: La cadena (%s) es numeric\n", src);
	}else{
		printf("Ex03: La cadena (%s) NO es numeric\n", src);
	}

	/*Ex04*/
	src = "asdfgS";
	if(ft_str_is_lowercase(src)){
		printf("Ex04: La cadena (%s) es lowercase\n", src);
	}else{
		printf("Ex04: La cadena (%s) NO es lowercase\n", src);
	}

	/*Ex05*/
	src = "ASDF";
	if(ft_str_is_uppercase(src)){
		printf("Ex05: La cadena (%s) es uppercase\n", src);
	}else{
		printf("Ex05: La cadena (%s) NO es uppercase\n", src);
	}

	/*Ex06*/
	src = "ASDF";
	if(ft_str_is_printable(src)){
		printf("Ex06: La cadena (%s) es printable\n", src);
	}else{
		printf("Ex06: La cadena (%s) NO es printable\n", src);
	}

	/*Ex07*/
	char srcArr[] = "bbASDas42df";
	dest = (char *) malloc(100);
	printf("Ex07 (antes): %s\n", srcArr);
	dest = ft_strupcase(srcArr);
	printf("Ex07 (despues): %s\n", dest);

	/*Ex08*/
	dest = (char *) malloc(100);
	printf("Ex08 (antes): %s\n", srcArr);
	dest = ft_strlowcase(srcArr);
	printf("Ex08 (despues): %s\n", dest);

	/*Ex09*/
	char srcArr09[] = "xxkkyk'#zxv'lexqw'bjl$2<f^v@9km)cr5mjni$";
	dest = (char *) malloc(100);
	printf("Ex09 (antes): %s\n", srcArr09);
	dest = ft_strcapitalize(srcArr09);
	printf("Ex09 (despues): %s\n", dest);
	printf("Ex09 (moullinette): Xxkkyk'#Zxv'Lexqw'Bjl$2<F^V@9km)Cr5mjni$\n");

	/*Ex10*/
	src = "Hola";
	dest = (char *) malloc(100);
	dest[0] = 'z';
	dest[1] = '\0';
	printf("Ex10 (antes): Src: %s Dest: %s\n", src, dest);
	ft_strlcpy(dest, src, 4);
	printf("Ex10 (despues): Dest: %s\n", dest);

	/*Ex11*/
	src = "Buenas\n que\ttal\eestas?";
	ft_putstr_non_printable(src);
}