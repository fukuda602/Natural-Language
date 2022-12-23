#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	FILE *fp1;
	FILE *fp2;
	int count1 = 0, count2 = 0;
	int ran = 0;
	int i;
	unsigned int seed;
	char ch1, ch2;
	
	fp1 = fopen("change.txt","r");
	fp2 = fopen("ran.txt","w");

	if(fp1 == NULL || fp2 == NULL){
		printf("error\n");
		return 1;
	}

	while((ch1 = fgetc(fp1)) != EOF){
			count1++;
	}


	count1 -= 1;	//プロクラムの最後に\nが入るため
	seed = (unsigned int)time(NULL);
	srand(seed);

	for(i = 1; i <= 100; i++){	
		ran = rand() % count1 + 1;
		fclose(fp1);
		fp1 = fopen("change.txt","r");

		do{
			(ch2 = fgetc(fp1));	
			count2++;
		}while(count2 < ran);

		fprintf(fp2,"%c",ch2);	
		count2 = 0;		
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}
