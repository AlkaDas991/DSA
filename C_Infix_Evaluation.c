#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 10
char oprtr[max],oprnd[max];
int oprnd_top=-1,oprtr_top=-1;
void push_oprnd(int ele){
    if(oprnd_top==max-1){
        printf("Stack Overflow\n");
        return;
    }
    oprnd[++oprnd_top]=ele;
}
void push_oprtr(char c){
    if(oprtr_top==max-1){
        printf("Stack Overflow\n");
        return;
    }
    oprtr[++oprtr_top]=c;
}
int pop_oprnd(){
    if(oprnd_top==-1){
        printf("Stack Underflow\n");
        return 0;
    }
    return oprnd[oprnd_top--];
}
char pop_oprtr(){
    if(oprtr_top==-1){
        printf("Stack Underflow\n");
        return  0;
    }
    return oprtr[oprtr_top--];
}
int isoperator(char c){
    switch(c){
        case '+':case '-':case '*':case '/':case '^':return 1;
        default:return 0;
    }
}
int prec(char c){
    switch(c){
        case '^':return 3;
        case '*':case '/':return 2;
        case '+':case '-':return 1;
        default:return 0;
    }
}
int infix_evaluate(char infix[]){
    push_oprtr('(');
    strcat(infix,")");
    int val=0,i=0,data=0,flag=0;
    char ch;
    while(infix[i]!='\0'){
        ch=infix[i];
        if(isdigit(ch))//for more than one digit numbers
        {
            data=data*10+(ch-48);
            flag=1;
            i++;
            continue;
        }
        if(flag==1){
            push_oprnd(data);
            flag=0;
            data=0;
        }
        if(isalpha(ch)){
            push_oprnd(ch);
        }
        else if(ch=='('){
            push_oprtr(ch);
        }
        else if(ch==')'){
            char c=pop_oprtr();
            while(c!='('){
                int b=pop_oprnd();
                int a=pop_oprnd();
                switch(c){
                    case '+':val=a+b;break;
                    case '-':val=a-b;break;
                    case '*':val=a*b;break;
                    case '/':val=a/b;break;
                    case '^':val=(int)(pow(a,b)+0.5);break;
                    default:break;
                }
                push_oprnd(val);
                c=pop_oprtr();
            }
        }
        else if(isoperator(ch)){
            char c=pop_oprtr();
            while(isoperator(c)==1 && prec(c)>=prec(ch)){
                int b=pop_oprnd();
                int a=pop_oprnd();
                switch(c){
                    case '+':val=a+b;break;
                    case '-':val=a-b;break;
                    case '*':val=a*b;break;
                    case '/':val=a/b;break;
                    case '^':val=(int)(pow(a,b)+0.5);break;
                    default:break;
                }
                push_oprnd(val);
                c=pop_oprtr();
            }
            push_oprtr(c);
            push_oprtr(ch);
        }
        i++;
    }
    return oprnd[oprnd_top];
}
int main(){
    char infix[100];
    printf("Enter an Infix Expression:\n");
    gets(infix);
    printf("%d\n",infix_evaluate(infix));
    return 0;
}