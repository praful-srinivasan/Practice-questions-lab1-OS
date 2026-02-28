#include<stdio.h> 
#include<stdlib.h>
int main(){
    int arr[10],item;
    printf("Enter the 10 elements in the Array");
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be found");
    scanf("%d",&item);
    for(int i=0;i<10;i++){
        if(arr[i]==item){
            printf("Item found at %d",i+1);
            exit(0);
        }
    }
    printf("Element not found");
}
