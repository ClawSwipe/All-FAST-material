#include<stdio.h>
main(){
	char abc[30]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int i,lines,j=0;
	printf("Enter a number");
	scanf("%d",&lines);
	for(i=0;i<lines;i++){
		printf("\n");
		for(j=0;j<=i;j++){
			printf("%c",abc[j]);
		}
	}
}
