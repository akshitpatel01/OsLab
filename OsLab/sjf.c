#include<stdio.h>
int j, n, min_pos;
int completed[100];

int indexFinder()
{
  for(j=0; j<n; j++)
  {
    if(completed[j] == 1)
    continue;
    break;
  }
  return j;

}

int findMinExecution(int timer, int at[], int bt[])
{
  min_pos = indexFinder();
  for(j=0; j<n; j++)
  {
    if((at[j] <= timer) && (bt[j] <= bt[min_pos]) && (!completed[j]))
    {
      min_pos = j;
    }
  }
  return min_pos;
}


int main()
{
  printf("Enter no of process: ");
  scanf("%d", &n);
  int i;
  int at[n], bt[n], ct[n];
  for(i = 0; i<n; i++)
  {
    printf("Enter at and bt for p%d:  ", i);
    scanf("%d %d", &at[i], &bt[i]);
  }



  //logic starts
  int timer = 0;
  int count_process = 0;
  //skip pre waste time before first arrival

  while(count_process != n)
  {

    int min_exp = findMinExecution(timer, at, bt);

      count_process++;
      timer += bt[min_exp];
      ct[min_exp] = timer;
      completed[min_exp] = 1;

  }
  //now we have ct[n] full;

  //calculating tat[]
  int tat[n], sumt = 0;
  for(i = 0; i<n; i++)
  {
    tat[i] = ct[i] - at[i];
    sumt += tat[i];
  }

  //calculating wait time full;
  int wt[n], sumw = 0;
  for(i=0; i<n; i++)
  {
    wt[i] = tat[i] - bt[i];
    sumw += wt[i];
  }

  for(i=0; i<n; i++)
  {
    printf("Process %d,  at: %d,  bt: %d,  ct: %d,  tat: %d, wt: %d\n", i, at[i], bt[i], ct[i], tat[i], wt[i]);
  }

  printf("Average WT: %f  Average TAT: %f",(float) sumw/n,(float) sumt/n);


  return 0;
}
