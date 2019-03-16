/// The Programs takes profit and deadline of a Job as Input and then it select the Job which can give max Profit.
#include<stdio.h>
typedef struct
{
    int profit;
    int deadline;
} Job;
void swapJobs(Job *j1,Job *j2)
{
    int p,d;
    p=j1->profit;
    d=j1->deadline;
    j1->profit=j2->profit;
    j1->deadline=j2->deadline;
    j2->profit=p;
    j2->deadline=d;

}
void sortJobs(Job J[],int n)    /// sorting the jobs in decreasing order of their profit using bubble sort
{
    int i,j;
    Job temp;
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<n-i;j++)
        {
            if(J[j].profit<J[j+1].profit)
            {
               swapJobs(&J[j],&J[j+1]);

            }
        }
    }

}
void jobShcheduling(Job J[],int S[],int n)
{
    int i,k,r,q;
    S[0]=0;
    S[1]=1;
    k=1;
    for(i=2;i<n;i++)
    {
        r=k;
        while(J[S[r]].deadline>J[i].deadline&&S[r]>r)
        {
            r--;
        }
        if(J[S[r]].deadline<=J[i].deadline&&J[i].deadline>r)
        {
            for(q=k;q>r+1;q--)
            {
                S[q+1]=S[q];
            }
            S[r+1]=i;
            k++;
        }
    }
    printf("\nOptimal Soluation :-");
    printf("\nProfit  Deadline  Soluation\n");
    for(i=1;i<=k;i++)
    {

        printf("%d\t%d\t%d\n",J[S[i]].profit,J[S[i]].deadline,S[i]);
    }


}
void display(Job J[],int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        printf("%d\t%d\n",J[i].profit,J[i].deadline);
    }
}
void inputJobs(Job J[],int n)
{
    int i;
    printf("\nEnter the Job's profit and Deadline of Job");
    for(i=1;i<n;i++)
    {
        scanf("%d",&J[i].profit);
        scanf("%d",&J[i].deadline);
    }
}
int main()
{
    Job J[1000];
    int n;
    int S[1000]={0};
    printf("\nEnter the number of Jobs :-");
    scanf("%d",&n);
    if(n>999)
        return 0;
    inputJobs(J,n+1);
    sortJobs(J,n+1);
    printf("\nAfter sorting of Jobs :-\n");
    display(J,n+1);
    jobShcheduling(J,S,n+1);
}
