#include<stdio.h>

int queue[100];
int f,r = -1;
int timer = 0;
int at[100],bt[100],ct[100];
int timeQuantum = 2;
int p,i;
int found[100];

void push(int data)
{
	queue[++r] = data;
}

int pop(void)
{	
	if(f>r) return printf("\nUnderflow!"); 
	int popped = queue[f] ;
	queue[f++] = -1;
	return popped;
	
}
		
int seek(void)
{
	if (f>r)
	return printf("\nqueue is empty");
	
	return queue[f];
}

int isEmpty(void)
{
	if(f>r)
	return 1;
	
	return 0;
}



int pushArrived(void) // Assuming at is in ascending order;
{
	for(i = 0; i<p; i++)
	if( (at[i] <= timer) && !found[i] )
		{ push(i); found[i] = 1; }
		
}
	
void main()
{	
	
	
	
	printf("\nEnter no of processes: "); scanf("%d",&p);
	
	
	//initializing queue to -1;	

	for(i = 0; i < 100; i++)
	{
		queue[i] = -1;
	}
	
		
	 
	for(i = 0; i<p; i++)
	{
		printf("\nEnter at bt for process%d: ", i);
		scanf("%d %d", &at[i], &bt[i]);
	}

	int btCopy[100];
	for(i = 0; i<p; i++)
	{
		btCopy[i] = bt[i];
	}
	//i have copy of the original bt now

	// doing rr;
	
	pushArrived();

	while(isEmpty())
	{
		timer++;
		pushArrived();
	}

	int popped;
	
	if(timer !=0)
	printf("\nCPU was IDEAL for %d ms", timer); 
	
	while( !isEmpty() )
	{
		
		
		popped = pop();
		
		
		if((bt[popped] <= timeQuantum))
		{		
			timer += bt[popped];		//process done
			ct[popped] = timer;
			continue;
					
		}				
		
		else{
			timer += timeQuantum;
			bt[popped] -= timeQuantum;
			
			if(bt[popped] == 0)
			{
			ct[popped] = timer;			
			continue;	//process done
			}			
			pushArrived(); //arrived yet has been pushed now.
			push(popped);
		    }
		

	

	}

	int tat[100], wt[100];
	int sumt = 0, sumw = 0;	
	
	for(i = 0; i<p; i++)
	{
		tat[i] = ct[i] - at[i];
		sumt += tat[i];

		wt[i] = tat[i] - btCopy[i];	
		sumw += wt[i];	
	}
	
	if(isEmpty())
	printf("\nWORKED CORRECTLY!!");


	for(i = 0; i<p; i++)
	{
		printf("\nProcess%d  at: %d,  bt: %d,  ct: %d,  tat: %d,  wt: %d", i, at[i], btCopy[i], ct[i], tat[i], wt[i]);
	}

	printf("\nAverage tat: %f  Average wt: %f", (float) sumt/p, (float) sumw/p);

}  
