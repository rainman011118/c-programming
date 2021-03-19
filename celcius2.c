#include <stdio.h>
int main(int argc, char **argv) {
	double t_c1 = 55, t_c2 = 100, t_c3 = 222.4;
	double cfac, t_f1, t_f2, t_f3;
	cfac = 9.0/5.0;
	//cfac is just short for 'conversion factor' NOT FIXED.

	t_f1 = t_c1 * cfac +32;
	t_f2 = t_c2 * cfac +32;
	t_f3 = t_c3 * cfac +32;

	printf("cfac: %f\n", cfac);
	printf("%f celcius is %f farenheit\n", t_c1, t_f1);
	printf("%f celcius is %f farenheit\n", t_c2, t_f2);
	printf("%f celcius is %f farenheit\n", t_c3, t_f3);
	
	return 0;

}

/*First I have declared my variables:
	type = double
	celcius = t_c x 3
	farenheit = t_f x 3
	cfac = conversion factor x 1

Then I calculate each t_f variable.

NOTE: It is important that you use 9.0 and 5.0 as these are decimal.
If you put 9 and 5, which are integers, it will ERROR.
*/
	
