#include <stdio.h>
#include <string.h>
/*'How to use scanf with fgets' youtube 'CodeVault'*/
int main(int argc, char **argv) {
    int id;
    char message[100];
    while (1) {
        printf("Input ID: ");
        scanf("%d", &id);
        fgetc(stdin);
        /*eats the 'enter' value from scanf.
        Scanf reads upto the first whitespace ch.
        Therefore this is AFTER the 'enter' value.
        So, 'enter' remains in the buffer.
        This gets eaten by fgetc().
        Alternative is to use: getchar(); */
        printf("Input message: ");
        fgets(message, 100, stdin);
        message[strlen(message) - 1] = 0;
        printf("(%d) Sent message: %s\n", id, message);
    }

    return 0;
}

/*Both fgets and scanf store the 'enter'(\n) in their buffers, hence why when a subsequent scanf/fgets/ or stdin line is followed, it will automatically take in what's left in the buffer from the previous reads i.e. 'enter'
 */
