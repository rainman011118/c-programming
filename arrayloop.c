#include <stdio.h>
/*2D-array which has 2 rows and 3 columns: */
int main()
{
    int myArray[2][3] = {
        {1, 2, 3},
        {8, 9, 10}

    };
    int i = 0; //this represents the rows
    int j = 0; //this represents the columns
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("myArray[%d][%d] = %d\n", i, j, myArray[i][j]);
        }
    }
}
/*Order of things:
     - when i is 0, less than 2, GO INTO J LOOP
     - j = 0, < 3, GO TO PRINTF fn, j++.
     - j = 1, < 3, GO TO PRINTF fn ....etc etc
     - When j = 3, GO BACK TO i LOOP. i = 1...
     Each nested loop (j) must finish/complete before
     going back to original start loop.*/
