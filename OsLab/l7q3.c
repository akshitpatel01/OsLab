#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "math.h"

struct Process{
	int pid;
	int size;
	int AllocatedBlock;
	bool allocated;
};

struct Block{
	int size;
	int InternalFragment;
};
int main(){
	int numberProcesses,numberBlocks,i,temp,max,j;


	printf("Enter number of blocks:  ");
	scanf("%d",&numberBlocks);
	struct Block b[numberBlocks];
	bool allocated[numberBlocks];

	printf("Enter number of processes:  ");
	scanf("%d",&numberProcesses);
	struct Process p[numberProcesses];


	for(i=0;i<numberBlocks;i++){
		printf("Enter size of %d block: ",i);
		scanf("%d",&b[i].size);
	}

	for(i=0;i<numberProcesses;i++){
		printf("Enter size of %d process: ",i);
		scanf("%d",&p[i].size);
		p[i].pid = i;
		p[i].allocated=false;
	}

	//allocation loop

	for(i=0;i<numberProcesses;i++){
		max = -5,j=-1;
		for(temp=0;temp<numberBlocks;temp++){
			if (p[i].size<=b[temp].size && (!allocated[temp])){
				b[temp].InternalFragment = abs(b[temp].size-p[i].size);
				if (max>b[temp].InternalFragment){
					max = b[temp].InternalFragment;
					j = temp;
				}
			}
			
		}
		if(j!=-1){
			p[i].allocated=true;
			p[i].AllocatedBlock = j;
			allocated[j]=true;
		}		
	}
	printf("Process Id\tProcess Size\tAllocated Block\n");
	for(i=0;i<numberProcesses;i++){
		if(p[i].allocated==true)
			printf("%d \t\t%d\t\t %d\n",p[i].pid,p[i].size,p[i].AllocatedBlock);
		else
			printf("%d \t\t%d\t\t Not Allocated\n",p[i].pid,p[i].size);
	}

	for(i=0;i<numberBlocks;i++){
		printf("Internal Fragment of block %d is: %d\n",i,b[i].InternalFragment);
	}
}