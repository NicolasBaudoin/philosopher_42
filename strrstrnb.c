
int	strtrucstr(char *str, char *toFind)
{
	int i = 0;
	int counter = 0;

	while (str[i])
	{
		int j = 0;
		while (str[i + j] == toFind[j])
		{
			if (toFind[j+1] == '\0')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}
#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;
	char *str;
	char *to_find;
	int res = 0;

	str = av[1];
	to_find = av[2];
	res = strtrucstr(str, to_find);
	printf("%d\n", res);
	return 0;
}

// abcdef
// ef

