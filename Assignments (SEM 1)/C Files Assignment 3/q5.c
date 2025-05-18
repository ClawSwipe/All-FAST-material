#include<stdio.h>
#include<math.h>
main(){
	unsigned int num,count, div=1000000000,msd,i;
	int N,j,x1=1,y1=3,x2,y2;
	float dis;
	printf("Please enter your mobile number:0");//to ensure an octal number isnt entered;
	scanf("%u%n",&num,&count);
	if(count==10){
		for(i=0;i<10;i++){//question says N should be the NON ZERO most significant digit, so Im following that
			msd=num/div;
			if(msd!=0){
				break;
			}
			else{
			div/=10;
			}//keeps on going until a non zero value is found
		}
		printf("The most significant digit of your number is %d\n",msd);
		N=ceil(((pow(2,msd))*0.0625));
		printf("The result of N is %d, so your robot will move %d number of times!\n",N,N+3);//to ensure location A,B and C are input
		for(j=0;j<N+3;j++){
			printf("Enter location %d\nEnter the x coordinate:",j+1);
			scanf("%d",&x2);
			printf("Enter the y coordinate:");
			scanf("%d",&y2);
			dis=sqrt((pow(x2-x1,2))+(pow(y2-y1,2)));
			printf("The distance of the robot from the camera currently is %.2f units\n",dis);
		}
	}
	else{
		printf("Please enter the correct format");
	}
}
