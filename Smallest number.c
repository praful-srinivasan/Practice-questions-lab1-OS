#include<stdio.h>
#include<stdlib.h>
void main(){
int n,min=1000000;
int arr[n];
printf("Enter the n");
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
for(int i=0;i<n;i++){
    if(arr[i]<min)
        min=arr[i];
}
printf("Smallest Element %d",min);
}
