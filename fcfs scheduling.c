#include<stdio.h>
#include<conio.h>
#define max 30
void main()
{
    int i,j,n,bt[max],at[max],wt[max],tat[max],temp[max];
    float awt=0,atat=0;
    printf("Enter number of processes : \n");
    scanf("%d",&n);
    printf("Enter the burst time of process : \n");
    for(i=0;i<n;i++)
    scanf("%d",&bt[i]);
    printf("Enter the arrival time of the process : \n");
    for(i=0;i<n;i++)
    scanf("%d",&at[i]);
    temp[0]=0;
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\n",i+1,bt[i],at[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("Average Waiting Time = %f\n",awt);
    printf("Average Turnaround Time = %f\n",atat);
}