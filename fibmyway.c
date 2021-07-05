#include <stdio.h>

int main()
{
    int x;
    printf("Enter a number between 1 and 20: ");
    scanf("%d", &x);
    /*Still need to check for invalid characters, 
    EOF and \n.
    */
    unsigned int a = 0, b = 1, c = 0;
    if (x < 0 || x > 20)
    {
        printf("Invalid number\n");
        return 0;
    }
    else
    {
        for (int i = 0; i < x; i++)
        /*MAX limit for 'int' = 45 (2.1billion)
    (46+ = minus figure)
    unsigned ceiling = 4.2billion
    */
        {
            c = a + b;
            printf("%d\n", c);
            a = b;
            b = c;
            c = 0;
        }
    }
    return 0;
}
