#include<stdio.h>

int part(int a[],int l,int u){
    int p=a[l];
    int i=l;
    int j=u;
    while(i<j){
        while(a[i]<p){
            i++;
        }
        while(a[j]>p){
            j--;
        }
        if(i<j){
            a[i]=a[i]+a[j];
            a[j]=a[i]-a[j];
            a[i]=a[i]-a[j];
        }
    }
    a[j]=p+a[j];
    p=a[j]-p;
    a[j]=a[j]-p;
    return j;
}
void quicksort(int a[],int l,int u){
    if(l<u){
    int temp=part(a,l,u);
    quicksort(a,l,temp-1);
    quicksort(a,temp+1,u);
    }
}
int main(){
    int l;
    scanf("%d",&l);
    int a[l];
    //input
    for(int i=0;i<l;i++){
        scanf("%d",&a[i]);
    }
    //sorting
    quicksort(a,0,l);
    //printing
    for(int k=0;k<l;k++){
    printf("%d ",a[k]);
    }
    return 0;
}
