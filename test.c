#include <unistd.h>
#include <stdio.h>

int main()
{
    int tab[2];
 
    pipe(tab);
    printf("%d\n", tab[0]);
    printf("%d\n", tab[1]);
    return (0);
}