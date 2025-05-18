#include<stdio.h>
#include<math.h>
main(){
	int i,prev,j,k,year,roll,LSD,MSD,prime,prime2,seq,ans;
	prime=5;
	printf("Enter your birth year");
	scanf("%d",&year);
	printf("Enter the 4 digits of your roll number");
	scanf("%d",&roll);
	MSD=year/1000;
	LSD=roll%10;
	prime2=pow(2,prime);
	seq=MSD+LSD+prime2;
	printf("The series will be printed till %d number of times\n",seq);
	printf("0, ");
	prev=0,i=1l;
	for(k=0;k<seq-1;k++){
		prev=i;
		i=ans;
		ans=i+prev;
		printf("+%d,  ",ans);
	}
}
