//linear search
#include <stdio.h>
#include<stdlib.h>
#define n 5
int main(){
    int key;
    int a[n]={23,56,77,54,34};
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(key==a[i]){
            printf("found\n");
            exit(1);
        }
    }
    printf("not found\n");
    return 0;
}