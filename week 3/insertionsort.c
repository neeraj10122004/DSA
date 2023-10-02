#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int l=0;l<n;l++){
        scanf("%d",&a[l]);
    }
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(key<=a[j] && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    for(int k=0;k<n;k++){
        printf("%d ",a[k]);
    }
    return 0;
}
