#include <stdio.h>
#include <string.h>
int main()
{
    int a[5] = {99, 39, 25, 101, 920};
    char b[] = "hello";
    int i;
    printf("a = %p\n", a);
    printf("&a = %p\n", &a);
    printf("a+1 = %p\n", a + 1);
    printf("*a = %d\n", *a);
    printf("*a+1 = %d\n", *a + 1);
    printf("*(a+1) = %d\n", *(a + 1));
    printf("a[1] = %d\n", a[1]);
    printf("sizeof(a) = %lu(in bytes)\n", sizeof(a));
    printf("sizeof(b) = %lu(in bytes)\n", sizeof(b));

    printf("strlen(b) = %ld\n", strlen(b));
    //NO GOOD WITH 'INT' ARRAYS.Besides I have already defined the size[5].
    for (i = 0; i < 5; i++)
    {
        printf("[%d]: %d ", i, a[i]);
    }
    printf("\nNow for char b array which will be ASCII values\nNotice when I print 1 extra, it is the null character\nBUT BEWARE - ANYTHING AFTER THE ALLOTTED SIZE IS CONSIDERED UNDEFINED BEHAVIOUR AND NOT WISE.\n");
    for (i = 0; i < 6; i++)
    {
        printf("[%d]: %d = %c ", i, b[i], b[i]);
    }
    printf("\n*b = %d",*b);
    printf("\n*(b+1) = %d", *(b + 1));
    printf("\n*(b+2) = %d\n", *(b + 2));

    printf("dereferencing using b[]: %c%c%c%c%c\n", b[0], b[1], b[2], b[3], b[4]);
    printf("*&b = %s\n", *&b);
    //printf("&b = %s\n", &b);//This doesn't compile.
    /*https://www.youtube.com/watch?v=Cfm4D_Mxpiw 'Arrays as function parameters in C'
    See this link which explains: 
    %s expects char *, but arg is char*[6]
    Therefore *&b will work.
    */

    printf("&b = %p\n", &b);
    printf("b = %s\n", b);
    printf("*b = %c\n", *b);
    return 0;
}
