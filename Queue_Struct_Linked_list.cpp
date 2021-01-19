#include<iostream>
#define nl '\n'
using namespace std;
typedef struct queue{
    int data;
    struct queue* next;
}Queue;
Queue *front,*rear;
void push(){
    Queue *curr=new Queue;
    Queue *prevv=rear;
    if(curr==NULL){
        cout<<"Out of Memory\n";
        return;
    }
    cout<<"Enter an element\n";
    cin>>curr->data;
    curr->next=NULL;
    if(front==NULL){
        front=curr;
        rear=curr;
    }
    else{
        prevv->next=curr;
        rear=curr;
    }
}
void pop(){
    if(front==NULL && rear==NULL){
        cout<<"Queue Underflow\n";
        return;
    }
    cout<<"Popped Element from the Queue: "<<front->data<<nl;
    front=front->next;
}
void peek(){
    if(front==NULL && rear==NULL){
        cout<<"Queue Underflow\n";
        return;
    }
    cout<<"The 1st element in queue is: "<<front->data<<nl;
}
void display(){
    Queue *ptr=front;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<nl;
}
int main(){
    while(1){
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
    }
    return 0;
}