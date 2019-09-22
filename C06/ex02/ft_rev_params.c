#include <unistd.h>

void	ft_ptint_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &(str[i]), 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_swap(int *a, int *b)
{
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int		partition(int arr[], int low, int high)
{
	int pivot;
	int i;
	int j;

	i = (low - 1);
	j = low;
	pivot = arr[high];
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int arr[], int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = argc -1;
	while (i > 0){
		ft_ptint_str(argv[i]);
		i--;
	}
}