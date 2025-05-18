#include<stdio.h>
main(){
	int num=0,pos=0,majp=0,neg=0,majn=0,zero=0,majz=0;
	char ans;
	while(ans!='N'){
		printf("Enter a number");
		scanf("%d",&num);
		if(num>0){
			pos++;
			majp++;
		}
		else if(num<0){
			neg++;
			majn++;
		}
		else{
			zero++;
			majz++;
		}
		printf("To terminate, input N. To continue, input any other key");
		scanf(" %c",&ans);
	}
	printf("The number of positive integers input were: %d\nThe number of negative integers input were: %d\nThe number of integers equal to 0 were: %d\n",pos,neg,zero);
	if(majp>majn&&majp>majz){
		printf("The majority of integers input were positive");
	}
	else if(majn>majp&&majn>majz){
		printf("The majority of integers input were negative");
	}
	else if(majz>majp&&majz>majn){
		printf("The majority of integers input were zeroes");
	}
	else if(majp==majn&&majp>majz){
		printf("The majority of integers input were both positive and negative");
	}
	else if(majz==majn&&majz>majp){
		printf("The majority of integers input were both zeroes and negative");
	}
	else if(majz==majp&&majz>majn){
		printf("The majority of integers input were both zeroes and positive");
	}
	else{
		printf("Equal number of positive,negative and zero value integers were added");
	}
}
