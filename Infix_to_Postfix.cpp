#include<iostream>
#include<string.h>
#define max 100
using namespace std;
char inf[max],post[max],stack[max];
int top=-1;
int isoperator(char ch){
    switch(ch){
        case '+':case '-':case '*':case '/':return 1;
        default: return 0;
    }
}
int prec(char ch){
    switch(ch){
        case '+':case '-':return 1;break;
        case '*':case '/':return 2;break;
        case '^':return 3;break;
        default :return 0;
    }
}
void push(char ch){
    if(top==max-1){
        cout<<"Overflow\n";
        return;
    }
    top++;
    stack[top]=ch;
}
char pop(){
    if(top==-1){
        cout<<"UnderFlow\n";
        return 0;
    }
    return stack[top--];
}
void inftopost(){
    
    strcat(inf,")");
    push('(');
    int i=0,j=0;
    char ch;
    while(inf[i]!='\0'){
        ch=inf[i];
        if(isalpha(ch) || isdigit(ch)){
            post[j]=ch;
            j++;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            char c=pop();
            while(c!='('){
                post[j]=c;
                j++;
                c=pop();
            }
        }
        else if(isoperator(ch)){
            char c=pop();
            while(isoperator(c)==1 && prec(c)>=prec(ch)){
                post[j]=c;
                j++;
                c=pop();
            }
            push(c);
            push(ch);
        }
        i++;
    }
    post[j]='\0';
}
int main(){
    cout<<"Enter an Infix Expression:\n";
    gets(inf);
    inftopost();
    cout<<post<<'\n';
    return 0;
}