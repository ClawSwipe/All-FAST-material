 #include<stdio.h>
 #include<ctype.h>
 main(){
 	int age,i;
 	char area;
 	for(i=0;i<10;i++){
 		printf("Enter age");
 		scanf("%d",&age);
 		printf("Enter area.R for Rural and U for Urban\n");
 		scanf(" %c",&area);
 		if(age>=18&&area=='U'){
 			printf("You are eligible for a vacation\n");
		}
		else if(age<18&&area=='R'){
			printf("You are not eligible for a vacation\n");
		}
		else{
			printf("Invalid conditions\n");
		}
	 }
 }
