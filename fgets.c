#include <stdio.h>
#include <string.h>
int main()
{
  char alpha[10];
  printf("Enter a short string: ");
  fgets(alpha, sizeof(alpha), stdin);

  /* fgets takes the input from 'stdin',
  (max. size of (10-1) characters to allow for NULL),  
  and assigns it to char 'alpha'. */
  printf("%s", alpha);
  puts("helloabcde = helloabcd(10) with no new-line - e replaced by \\0 and \\n cut off.");
  puts("helloabcd = helloabcd(9) with no new-line = newline is replaced by\\0 - NO ROOM FOR \\n");
  puts("helloabc = helloabc(8) WITH new-line = helloabc\\n\0");
  return 0;
}

/*The 'fgets' function allows the programmer to specify:
  how many characters it will accept, thereby protecting against overflow.
  
  format = ('variable name', 'char limit', stdin = keyboard input)
  Note: spaces are included in the char count.
  
  **fgets is used to read 'lines of text from a file'
    aka strings.  Therefore it stops reading input only
    when it encounters a new line or EOF.

    It also 'reads at most one less than the number of
    characters specified by n from the stream. No additional
    characters are read after a new-line character (which
    is retained) or after end-of-file. A null character is
    written immediately after the last character read
    into the array.' See link below:
    (https://stackoverflow.com/questions/42404627/what-size-should-be-used-for-fgets)
    So it will read all the characters in hello, including
    the 'enter', but stores 'hello' without the 'enter'.
    It then adds \0 as the terminator.
  
  
  */
