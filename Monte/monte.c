#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main (){
	int i;
	int count1 = 0, count2 = 0; 
	int long num1 = 0, num2 = 0;
	double x, y;
	double pi;

	printf("試行回数：");
	scanf("%ld",&num1);
	printf("繰り返し：");
	scanf("%ld",&num2);

	srand((unsigned)time(NULL));
	
	while(count2 <= num2){

		for (i = 0; i <= num1; i++){
			x = (double)(rand() / (double)RAND_MAX);
			y = (double)(rand() / (double)RAND_MAX);
			x = pow(x - 0.5, 2);
			y = pow(y - 0.5, 2);

			if(x + y <= pow(0.5, 2)){
				count1++;
			}
		}
	
		pi = (double)count1 / num1 * 4;
		printf("%f\n", pi);

		x = 0;
		y = 0;
		count1 = 0;
		pi = 0;

		count2++;
	}

	return 0;

}


		
