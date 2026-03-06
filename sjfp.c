#include<stdio.h>
#include<stdlib.h>
struct process {
int id,at,bt,ct,tat,wt,rt,rem;
};
int main(){
    int n;
    printf("Enter the number of processes");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
            p[i].id=i+1;
            printf("Arrival Time of P%d",p[i].id);
            scanf("%d",&p[i].at);
            printf("Burst time of P%d",p[i].id);
            scanf("%d",&p[i].bt);
            p[i].rem = p[i].bt;
            p[i].rt = -1;
    }
    int Completed=0,time=0,sumTat=0,sumWt=0,sumRT=0;
    printf("ProcessID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    while(Completed!=n){
        int index=-1, minRem=1e9;
        for(int i=0;i<n;i++){
            if(p[i].at<=time && p[i].rem>0){
                if(minRem>p[i].rem){
                minRem=p[i].rem;
                index=i;
            }
        }
    }
    if(index!=-1){
        if(p[index].rt==-1){
            p[index].rt=time-p[index].at;
            sumRT+=p[index].rt;
    }
        p[index].rem--;
        time++;
    if(p[index].rem==0){
        p[index].ct=time;
        p[index].tat=p[index].ct-p[index].at;
        p[index].wt=p[index].tat-p[index].bt;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[index].id,p[index].at,p[index].bt,p[index].ct,p[index].tat,p[index].wt);
        sumTat+=p[index].tat;
        sumWt+=p[index].wt;
        Completed++;
    }
    }
    else{
        time++;
    }
}
    printf("Average TAT: %.2f\n",(float)sumTat/n);
    printf("Average WT:%.2f\n",(float)sumWt/n);
    printf("DONE BY A PRAFUL SRINIVASAN\n");
    return 0;

}
