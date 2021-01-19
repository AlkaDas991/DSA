#include<iostream>
using namespace std;
typedef struct Stack{
    char data;
    struct Stack *next;
}stack;
stack *top=NULL;
void push(char ele){
    stack *temp=new stack;
    if(temp==NULL){
        cout<<"Out of Memory\n";
        return;
    }
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
    if(top==NULL){
        cout<<"Underflow\n";
        return;
    }
    stack *temp=top;
    top=top->next;
    delete temp;
}
int main(){
    bool flag=true;
    stack stk;
    string str;
    cout<<"Enter a string\n";
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='<' || str[i]=='(' || str[i]=='{'|| str[i]=='[')
            push(str[i]);
        else if(top==NULL){
            flag=false;
            break;
        }
        else if((top->data=='<' && str[i]=='>') 
                || (top->data=='(' && str[i]==')') 
                || (top->data=='{' && str[i]=='}')
                || (top->data=='[' && str[i]==']')){
           pop();
        }
    }
    if(top!=NULL)
        flag=false;
    flag?cout<<"Balanced Parenthesis\n":cout<<"Not a Balanced Parenthesis\n";
    return 0;
}