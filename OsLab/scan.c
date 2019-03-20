#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Request
{
	int TrackNumber;
	bool visited;
};


int main()
{
	int NumberOfRequests, temp,i,limit,InitialHead,j,seek=0,dummy;

	printf("Enter Number of requests:  ");
	scanf("%d",&NumberOfRequests);

	struct Request req[NumberOfRequests];

	printf("Enter Request numbers:  ");
	for(i=0;i<NumberOfRequests;i++){
		scanf("%d",&req[i].TrackNumber);
		req[i].visited=false;
	}

	printf("Enter initial head:  ");
	scanf("%d",&InitialHead);

	dummy = InitialHead;

	printf("Enter disk size:  ");
	scanf("%d",&limit);

	printf("Enter choice\n1.to move forward first\n2.to move backward first\n");
	scanf("%d",&temp);

	if (temp==1){
		for(i=InitialHead;i<limit;i++){
			for(j=0;j<NumberOfRequests;j++){
				if(i==req[j].TrackNumber && req[j].visited==false){
					printf("%d \t",req[j].TrackNumber);
					req[j].visited = true;
				}
				seek++;
			}
		}
		InitialHead = limit-1;
		for(i=InitialHead;i>=0;i--){
			for(j=0;j<NumberOfRequests;j++){
				if(i==req[j].TrackNumber && req[j].visited==false){
					printf("%d \t",req[j].TrackNumber);
					req[j].visited = true;
				}
			}
			seek++;	
		}
	}
	else if (temp==2){
		for(i=InitialHead;i>=0;i--){
			for(j=0;j<NumberOfRequests;j++){
				if(i==req[j].TrackNumber && req[j].visited==false){
					printf("%d \t",req[j].TrackNumber);
					req[j].visited = true;
				}
			}
			seek++;	
		}
		InitialHead = 0;	
		for(i=InitialHead;i<limit;i++){
			for(j=0;j<NumberOfRequests;j++){
				if(i==req[j].TrackNumber && req[j].visited==false){
					printf("%d \t",req[j].TrackNumber);
					req[j].visited = true;
				}
			}
			seek++;
		}
	}
	seek = limit+ abs(limit-1-dummy);
	printf("%d",seek);

	return 0;
}