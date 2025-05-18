#include<stdio.h>
#include<math.h>
main(){
	int age,i,j,h;
	printf("Enter age");
	scanf("%d",&age);
	for(i=1;i<age;i++){
		for(j=1;j<age;j++){
			h=sqrt((pow(i,2))+(pow(j,2)));
			printf("side a=%d  side b=%d  hypotenuse=%d\n",i,j,h);
		}
	}
}
