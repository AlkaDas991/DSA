#include<iostream>
#define max 5
using namespace std;
int queue1[max],queue2[max],front1{-1},rear1{-1},front2{-1},rear2{-1},c{0};
int delete1(){
    return queue1[front1++];
}
int delete2(){
    if(front2==-1 || front2>rear2){
        cout<<"Stack Underflow\n";
        return 0;
    }
    return queue2[front2++];
}
void insert2(int ele){
    if(front2==-1)
        front2++;
    queue2[++rear2]=ele;
}
void insert1(int ele){
    if(front1==-1)
        front1++;
    if(c!=0)
    {
        front1+=1;
        rear1+=1;
    }
    queue1[++rear1]=ele;
}
void pop(){
    c++;
    if(front1==-1 || front1>rear1){
        cout<<"Stack underflow\n";
    }
    while(front1<rear1){
        insert2(delete1());
    }
    cout<<"Removed Element is: "<<delete1()<<'\n';
    front1=-1;
    rear1=-1;
    while(front2<=rear2){
        insert1(delete2());
        c=0;
    }
    front2=-1;
    rear2=-1;
}
void push(){
    if(rear1==max-1){
        cout<<"Stack Overflow\n";
        return;
    }
    int ele;
    cout<<"Enter an element\n";
    cin>>ele;
    insert1(ele);
}
void peek(){
    if(front1==-1 || front1>rear1){
        cout<<"Stack underflow\n";
    }
    while(front1<=rear1){
        if(front1==rear1)
            cout<<"Top Element is "<<queue1[front1]<<'\n';
        insert2(delete1());
    }
    front1=-1;
    rear1=-1;
    while(front2<=rear2){
        insert1(delete2());
    }
    front2=-1;
    rear2=-1;
}
void display(){
    for(int i=rear1;i>=front1;i--)
        cout<<queue1[i]<<" ";
    cout<<"\n";
}
int main(){
    while(1){
        cout<<"Enter your choice:\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
        int ch;
        cin>>ch;
        switch(ch){
            case 1:push();break;
            case 2:pop();break;
            case 3:peek();break;
            case 4:display();break;
            case 5:exit(0);
            default:cout<<"Invalid choice\n";break;
        }
    }
    return 0;
}