#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Still not quite 100%
// I entered in 2 random strings and the counts were not right...but the matching characters were

/*
void total_matches(char** buffer) {
		char** ptr = *buffer;
		int i, j;
		int count = 0;
		int len_buf = strlen(buffer);
		for(i=0;i<len_buf;i++) {
				for(j=i;j<len_buf;j++) {
						if(*ptr == buffer[j]) {
								count += 1;
						}else{
								continue;
						}
				}
				ptr++;
				printf("%c = %d total matches\n", *ptr, count);
				count = 0;
		}
}
*/

// this runs, but not yet finalised...
// want to return total matches for each seen char, BUT NOT REPEATS! 
// also, each repeat is copied to buffer, not what I want. If already in buffer, I want to ignore it and just add to count.
void cmp_strings(char* one, char* two) {
		int len_one = strlen(one);
		int len_two = strlen(two);
		int i, j, k;
		int l = 0;
		int match = 0;
		char matching_letters[24] = {0};
		int len_match = sizeof(matching_letters);
		for(i=0;i<len_one;i++) {
				match = 0;
				for(j=0;j<len_two;j++) {
						if(one[i] == two[j]) {
								match += 1;
								matching_letters[l++] = one[i];
								/*for(k=0;k<len_match;k++) {
										if(one[i] != matching_letters[k]) {
												continue;
										}else{
												match += 1;
												break;
										}
								}
								if(match > 1) {
										break;
								}else{
										matching_letters[l++] = one[i];
								}*/
						}else{
								continue;
						}
				}
				printf("char %c = %d matches\n", one[i], match);
		}
		printf("matching letters = %s\n", matching_letters);
}

int main() {
		char buffer[64];
		char* name = "partly";
		char* name2 = "same";
		printf("name = %s\n", name);

		if(strcmp(name, name2) == 0) {
				printf("Match!\n");
		}else{
				printf("Not the same\n");
		}


		/*
		puts("Now print out all the letters that match 'w' or 'z'");
		int len = 0;
		int i = 0;
		int j = 0;
		len = strlen(name);
		for(i=0;i<len;i++) {
				if(name[i] == 'n' || name[i] == 'y') {
						printf("name[%d]: %c\n", i, name[i]);
						buffer[j++] = name[i];
				}else{
						continue;
				}
		}
		printf("name = %s\n", name);
		printf("buffer = %s\n", buffer);
		
		char buffone[24];
		char bufftwo[24];
		puts("Please enter a cartoon character's name");
		fgets(buffone, 24, stdin);
		buffone[strlen(buffone)-1] = 0;
		puts("Please enter another, different cartoon character's name");
		fgets(bufftwo, 24, stdin);
		bufftwo[strlen(bufftwo)-1] = 0;

		cmp_strings(buffone, bufftwo);
*/
		return 0;
}
