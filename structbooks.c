#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct 
{
    char title[20];
    char author[20];
    int pages;
    float price;
} Books;

int main()
{
    Books book2, book3;
    Books book1 = {"Lord of the Rings", "JRR Tolkein", 5005, 5.99};
    /*When I initially typed this as:
	Books book1, book2, book3; //which was the declaration of vars.
	book1 = //which was the assignment. 
	it would not work.
	For some reason it required 'Books book1 = '??
	Also didn't require the pointer use below.
	Books* ptr = &book1;//structure pointer.
	*/
    //printf("%s\n%s\n%d\n%.2f\n", book1.title, book1.author, book1.pages, book1.price);
    book2.pages = 1005;
    printf("Pages in book2: %d\n", book2.pages);
    /*You CANNOT ASSIGN STRINGS TO CHAR ARRAYS!!!
	So below will not work!
	A string can only be assigned to an array at 
	declaration.
	Hence STRCPY must be used
	*/
    //Books *bk2;
    //bk2 = &book2;
    //*(*bk2).author = "Hello";
    //printf("Author book2: %s\n", book2.author);
	strcpy(book2.author, "George RR Martin");
	printf("Game of Thrones author is: %s\n", book2.author);

    return 0;
}
