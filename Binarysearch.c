#include<stdio.h>
#include<stdlib.h>
int main(){
int n;
printf("Enter the number of elements in the array\n");
scanf("%d",&n);
printf("Enter array elements\n");
int arr[n];
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
int item;
printf("Enter the item to be found\n");
scanf("%d",&item);
int beg=0,end=n-1,mid;
while(beg<=end){
    mid=(int)(beg+end)/2;
    if(arr[mid]==item){
        printf("Item found at %d",mid+1);
        exit(0);
    }
    else if(item<arr[mid]){
        end=mid-1;
        continue;
    }
    beg=mid+1;
}
printf("Item not found");
}
