#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// int tab[2];
 
	// pipe(tab);
	// printf("%d\n", tab[0]);
	// printf("%d\n", tab[1]);
	// return (0);


	// pid_t   pid;
	// int     status;
	// pid = fork();
	// if (pid == 0)
	// {
	//     exit(200);
	// }
	// else
	// {
	//     pid = waitpid(-1, &status, 0);
	//     printf("pid = %d\n", pid);
	//     printf("$? = %d\n", WEXITSTATUS(status));
	//     printf("status = %d\n", status);
	//     return(0);
	// }

	pid_t   pid;
	int     a;
	int		b;
	int		*ptr;

	a = 0;
	b = 20;
	ptr = &a;
	pid = fork();
	if (pid == 0)
		ptr = &b;
	printf("%d\n", *ptr);
}