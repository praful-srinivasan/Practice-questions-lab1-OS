#include<stdio.h>
struct process {
int id,at,bt,ct,tat,wt;
};
int main(){
    int n;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
        p[i].id=i+1;
        printf("Arrival Time for Process P%d",p[i].id);
        scanf("%d",&p[i].at);
        printf("Burst Time for process P%d",p[i].id);
        scanf("%d",&p[i].bt);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                struct process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    int timePassed=0,sumTat=0,sumWT=0;
    printf("ProcessID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0;i<n;i++){
        if(timePassed<p[i].at)
            timePassed=p[i].at;
        p[i].ct=timePassed+p[i].bt;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        timePassed+=p[i].bt;
        sumTat+=p[i].tat;
        sumWT+=p[i].wt;
    }

    printf("Average TAT:%.2f\n",(float)sumTat/n);
    printf("Average WT:%.2f\n",(float)sumWT/n);
    printf("DONE BY A PRAFUL SRINIVASAN\n");
    return 0;
}
