#include<iostream>
#define nl '\n'
using namespace std;
typedef struct cirQueue{
    int data;
    struct cirQueue* next;
}CirQueue;
CirQueue *front=NULL,*rear=NULL;
void inqueue(){
    CirQueue* curr= new CirQueue;
    if(curr==NULL){
        cout<<"Out of Memory\n";
        return;
    }
    cout<<"Enter an element\n";
    cin>>curr->data;
    curr->next=curr;
    if(front==NULL){
        front=curr;
        rear=curr;
        return;
    }
    rear->next=curr;
    rear=curr;
    rear->next=front;
}
void dequeue(){
    if(front==NULL){
        cout<<"Circular Queue Underfllow\n";
        return;
    }
    CirQueue* temp=front;
    cout<<"Removed data: "<<temp->data<<nl;
    if(front==rear){
        front=NULL;
        rear=NULL;
    }
    else{
        front=front->next;
        rear->next=front;
    }
    free(temp);
}
void peek(){
    if(front==NULL){
        cout<<"Circular Queue Underflow\n";
        return;
    }
    cout<<"First element in the Circular queue:"<<front->data<<nl;
}
void display(){
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
     while(1){
        int ch;
        cout<<"Enter your choice:\n1.Inqueue\n2.Dequeue\n3.Peek\n4.Display\n5.EXIT\n";
        cin>>ch;
        switch(ch){
            case 1:inqueue();break;
            case 2:dequeue();break;
            case 3:peek();break;
            case 4:display();break;
            case 5:exit(0);break;
            default:
            cout<<"Invalid Choice\n";
        }
    }
 return 0;
}