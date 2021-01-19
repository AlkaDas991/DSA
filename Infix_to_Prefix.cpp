#include<iostream>
#include<string.h>
#define max 100
using namespace std;
char stack[max];
int top=-1;
void push(char ch){
    if(top==max-1){
        cout<<"Stack Overflow\n";
        return;
    }
    stack[++top]=ch;
}
char pop(){
    if(top==-1){
        cout<<"Stack Underflow\n";
        return 0;
    }
    return stack[top--];
}
int is_operator(char ch){
    switch(ch){
        case '+':case '-':case '*':case '/':case '^':return 1;
        default:return 0;
    }
}
int prec(char ch){
     switch(ch){
         case '+':case '-':return 1;
         case '*':case '/':return 2;
         case '^':return 3;
         default:return 0;
     }
}
void inftopre(char inf[],char pre[]){
    strrev(inf);
    strcat(inf,"(");
    push(')');
    int i=0,j=0;
    char ch;
    while(inf[i]!='\0'){
        ch=inf[i];
        if(isalpha(ch) || isdigit(ch)){
            pre[j]=ch;
            j++;
        }
        else if(ch==')'){
            push(ch);
        }
        else if(ch=='('){
            char c=pop();
            while(c!=')'){
                pre[j]=c;
                j++;
                c=pop();
            }
        }
        else if(is_operator(ch)){
            char c=pop();
            while(is_operator(c)==1 && prec(c)>prec(ch)){
                pre[j]=c;
                j++;
                c=pop();
            }
            push(c);
            push(ch);
        }
        i++;
    }
    pre[j]='\0';
    strrev(pre);
}
int main(){
    cout<<"Enter an infix Expression\n";
    char inf[max],pre[max];
    gets(inf);
    inftopre(inf,pre);
    cout<<pre<<'\n';
    return 0;
}