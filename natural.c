#include <stdio.h>
#include <ctype.h>

int main(){

int num = 0;
char ch;
FILE *fp1;
FILE *fp2;

printf("text number :");
scanf("%d",&num);

if(num == 1){
	fp1 = fopen("text1.txt","r");
}else if(num == 2){
	 fp1 = fopen("text2.txt","r");
}else if(num == 3){
	 fp1 = fopen("text3.txt","r");
}else{
	printf("error\n");
	return 1;
}

fp2 = fopen("change.txt", "w");

if(fp1 == NULL || fp2 == NULL) {
	printf("error\n");
	return 1;
}
while((ch = fgetc(fp1)) != EOF) {
	ch = tolower(ch);

	if(isalpha(ch) == 0 && ch != 0x0a)
	       	ch = 0x20;	

	fprintf(fp2,"%c", ch);
}

fclose(fp1);
fclose(fp2);

return 0;
}
