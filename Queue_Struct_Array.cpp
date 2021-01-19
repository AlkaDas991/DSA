#include<iostream>
#define nl '\n'
using namespace std;
typedef struct queue{
    int front;
    int *arr;
    int rear;
}Queue;
int maxx;
void push(Queue *q){
    if(q->rear==maxx-1 && q->front==0){
        cout<<"Stack Overflow\n";
        return;
    }
    int ele;
    cout<<"Enter an element\n";
    cin>>ele;
    if(q->front==-1)
        q->front++;
    q->rear++;
    q->arr[q->rear]=ele;
}
void pop(Queue *q){
    if(q->rear==-1 && q->front==-1){
        cout<<"Stack Underflow\n";
        return;
    }
    cout<<"The popped element is: "<<q->arr[q->front]<<nl;
    q->front++;
}
void peek(Queue *q){
    if(q->rear==-1 && q->front==-1){
        cout<<"Stack Underflow\n";
        return;
    }
    cout<<"The 1st element in queue is: "<<q->arr[q->front]<<nl;
}
void display(Queue *q){
    for(int i=q->front;i<=q->rear;i++)
        cout<<q->arr[i]<<" ";
    cout<<nl;
}
int main(){
    Queue q{.front=-1,.rear=-1};
    cout<<"Enter the maximium capacity of queue\n";
    cin>>maxx;
    q.arr=new int[maxx];
    char c='y';
    while(c=='y' || c=='Y'){
        int ch;
        cout<<"Enter your choice:\n1.PUSH\n2.POP\n3.PEEK\n4.Display\n5.EXIT\n";
        cin>>ch;
        switch(ch){
            case 1:push(&q);break;
            case 2:pop(&q);break;
            case 3:peek(&q);break;
            case 4:display(&q);break;
            case 5:exit(0);break;
            default:
            cout<<"Invalid Choice\n";
        }
        cout<<"Do you want to continue(y/n)\n";
        cin>>c;
    }
    return 0;
}