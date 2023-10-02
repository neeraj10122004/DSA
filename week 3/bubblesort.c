#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int l[n];
    for(int m=0;m<n;m++){
        scanf("%d",&l[m]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(l[j]>l[j+1]){
                l[j]=l[j+1]+l[j];
                l[j+1]=l[j]-l[j+1];
                l[j]=l[j]-l[j+1];
            }
        }
    }
    for(int k=0;k<n;k++){
    printf("%d ",l[k]);
    }
}