#include<iostream>
#define nl '\n'
using namespace std;
typedef struct Stack{
    int data;
    struct Stack* next;
}Stack;
Stack* push(Stack* top){
    Stack *curr,*prevv;
    curr=new Stack;
    if(curr==NULL){
        cout<<"Out of Memory\n";
        return top;
    }   
    cout<<"Enter an Element:\n";
    cin>>curr->data;
    prevv=top;
    top=curr;
    top->next=prevv; 
    return top;                                         
}
Stack* pop(Stack* top){
    if(top==NULL){
        cout<<"Stack Underflow\n";
        return top;
    }
    cout<<"The popped element is: "<<top->data<<nl;
    top=top->next;
    return top;
}
Stack* peek(Stack* top){
    if(top==NULL){
        cout<<"Stack Underflow\n";
        return top;
    }
    cout<<"The top element is: "<<top->data<<nl;
    return top;
}
void display(Stack* top){
    Stack *ptr=top;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<nl;
}
int main(){
    Stack* top=NULL;
    char c='y';
    while(c=='y' || c=='Y'){
        int ch;
        cout<<"Enter your choice:\n1.PUSH\n2.POP\n3.PEEK\n4.Display\n5.EXIT\n";
        cin>>ch;
        switch(ch){
            case 1:top=push(top);break;
            case 2:top=pop(top);break;
            case 3:top=peek(top);break;
            case 4:display(top);break;
            case 5:exit(0);break;
            default:
            cout<<"Invalid Choice\n";
        }
        cout<<"Do you want to continue(y/n)\n";
        cin>>c;
    }
    return 0;
}