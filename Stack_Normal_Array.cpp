#include<iostream>
#define nl '\n'
using namespace std;
int top=-1,maxx;
void push(int *arr){
    if(top==maxx-1){
        cout<<"Stack Overflow\n";
        return;
    }
    int ele;
    cout<<"Enter an element\n";
    cin>>ele;
    top++;
    arr[top]=ele;
}
void pop(int *arr){
    if(top==-1){
        cout<<"Stack Underflow\n";
        return;
    }
    cout<<"The popped element is: "<<arr[top]<<nl;
    top--;
}
void peek(int *arr){
    if(top==-1){
        cout<<"Stack Underflow\n";
        return;
    }
    cout<<"The top element is: "<<arr[top]<<nl;
}
void display(int *arr){
    for(int i=top;i>=0;i--)
        cout<<arr[i]<<" ";
    cout<<nl;
}
int main(){
    cout<<"Enter the maximium capacity of stack\n";
    cin>>maxx;
    int *arr=new int[maxx];
    char c='y';
    while(c=='y' || c=='Y'){
        int ch;
        cout<<"Enter your choice:\n1.PUSH\n2.POP\n3.PEEK\n4.Display\n5.EXIT\n";
        cin>>ch;
        switch(ch){
            case 1:push(arr);break;
            case 2:pop(arr);break;
            case 3:peek(arr);break;
            case 4:display(arr);break;
            case 5:exit(0);break;
            default:
            cout<<"Invalid Choice\n";
        }
        cout<<"Do you want to continue(y/n)\n";
        cin>>c;
    }
    return 0;
}