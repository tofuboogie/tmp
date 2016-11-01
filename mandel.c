#include <stdio.h>
#include <math.h>
#define MAX_ITER 50 
//compile with: gcc -Wall -std=c11 -o mandel mandel.c -lm

int main(int argc, char* argv[]) {
	
	puts("\n****MANDLEBROT****");
	puts("Calculating number of iterations until escape for a complex number");
	
	float real,imag;
	printf("Enter real part: ");
	scanf("%f",&real);

	printf("Enter imaginary part: ");
	scanf("%f",&imag);

	puts("Formulae:\tz = z^2 + c");
	puts("\t\t(x,y)^2 = (x^2 - y^2 , 2xy)");
	puts("\t\tCheck: z^2 = x^2 + y^2      If z exceeds 2, it is not in the set");
	puts("\t\t   [for simplicity, since 2^2=4, the check compares to 4)\n");
	
	float z_real=0, z_imag=0;
	for(int i=1; i<MAX_ITER; ++i){
		printf("z%d = (%.2f,%.2f)^2 + (%.2f,%.2f)\n",i+1,z_real,z_imag,real,imag);
		printf("z%d = (%.2f^2 - %.2f^2, 2*%.2f*%.2f) + (%.2f,%.2f)\n",i+1,z_real,z_imag,z_real,z_imag,real,imag);
		
		float z_real1 = pow(z_real,2) - pow(z_imag,2);
		z_imag = 2*z_real*z_imag;
		z_real = z_real1;
		printf("z%d = (%.2f,%.2f) + (%.2f,%.2f)\n",i+1,z_real,z_imag,real,imag);

		z_real = z_real + real;
		z_imag = z_imag + imag;
		printf("z%d = (%.2f,%.2f)\n",i+1,z_real,z_imag);
			
		float check = pow(z_real,2) + pow(z_imag,2);
		printf("Check value (<4): %.2f\n\n", check); 

		if (check > 4) {
		printf("Escape: Iteration %d\n",i);
		break; // >=4 ??
		}
	}

	return 0;
}
