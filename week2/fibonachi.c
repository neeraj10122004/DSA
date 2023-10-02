#include<stdio.h>
#include<stdlib.h>
#define n 10
int main(){
    int l[n]={1,2,3,4,5,6,7,8,9,10};
    int key;
    scanf("%d",&key);
    int ch=2;
    int fab[n];
    fab[0]=0;
    fab[1]=1;
    while(ch<=n){
        fab[ch]=fab[ch-1]+fab[ch-2];
        if(fab[ch]>=n){
            break;
        }
        ch++;
    }
    //printf("%d %d %d\n",fab[ch-2],fab[ch-1],fab[ch]);
    int offset=-1;
    for(int i=0;fab[ch-2]>=l[0];i++){
        int k;
        if((offset+fab[ch-2])>(n-1)){
            k=n-1;
        }
        else{
            k=offset+fab[ch-2];
        }
        if(l[k]==key){
            printf("found");
            exit(1);
        }
        else if(l[k]<key){
            ch=ch-1;
            offset=k;
        }
        else{
            ch=ch-2;
        }
    }
    printf("not found");
    return 0;
}