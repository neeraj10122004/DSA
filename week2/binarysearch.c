//binary search
#include <stdio.h>
#include <stdlib.h>
#define n 5
int main(){
    int key,max,min,mid;
    int a[n]={1,2,3,4,5};
    scanf("%d",&key);
    max=n-1;
    min=0;
    mid=(max+min)/2;
    while(max>=min){
        if(key==a[mid]){
            printf("found\n");
            exit(1);
        }
        else if(a[mid]>key){
            max=mid-1;
            mid=(max+min)/2;
        }
        else if(a[mid]<key){
            min=mid+1;
            mid=(max+min)/2;
        }}
    printf("not found");
    return 0;
}