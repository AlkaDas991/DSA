#include<iostream>
#define nl '\n'
using namespace std;
typedef struct queue{
    int data;
    struct queue* next;
}Queue;
void inqueue(Queue **front,Queue **rear){
    Queue *curr=new Queue;          
    if(curr==NULL){
        cout<<"Out of Memory\n";
        return;
    }
    cout<<"Enter an element\n";
    cin>>curr->data;
    curr->next=NULL;
    if(*front==NULL){
        *front=curr;
        *rear=curr;
    }
    else{
        (*rear)->next=curr;
        *rear=curr;
    }
}
void dequeue(Queue **front,Queue **rear){
    if(front==NULL && rear==NULL){
        cout<<"Queue Underflow\n";
        return;
    }
    cout<<"Popped Element from the Queue: "<<(*front)->data<<nl;
    Queue *temp=*front;
    *front=(*front)->next;
    free(temp);
}
void peek(Queue **front,Queue **rear){
    if(*front==NULL && *rear==NULL){
        cout<<"Queue Underflow\n";
        return;
    }
    cout<<"The 1st element in queue is: "<<(*front)->data<<nl;
}
void display(Queue **front){
    Queue *ptr=*front;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<nl;
}
int main(){
    Queue *front=NULL,*rear=NULL;
    while(1){
        int ch;
        cout<<"Enter your choice:\n1.inqueue\n2.dequeue\n3.PEEK\n4.Display\n5.EXIT\n";
        cin>>ch;
        switch(ch){
            case 1:inqueue(&front,&rear);break;
            case 2:dequeue(&front,&rear);break;
            case 3:peek(&front,&rear);break;
            case 4:display(&front);break;
            case 5:exit(0);break;
            default:
            cout<<"Invalid Choice\n";
        }
    }
    return 0;
}