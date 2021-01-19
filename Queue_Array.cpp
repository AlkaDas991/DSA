#include<iostream>
#define nl '\n'
using namespace std;
int maxx,front=-1,rear=-1;
void Insert(int *arr){
    if(rear==maxx-1){
        cout<<"Queue Overflow\n";
        return;
    }
    int ele;
    cout<<"Enter an element\n";
    cin>>ele;
    if(front==-1)
        front++;
    rear++;
    arr[rear]=ele;
}
void Delete(int *arr){
    if(front==-1 || front>rear){
        cout<<"Queue Underflow\n";
        return;
    }
    cout<<"The popped element is: "<<arr[front]<<nl;
    front++;
}
void Peek(int *arr){
    if(front==-1 || front>rear){
        cout<<"Queue Underflow\n";
        return;
    }
    cout<<"The 1st element in queue is: "<<arr[front]<<nl;
}
void Display(int *arr){
    if(front==-1 || front>rear){
        cout<<"Queue Underflow\n";
        return;
    }
    for(int i=front;i<=rear;i++)
        cout<<arr[i]<<" ";
    cout<<nl;
}
int main(){
    cout<<"Enter the maximium capacity of queue\n";
    cin>>maxx;
    int *arr=new int[maxx];
    char c='y';
    while(c=='y' || c=='Y'){
        int ch;
        cout<<"Enter your choice:\n1.Insert\n2.Delete\n3.Peek\n4.Display\n5.EXIT\n";
        cin>>ch;
        switch(ch){
            case 1:Insert(arr);break;
            case 2:Delete(arr);break;
            case 3:Peek(arr);break;
            case 4:Display(arr);break;
            case 5:exit(0);break;
            default:
            cout<<"Invalid Choice\n";
        }
        cout<<"Do you want to continue(y/n)\n";
        cin>>c;
    }
    return 0;
}