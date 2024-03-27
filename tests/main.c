# include <tests.h>

int main (int argc, char *argv[])
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (fork() == 0)
			execl(argv[i], argv[i], NULL);
		else
			wait(NULL);
		i++;
	}
}
