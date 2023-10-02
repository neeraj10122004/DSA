#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int l=0;l<n;l++){
        scanf("%d",&a[l]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
            a[i]=a[i]+a[j];
            a[j]=a[i]-a[j];
            a[i]=a[i]-a[j];
        }}
    }
    for(int k=0;k<n;k++){
        printf("%d ",a[k]);
    }
    return 0;
}