//insert at one front-end,delete at both ends
#include<iostream>
using namespace std;
int maxx,front=-1,rear=-1;
void enqueue_front(int *arr){
    if(front==(rear+1)%maxx)
    {
        cout<<"circular Dequeue Overflow\n";
        return;
    }
    int ele;
    cout<<"Enter an element\n";
    cin>>ele;
    if(front==-1){
        front=0;
        rear=0;
    }
    else if(front==0)
        front=maxx-1;
    else
        front--;
    arr[front]=ele;
}
void enqueue_rear(int *arr){
    if(front==(rear+1)%maxx)
    {
        cout<<"circular Dequeue Overflow\n";
        return;
    }
    int ele;
    cout<<"Enter an element\n";
    cin>>ele;
    if((rear==-1) || (rear==maxx-1))
        rear=0;
    else
        rear++;
    arr[rear]=ele;
}
void delete_front(int* arr){
    if(front==-1){
        cout<<"Circular Dequeue Underflow\n";
        return;
    }
    cout<<"Deleted Front end element :"<<arr[front]<<'\n';
    if(front==rear){
        front=-1;
        rear=-1;
    }
    front++;
}
void delete_rear(int* arr){
    if(front==-1){
        cout<<"Circular Dequeue Underflow\n";
        return;
    }
    cout<<"Deleted Rear end element :"<<arr[rear]<<'\n';
    if(front==rear){
        front=-1;
        rear=-1;
    }
    rear--;
}
void display(int *arr){
    if(front==-1){
        cout<<"Empty List\n";
        return;
    }
    if(front<=rear)
        for(int i=front;i<=rear;i++)
            cout<<arr[i]<<" ";
    else{
        for(int i=front;i<maxx;i++)
            cout<<arr[i]<<" ";
        for(int i=0;i<=rear;i++)
            cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    cout<<"Enter the no of elements to be inserted:\n";
    cin>>maxx;
    int *arr=new int[maxx];
    int ch;
    while(1){
        cout<<"Enter your choice:\n1.Enqueue Front\n"
             "2.Enqueue Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n";
        cin>>ch;
        switch(ch){
            case 1:enqueue_front(arr);break;
            case 2:enqueue_rear(arr);break;
            case 3:delete_front(arr);break;
            case 4:delete_rear(arr);break;
            case 5:display(arr);break;
            case 6:exit(0);break;
            default:
            cout<<"Invalid Choice\n";break;
        }
    }
return 0;
}