#include<stdio.h>
#include<math.h>
main(){
	int x,n=1,N=14,i;
	int sum=0;
	printf("Enter the value of x");
	scanf("%d",&x);
	printf("The largest common factor of 42 and 98 is 14. Thus N=14\n");
	for(i=0;i<N;i++){
		n=n*i;
		sum=sum+(pow(x,i)/n) ;
	}
	sum++;
	printf("The sum is %d",sum);
}
