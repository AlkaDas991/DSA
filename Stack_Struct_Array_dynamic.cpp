#include<iostream>
#define nl '\n'
using namespace std;
struct Stack{
    int *arr;
    int top;
}s={.top=-1};
int maxx;
int isfull(){
    if(s.top==maxx-1)
        return 1;
    return 0;
}
int isempty(){
    if(s.top==-1)
        return 1;
    return 0;
}
void push(){
    if(isfull()){
        cout<<"Stack Overflow\n";
        return;
    }   
    cout<<"Enter an Element:\n";
    int ele;
    cin>>ele;
    s.top++;
    s.arr[s.top]=ele;                                           
}
void pop(){
    if(s.top==-1){
        cout<<"Stack Underflow\n";
        return;
    }
    cout<<"The popped element is: "<<s.arr[s.top]<<nl;
    s.top--;
}
void peek(){
    if(s.top==-1){
        cout<<"Stack Underflow\n";
        return;
    }
    cout<<"The top element is: "<<s.arr[s.top]<<nl;
}
void display(){
    for(int i=s.top;i>=0;i--)
        cout<<s.arr[i]<<" ";
    cout<<nl;
}
int main(){
    cout<<"Enter the maximium capacity of stack\n";
    cin>>maxx;
    s.arr=new int[maxx];
    char c='y';
    while(c=='y' || c=='Y'){
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
        cout<<"Do you want to continue(y/n)\n";
        cin>>c;
    }
    return 0;
}