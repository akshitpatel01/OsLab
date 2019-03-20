#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "math.h"

struct Process{
	int pid;
	int size;
	int AllocatedBlock;
	bool allocated;
	int ExternalFragment;
};

struct Block{
	int size;
	int InternalFragment;
	int status;
};
int main(){
	int numberProcesses,numberBlocks,i,temp,min,j,k,l;


	printf("Enter number of blocks:  ");
	scanf("%d",&numberBlocks);
	struct Block b[numberBlocks];
	bool allocated[numberBlocks];

	printf("Enter number of processes:  ");
	scanf("%d",&numberProcesses);
	struct Process p[numberProcesses];


	for(i=0;i<numberBlocks;i++){
		printf("Enter size and status of %d block: ",i);
		scanf("%d %d",&b[i].size,&b[i].status);
	}

	for(i=0;i<numberProcesses;i++){
		printf("Enter size of %d process: ",i);
		scanf("%d",&p[i].size);
		p[i].pid = i;
		p[i].allocated=false;
	}

	//allocation loop

	for(i=0;i<numberProcesses;i++){
		min = 999999,j=-1;
		for(temp=0;temp<numberBlocks;temp++){
			if(b[temp].status==0){
			if (p[i].size<=b[temp].size && (allocated[temp]==false)){
				b[temp].InternalFragment = abs(b[temp].size-p[i].size);
				if (min>b[temp].InternalFragment){
					min = b[temp].InternalFragment;
					j = temp;
				}
			}
		}
		}
		if(j!=-1){
			p[i].allocated=true;
			p[i].AllocatedBlock = j;
			b[j].size-=p[i].size;
			if (b[j].size<=0){
				allocated[j] = true;

			}
		}
		if (j==-1){
			l=0;
			for(k=0;k<numberBlocks;k++){
				l+=b[k].size;
			}
			if (l<=p[i].size){
				p[i].ExternalFragment=1;
			}
		}
	}
	printf("Process Id\tProcess Size\tAllocated Block\n");
	for(i=0;i<numberProcesses;i++){
		if(p[i].allocated==true)
			printf("%d \t\t%d\t\t %d\n",p[i].pid,p[i].size,p[i].AllocatedBlock);
		else
			printf("%d \t\t%d\t\t Not Allocated\n",p[i].pid,p[i].size);
	}
	for(i=0;i<numberProcesses;i++){
		if(p[i].ExternalFragment==1){
			printf("%d\n",i);
		}
	}
}