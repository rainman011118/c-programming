#include <stdio.h>

int main()
{
    char c;
    int lowercase_vowel, uppercase_vowel;
    printf("Please enter a letter of the alphabet: ");
    scanf("%c", &c);

    lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (lowercase_vowel || uppercase_vowel)
    {
        printf("%c is a vowel\n", c);
    }
    else
    {
        printf("%c is a consonant\n", c);
    }
    return 0;
}
