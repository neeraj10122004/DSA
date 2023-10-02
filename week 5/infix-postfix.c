#include<stdio.h>
#include<string.h>
int size;
int precidence(char x){
    switch (x){
        case '^' :
            return 4;
            break;
        case '*' :
            return 3;
        case '/' :
            return 3;
            break;
        case '+' :
            return 2;
        case '-' :
            return 2;
        default:
            return 0;

    }
}
void push(char* a,int* top,char value){
    printf("push\n");
    if(*top==size-1){
        printf("invalied\n");
    }
    else{
    *top+=1;
    a[*top]=value;
    }
}
char pop(char* a,int* top){
    printf("push\n");
    if(*top==-1){
        printf("invalied\n");
        return 0;
    }
    else{
    char ret = a[*top];
    *top-=1;
    return ret;
    }
}
char peak(char* a,int* top){
    printf("push\n");
    if(*top==-1){
        return '$';
    }
    return a[*top];
}
int main(){
    int top=-1;
    char a[100];
    char retu[100];
    int o=0;
    printf("enter the expresson\n");
    scanf("%s",a);
    size=strlen(a);
    char stack[size];
    for(int i=0;i<size;i++){
        char p=a[i];
        char next;
        switch (p)
        {
            case ')' :
                next=pop(a,&top);
                while(next!='('){
                    retu[o++]=next;
                    next=pop(a,&top);
                }
                break;
            case '+' :
            case '-' :
            case '*' :
            case '/' :
            case '^' :
                while(peak(a,&top)!='$' && precidence(p)<=precidence(peak(a,&top))){
                    retu[o++]=pop(a,&top);
                }
                push(a,&top,p);
                break;
            default :
                retu[o++]=p;
        }
    }
    while(top>=0){
        retu[o++]=pop(a,&top);
    }
    for(int j=0;j<size;j++){
        printf("%c",retu[j]);
    }
    return 0;
}