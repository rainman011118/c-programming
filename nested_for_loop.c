#include<stdio.h>
int main()
{
	for (int i = 0; i <2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d, %d\n", i, j);
		}
	}
	return 0;
}

	/* This reads as follows:
	   As long as the first loop (i) is true, 
	   carry out the nested loop (j).
	   while i is 0, run the j loop; j0, j1, j2, j3, BACK TO START.
	   while i is 1, run the j loop; j0, j1, j2, j3, BACK TO START.
	   now i is 2, break.
	 */
