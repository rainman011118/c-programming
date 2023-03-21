#include<stdio.h>
#include<stdlib.h>

long long add(int a, int b) {
	return a + b;
}

long long multiply(int a, int b) {
	return a * b;
}

void exec(long long (*fun2)(int, int)) {
	printf("%lld\n", fun2(5, 7));
}

int main() {
	long long (*fun)(int, int);// = &add; is alternative way (just like a pointer).
	fun = &add;
	//This above is the main bit.^^^^^
	
	printf("%lld\n", fun(5, 7));
/*NOTE: we use 'fun(5, 7)' and not '*fun(5, 7)'. This is because  we are calling the function rather than dereferencing it.  If we were to assign the result of call to a variable, then we would need to dereference it as we want the value. e.g. result = *fun(5, 7);    
 */
	fun = &multiply;
	printf("%lld\n", fun(5, 7));
//This above is straight forward to understand.  Hardly any different from typing 'add()'.

	exec(&add);
	exec(&multiply);
//This bit instead utilises the function pointer as an argument to a function....still doesn't make much sense why this would be beneficial over just calling the fn and passing the normal args...?  

	return 0;
}
/*I removed all the '&' from infront of the function names in main, and everything still worked...BUT, since the argument should be a function pointer, '&' should be used...?
 * You can also use 'typedef'.e.g. typedef long long (*func_addition)(int, int), and just call it with func_addition().
I think the reason for the use of typedef is to group all the relevant functions under one function name so that instead of having to call each individual fn, we just call the group typedef fn name and pass the specific sub function as the argument we want.
*/
