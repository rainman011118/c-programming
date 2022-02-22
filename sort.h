#pragma once //SEE: pragma.txt for explanation
#include<stdio.h> //I think this is included here because the functions use 'printf' which is part of the stdio.h library.  So declaring it here is fine.  (It then doesn't have to be declared in the sort_fucntions.c)..

void sort_ascending(int*, int);
void sort_descending(int*, int);

/*eg:
 	file "grandparent.h"
    #pragma once

 	struct foo {
		int member;
	};

	file "parent.h"
	#include"grandparent.h"

	file "child.c"
	#include"grandparent.h"
	#include"parent.h"

	*/

