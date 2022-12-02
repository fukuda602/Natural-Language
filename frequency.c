#include <stdio.h>
#include <ctype.h>

void bsort(int a[], char b[], int n){
	int i, j;

	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			if(a[i] < a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				char temp2 = b[i];
				b[i] = b[j];
				b[j] = temp2;
			}
		}
	}
}


int main(){

	int count[28] = {};
	int i = 0;
	FILE *fp;
	char ch;
	char alhp[28] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k' , 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',' ', '\n'};

	fp = fopen("change.txt","r");

	if(fp == NULL){
		puts("error");
		return 1;
	}

	while((ch = fgetc(fp)) != EOF){

		for(i = 0;  i < 28; i++){
			if(ch == alhp[i]){
				count[i] += 1;
			}
		}
	}

	count[27] -= 1;

	bsort(count, alhp, 28);
	for(i = 0; i < 28; i++){
		printf("%c : %d\n",alhp[i] ,count[i]);
	}


	fclose(fp);

	return 0;

	}

