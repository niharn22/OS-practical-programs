#include<stdio.h>
#include<conio.h>
#define max 30
void main()
{
    int i,j,n,t,p[max],bt[max],wt[max],tat[max];
    float awt=0,atat=0;
    printf("Enter number of processes : \n");
    scanf("%d",&n);
    printf("Enter the process number : \n");
    for(i=0;i<n;i++)
    scanf("%d",&p[i]);
    printf("Enter burst time of process : \n");
    for(i=0;i<n;i++)
    scanf("%d",&bt[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
            t=bt[j];
            bt[j]=bt[j+1];
            bt[j+1]=t;

            t=p[j];
            p[j]=p[j+1];
            p[j+1]=t;
            }
        }
    }
    printf("Process \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++)
        wt[i]+=bt[j];
        tat[i]=wt[i]+bt[i];
        awt+=wt[i];
        atat+=tat[i];
        printf("%d\t\t\t %d\t\t %d\t\t %d\n",p[i],bt[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("Average Waiting Time = %f\n",awt);
    printf("Average Turnaround Time = %f\n",atat);
}
