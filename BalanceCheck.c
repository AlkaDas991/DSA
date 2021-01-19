#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Stack{
    char data;
    struct Stack *next;
}stack;
stack *top=NULL;
void push(char ele){
    stack *temp=(stack*)malloc(sizeof(stack));
    temp->data=ele;
    temp->next=NULL;
    if(top==NULL)
        top=temp;
    else{
        temp->next=top;
        top=temp;
    }
}
void pop(){
    stack *temp=top;
    top=top->next;
    free(temp);
}
int main(){
    int flag=1,i=0;
    stack stk;
    char str[MAX];
    printf("Enter a string\n");
    gets(str);
    while(str[i]!='\0'){
        if(str[i]=='<' || str[i]=='(' || str[i]=='{'|| str[i]=='[')
            push(str[i]);
        else if(top==NULL){
            flag=0;
            break;
        }
        else if((top->data=='<' && str[i]=='>') 
                || (top->data=='(' && str[i]==')') 
                || (top->data=='{' && str[i]=='}')
                || (top->data=='[' && str[i]==']')){
           pop();
        }
        i++;
    }
    if(top!=NULL)
        flag=0;
    flag==1?printf("Balanced Parenthesis\n"):printf("Not a Balanced Parenthesis\n");
    return 0;
}