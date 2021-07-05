#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

//https://linuxhint.com/pipe_system_call_c/

int main()
{
    int arr[] = {1, 2, 3, 4, 1, 2};
    int arrSize = sizeof(arr) / sizeof(int);
    int start, end;
    int fd[2];/*fd stands for file descriptor. stdin 0, stdout 1, stderr 2, close() are examples of file descriptors.
	This int fd[2] is basically an array with 2 int elements which represent: read and write. 0 = read from pipe, 1 = write to pipe.  On success, the pipe() fn returns 0.  If an error occurs during initialisation, -1 is returned.
	*/

    if (pipe(fd) == -1)
    {
        return 1;
    }

    int id = fork();
    if (id == -1)
    {
        return 2;
    }

    if (id == 0)
    {
        start = 0;
        end = arrSize / 2;
    }
    else
    {
        start = arrSize / 2;
        end = arrSize;
    }

    int sum = 0;
    int i;
    for (i = start; i < end; i++)
    {
        sum += arr[i];
    }

    printf("Calculated partial sum: %d\n", sum);
    //################################################

    if (id == 0)
    {
        close(fd[0]);
        if (write(fd[1], &sum, sizeof(sum)) == -1)
        {
            return 3;
        }
        close(fd[1]);
    }
    else
    {
        int sumFromChild;
        close(fd[1]);
        if (read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1)
        {
            return 4;
        }
        close(fd[0]);

        int totalSum = sum + sumFromChild;
        printf("Total sum is %d\n", totalSum);
        wait(NULL);
    }

    return 0;
}
