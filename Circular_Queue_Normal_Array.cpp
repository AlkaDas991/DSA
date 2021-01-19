#include<iostream>
#define nl '\n'
using namespace std;
int maxx;
void inqueue(int *arr,int *front,int *rear){
    if((*front==0 && *rear==maxx-1) || (*front==*rear+1)){
        cout<<"Circular Queue Overflow\n";
        return;
    }
    int ele;
    cout<<"Enter an element\n";
    cin>>ele;
    if(*front==-1){
        *front=0;
        *rear=0;
    }
    else if(*rear==maxx-1)
        *rear=0;
    else
        (*rear)++;
    arr[*rear]=ele;
    cout<<*front<<" "<<*rear<<nl;
}
void dequeue(int *arr,int *front,int *rear){
    if(*front==-1){
        cout<<"Circular Dequeue\n";
        return;
    }
    cout<<"Dequeued Element: "<<arr[*front]<<nl;
    if(*front==*rear)
    {
        *front=-1;
        *rear=-1;
    }
    else if(*front==maxx-1)
        *front=0;
    else
        (*front)++;
}
void peek(int *arr,int *front){
    if(*front==-1){
        cout<<"Circular Dequeue Underflow\n";
        return;
    }
    cout<<"Element at the front: "<<arr[*front]<<nl;
}
void display(int *arr,int *front,int *rear){
    if(*front==-1){
        cout<<"Empty Circular Queue\n";
        return;
    }
    if(*rear>=*front)
    {
        for(int i=*front;i<=*rear;i++)
            cout<<arr[i]<<" ";
        cout<<nl;
    }
    else
    {
        for(int i=*front;i<=maxx-1;i++)
            cout<<arr[i]<<" ";
        for(int i=0;i<=*rear;i++)
            cout<<arr[i]<<" ";
        cout<<nl;
    }
}
int main(){
    int front=-1,rear=-1;
    cout<<"Enter no of elements to be inserted in the Queue:\n";
    cin>>maxx;
    int *arr= new int[maxx];
    while(1){
        int ch;
        cout<<"Enter your choice:\n1.Inqueue\n2.Dequeue\n3.Peek\n4.Display\n5.EXIT\n";
        cin>>ch;
        switch(ch){
            case 1:inqueue(arr,&front,&rear);break;
            case 2:dequeue(arr,&front,&rear);break;
            case 3:peek(arr,&front);break;
            case 4:display(arr,&front,&rear);break;
            case 5:exit(0);break;
            default:
            cout<<"Invalid Choice\n";
        }
    }
    return 0;
}