#include<iostream>
#define nl '\n'
using namespace std;
typedef struct Stack{
    int data;
    struct Stack* next;
}Stack;
Stack *top=NULL,*curr,*prevv;
void push(){
    curr=new Stack;
    if(curr==NULL){
        cout<<"Out of Memory\n";
        return;
    }   
    cout<<"Enter an Element:\n";
    cin>>curr->data;
    prevv=top;
    top=curr;
    top->next=prevv;                                          
}
void pop(){
    if(top==NULL){
        cout<<"Stack Underflow\n";
        return;
    }
    cout<<"The popped element is: "<<top->data<<nl;
    top=top->next;
}
void peek(){
    if(top==NULL){
        cout<<"Stack Underflow\n";
        return;
    }
    cout<<"The top element is: "<<top->data<<nl;
}
void display(){
    Stack *ptr=top;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<nl;
}
int main(){
    char c='y';
    while(c=='y' || c=='Y'){
        int ch;
        cout<<"Enter your choice:\n1.PUSH\n2.POP\n3.PEEK\n4.Display\n5.EXIT\n";
        cin>>ch;
        switch(ch){
            case 1:push();break;
            case 2:pop();break;
            case 3:peek();break;
            case 4:display();break;
            case 5:exit(0);break;
            default:
            cout<<"Invalid Choice\n";
        }
        cout<<"Do you want to continue(y/n)\n";
        cin>>c;
    }
    return 0;
}