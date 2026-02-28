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
    for(int j=i+1;j<n;j++){
        if(arr[i]==arr[j]){
            printf("Duplicates Found");
            exit(0);
        }
    }
}
printf("No Duplicates");
}
