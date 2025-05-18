#include<stdio.h>
main(){
	char a,b,c,a2,b2,c2;
	int flag=0;
	printf("Enter the first alphabet");
	scanf(" %c",&a);
	printf("Enter the second alphabet");
	scanf(" %c",&b);	
	printf("Enter the third alphabet");
	scanf(" %c",&c);
	do{
		printf("Enter a random alphabet");
		scanf(" %c",&a2);
		printf("Enter a random alphabet");
		scanf(" %c",&b2);
		printf("Enter a random alphabet");
		scanf(" %c",&c2);
		if(a2==a&&b2==b&&c2==c||c2==a&&b2==b&&a2==c){
			flag=1;
		}	
	}while(flag==0);
	printf("Pass. The alphabets you entered were %c%c%c",a2,b2,c2);
}
