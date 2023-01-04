#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main (){
	int i;
	int count = 0; 
	int long num = 10;
	double x, y;
	double pi;

	srand((unsigned)time(NULL));
	
	while(num <=  1000000000){

		for (i = 0; i <= num; i++){
			x = (double)(rand() / (double)RAND_MAX);
			y = (double)(rand() / (double)RAND_MAX);
			x = pow(x - 0.5, 2);
			y = pow(y - 0.5, 2);

			if(x + y <= pow(0.5, 2)){
				count++;
			}
		}
	
		pi = (double)count / num * 4;
		printf("%f\n",pi);

		x = 0;
		y = 0;
		count = 0;
		pi = 0;

		num *= 10;

	}

	return 0;

}


		
