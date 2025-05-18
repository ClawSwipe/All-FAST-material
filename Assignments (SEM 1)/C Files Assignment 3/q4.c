#include<stdio.h>
main(){
	int t1,t2,max;
	printf("Enter the time taken by car 1 to complete one round in minutes");
	scanf("%u",&t1);
	printf("Enter the time taken by car 2 to complete one round in minutes");
	scanf("%u",&t2);
	max=t1>t2?t1:t2;
	while(max>-1){
		if(max%t1==0&&max%t2==0){
			printf("The time at which both cars will run together is %d minutes",max);
			break;
		}
		else{
			max++;
		}
	}
}
