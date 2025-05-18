#include<stdio.h>
main(){
	int itr,i,j;
	char sit;
	printf("Input iterations");
	scanf("%d",&itr);
	printf("Enter situation. n for normal and ab for abnormal");
	getchar();
	sit=getchar();
	if(sit=='n'){
		printf("#######\n");
		for(i=0;i<itr;i++){
			for(j=0;j<itr;j++){
			printf("Normalsituation");
			}
		}
		printf("\n#######\n");
	}
	else if(sit=='a'){
		printf("*******\n");
		for(i=0;i<itr;i++){
			for(j=0;j<itr;j++){
			printf("Abnormalsituation");
			}
		}
		printf("\n*******\n");
	}
	else{
		printf("invalid input");
	}
}
