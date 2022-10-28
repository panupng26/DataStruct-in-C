#include <stdio.h>   /* Link section */
int total = 0;       /* Global declaration, definition section */
int main()          /* Main function */
{
    int num = 3;
    printf ("This is a C basic program \n");
    total = 100 + num;
    printf ("Sum of two numbers : %d \n", total);
    return 0;
}
