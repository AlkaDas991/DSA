#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
typedef struct Expression{
    char data;
    struct Expression *next;
}exp;
exp *infix=NULL,*prefix=NULL;
char stack[MAX],inf[MAX];
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
    if(top==MAX-1){
        printf("Overflow\n");
        return;
    }
    top++;
    stack[top]=ch;
}
char pop(){
    if(top==-1){
        printf("UnderFlow\n");
        return 0;
    }
    return stack[top--];
}
void create_nodePrefix(char ele){
    exp *temp=(exp*)malloc(sizeof(exp));
    if(temp==NULL){
        printf("Out Of Memory\n");
        return;
    }
    temp->data=ele;
    temp->next=prefix;
    prefix=temp;
}
void create_nodeInfix(char ele){
    exp *temp=(exp*)malloc(sizeof(exp));
    if(temp==NULL){
        printf("Out Of Memory\n");
        return;
    }
    temp->data=ele;
    temp->next=infix;
    infix=temp;
}
void inftoprefix(){
    exp *ptr=infix;
    int j=0;
    push(')');
    char ch;
    while(ptr!=NULL){
        ch=ptr->data;
        if(isalpha(ch) || isdigit(ch)){
            create_nodePrefix(ch);
        }
        else if(ch==')'){
            push(ch);
        }
        else if(ch=='('){
            char c=pop();
            while(c!=')'){
               create_nodePrefix(c);
               c=pop();
            }
        }
        else if(isoperator(ch)){
            char c=pop();
            while(isoperator(c)==1 && prec(c)>prec(ch)){
                create_nodePrefix(c);
                c=pop();
            }
            push(c);
            push(ch);
        }
        ptr=ptr->next;
    }
}
void display(){
    exp *ptr=prefix;
    while(ptr!=NULL){
        printf("%c",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    printf("Enter Infix Expression:\n");
    gets(inf);
    int i=0;
    while(inf[i]!='\0'){
        create_nodeInfix(inf[i]);
        i++;
    }
    create_nodeInfix('(');
    inftoprefix();
    display();
    return 0;
}
