#include<stdio.h>
#include<math.h>
main(){
	int dob,count,i=0,x[10],j=1,k;
	printf("Enter your date of birth in ddmmyyyy format");
	scanf("%d%n",&dob,&count);
	if(count==8){
		for(i=0;i<10;i++){
		x[i]=0;//initializing array into all zeros first because it was giving me garbage values.
		}
	while(dob!=0){
		x[j++]=dob%8;
		dob/=8;
	}
	printf("Your date of birth in octal form is:\n");
	for(k=j-1;k>0;k--){
		printf(" %d",x[k]);
	}
}
else{
	printf("Please enter in the correct format");
}	
}
