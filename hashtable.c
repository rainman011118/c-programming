#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct pair {
		int value;
		int key;
};

void display(struct pair[], int size);

int main(int argc, char** argv) {
		int SIZE, i, temp;
		printf("Enter the size of the table:\n");
		scanf("%d", &SIZE);
		struct pair hash_table[SIZE];
		printf("Enter the elements:\n");
		for(i=0;i<SIZE;i++) {
				scanf("%d", &temp);
				hash_table[temp % SIZE].value = temp;
				hash_table[temp % SIZE].key = temp % SIZE;
		}
		printf("\n");

		display(hash_table, SIZE);

		return 0;

}

void display(struct pair array[], int size) {
		printf("Value\tkey\n");
		for(int i=0;i<size;i++) {
				printf("%d\t%d\n", array[i].value, array[i].key);
		}
}

/*When I entered the following:
size of table: 5
no. elements:
99
32
47 - change this to 46 and it works fine.
13
20
It printed them all out in key and value pairs except for 32 which showed a garbage number...??? - ANSWER: This might be because of COLLISION. Since 32 and 47 both return '2' for the final number hash_table[2], so this must have caused the problem...
*/


