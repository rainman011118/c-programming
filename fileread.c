#include <stdio.h>
/*fgets automatically stops at a new line or EOF.*/
int main()
{
    FILE *fp;
    char str[64];

    fp = fopen("/home/rain/Testfolder/BBA.txt", "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        return (-1);
    }
    /*if (fgets(str, 64, fp) != NULL)
    { This is alternative way using another if statement.
        puts(str);
    }
    */
    else
    {
        fgets(str, 64, fp);
        puts(str);
    }
    fclose(fp);
    return 0;
}
