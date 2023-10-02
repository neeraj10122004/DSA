#include<stdio.h>
#define n 5
//int b[5];
void merge(int *a,int l,int m,int u){
    int b[u+1];
    int i=l;
    int j=m+1;
    int k=0;
    while(i<=m && j<=u){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    while(j<=u){
        b[k++]=a[j++];
    }
    while(i<=m){
        b[k++]=a[i++];
    }
    for(int o=l;o<=u;o++){
        a[o]=b[o-l];
    }
}
void mergesort(int *a,int l,int u){
    if(l<u){
        int m=(l+u)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,u);
        merge(a,l,m,u);
    }
    else{
        return ;
    }
}
int main(){
    int a[n]={2,4332,341,324,1};
    int b[n];
    mergesort(a,0,n-1);
    for(int k=0;k<n;k++){
        printf("%d ",a[k]);
    }
    return 0;
}