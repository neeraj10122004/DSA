#include<stdio.h>
#define n 6
int partition(int a[],int l,int u){
    int pivot=a[l];
    int i=l;
    int j=u;
    while(i<j){
        while(a[i]<pivot){
            i++;
        }
        while (a[j]>pivot)
        {
            j--;
        }
        if(i<j){
            a[i]=a[i]+a[j];
            a[j]=a[i]-a[j];
            a[i]=a[i]-a[j];
        }
    }
    a[j]=a[j]+pivot;
    pivot=a[j]-pivot;
    a[j]=a[j]-pivot;
    return j;
}
void qs(int a[],int l,int u){
    if(l<u){
        int c=partition(a,l,u);
        qs(a,l,c-1);
        qs(a,c+1,u);
    }
}
int main(){
    int a[n]={2,1,4,23,11,5};
    qs(a,0,n-1);
    for(int k=0;k<n;k++){
    printf("%d ",a[k]);
    }
    return 0;
}