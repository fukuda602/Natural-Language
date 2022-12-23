#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define billion 10000000000

double get_x1(double n9, double n1, double x2, double n2, double x3, double n0)
{
	return ((n9 - n1 * x2 - n2 * x3) / n0);
}

double get_x2(double n10, double n3, double x1, double n5, double x3, double n4)
{
	return ((n10 - n3 * x1 - n5 * x3) / n4);
}

double get_x3(double n11, double n6, double x1, double n7, double x2, double n8)
{
	return((n11 - n6 * x1 - n7 * x2) / n8);
}

int main(){
	double x1, x2, x3;
	double num[12];
	double n0, n1, n2, n9;
	double n3, n4, n5, n10;
	double n6, n7, n8, n11;
	int i = 1, j = 1;
	int n = 1, m = 1;
	int long A, B, C;
	double a, b, c;

	for(j = 1; j <= 12; j++)
	{
		if(j <= 9){
			printf("%d 行%d 列:",n , m);
			scanf("%lf",&num[j]);
		}
		else if(j >= 10){
			printf("x%d = ",j - 9);
			scanf("%lf",&num[j]);
		}
		m++;
		if(j % 3 == 0){
			n++;
			m = 1;
		}
	}

	n0 = num[0 + 1]; n1 = num[1 + 1]; n2 = num[2 + 1]; n9 = num[9 + 1];
	n3 = num[3 + 1]; n4 = num[4 + 1]; n5 = num[5 + 1]; n10 = num[10 + 1];
	n6 = num[6 + 1]; n7 = num[7 + 1]; n8 = num[8 + 1]; n11 = num[11 + 1];
	
	printf("x2 の初期値:");
	scanf("%lf",&x2);
	printf("x3 の初期値:");
	scanf("%lf",&x3);

	for(;;)
	{
		x1 = get_x1(n9, n1, x2, n2, x3, n0);
		x2 = get_x2(n10, n3, x1, n5, x3, n4);
		x3 = get_x3(n11, n6, x1, n7, x2, n8);
		printf("round %2d, (%12.10f, %12.10f, %12.10f)\n", i, x1, x2, x3);

		A = (round(x1 * billion));
		B = (round(x2 * billion));
		C = (round(x3 * billion));
		a = x1 - (int long)x1;
		b = x2 - (int long)x2;
		c = x3 - (int long)x3;

		if(A % 10 == 0 && B % 10 == 0 && C % 10 == 0)
			exit(0);

		if(a == 0 && b == 0 && c == 0)
			exit(0);

		i++;
	}
}
