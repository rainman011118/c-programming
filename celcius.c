#include <stdio.h>
int main() {
	double t_c = 55;
	double t_f;

	t_f = t_c * 9/5 + 32;

	printf("%f celcius is %f farenheit\n", t_c, t_f);

	return 0;
}

//Simple temperature conversion.
//t_c (celcius) is declared and so is value.
//t_f (farenheit) is declared
//t_c calculation is declared.
