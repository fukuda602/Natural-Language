#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main (){
	int i;
	int count = 0; 
	int long num = 0;
	double x, y;
	double pi;

	printf("試行回数：");
	scanf("%ld",&num);

	srand((unsigned)time(NULL));

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
	printf("%f\n", pi);

	return 0;

}


		
