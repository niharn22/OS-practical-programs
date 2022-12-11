#include<stdio.h>
#include<stdlib.h>
#define max 30
void main()
{
    int i,j,n,bt[max],p[max],compt[max],wt[max],tat[max],temp1,temp2;
    float awt=0,atat=0;
    printf("Enter number of processes : \n");
    scanf("%d",&n);
    printf("Enter Burst Time : \n");
    for(i=0;i<n;i++)
    scanf("%d",&bt[i]);
    printf("Enter Priority : \n");
    for(i=0;i<n;i++)
    scanf("%d",&p[i]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i]>p[j])
            {
                temp1=bt[i];
                bt[i]=bt[j];
                bt[j]=temp1;

                temp2=p[i];
                p[i]=p[j];
                p[j]=temp2;
            }
        }
    }
    compt[0]=bt[0];
    wt[0]=0;
    for(i=0;i<n;i++)
    compt[i]=bt[i]+compt[i-1];
    for(i=0;i<n;i++)
    {
        tat[i]=compt[i];
        wt[i]=tat[i]-bt[i];
        atat+=tat[i];
        awt+=wt[i];
    }
    atat=atat/n;
    awt=awt/n;
    printf("Average Waiting Time = %f\n",awt);
    printf("Average Turnaround Time = %f\n",atat);
}
