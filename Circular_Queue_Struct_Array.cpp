#include<iostream>
#define nl '\n'
using namespace std;
struct cirQueue{
    int front;
    int *arr;
    int rear;
}cq{.front=-1,.rear=-1};
int maxx;
void inqueue(){
    if((cq.rear==maxx-1 && cq.front==0) || (cq.front==cq.rear+1)){
        cout<<"Circular Queue OverFlow\n";
        return;
    }
    cout<<"Enter an element\n";
    int ele;
    cin>>ele;
    if(cq.front==-1){
        cq.front=0;
        cq.rear=0;
    }
    else if(cq.rear==maxx-1)
        cq.rear=0;
    else
        cq.rear++;
    cq.arr[cq.rear]=ele;
}
void dequeue(){
    if(cq.arr[cq.front]==NULL){
        cout<<"Circular Queue Underfllow\n";
        return;
    }
    cout<<"Removed data: "<<cq.arr[cq.front]<<nl;
    if(cq.front==cq.rear){
        cq.front=-1;
        cq.rear=-1;
    }
    else
        cq.front=cq.front++;
}
void peek(int *arr){
    if(front==NULL){
        cout<<"Circular Queue Underflow\n";
        return;
    }
    cout<<"First element in the Circular queue:"<<front->data<<nl;
}
void display(int *arr){
    if(front==NULL)
    {
        cout<<"Empty Circular Queue\n";
        return;
    }
    CirQueue* temp=front;
    do{
        cout<<temp->data;
        temp=temp->next;
    }while(temp!=front);
}
int main(){
    CirQueue cq{.front=-1,.rear=-1};
    cout<<"Enter no of elements to be inserted in the Queue:\n";
    cin>>maxx;
    cq.arr=new int[maxx];
    while(1){
        int ch;
        cout<<"Enter your choice:\n1.Inqueue\n2.Dequeue\n3.Peek\n4.Display\n5.EXIT\n";
        cin>>ch;
        switch(ch){
            case 1:inqueue(&cq);break;
            case 2:dequeue(&cq);break;
            case 3:peek(&cq);break;
            case 4:display(&cq);break;
            case 5:exit(0);break;
            default:
            cout<<"Invalid Choice\n";
        }
    }
 return 0;
}