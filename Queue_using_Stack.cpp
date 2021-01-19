#include<iostream>
#define max 5
using namespace std;
int top1{-1},top2{-1},stack1[max],stack2[max],cnt{0},temp1{-1};
void pop_push(){
    if(top1==temp1){
        cout<<"Queue Underflow\n";
        return;
    }
    while(top1!=temp1){
        push2(pop1());
    }
}
void push1(int ele){
    if(cnt==1){
        top1+=1;
        temp1=top1;
    }
    stack1[++top1]=ele; 
}
void push2(int ele){
    if(top2==max-1){
        cout<<"Queue Overflow\n";
        return;
    }
    stack2[++top2]=ele;
}
int pop1(){
    return stack1[top1--];
}
int pop2(){
    if(top2==-1){
        cout<<"Queue Underflow\n";
        return 0;
    }
    return stack2[top2--];
}
void insert(){
    if(top1==max-1){
        cout<<"Queue Overflow\n";
        return;
    }
    int ele;
    cout<<"Enter an element\n";
    cin>>ele;
    push1(ele);
}
void Delete(){
    cnt=1;
    cout<<"Removed Element: "<<pop2()<<'\n';
    while(top2!=-1){
        push1(pop2());
        cnt=0;
    }
}
void peek(){
    if(top1==temp1){
        cout<<"Queue Underflow\n";
        return;
    }
    while(top1!=temp1){
        push2(pop1());
    }
    cout<<"Front Element: "<<stack2[top2]<<'\n';
    while(top2!=-1){
        push1(pop2());
    }
}
void display(){
    if(top1==temp1){
        cout<<"Queue Underflow\n";
        return;
    }
    while(top1!=temp1){
        push2(pop1());
    }
    for(int i=top2;i>=0;i--)
        cout<<stack2[i]<<" ";
    cout<<'\n';
    while(top2!=-1){
        push1(pop2());
    }
}
int main(){
    while(1){
        int ch;
        cout<<"Enter your choice:\n1.Insert\n2.Delete\n3.Peek\n4.Display\n5.EXIT\n";
        cin>>ch;
        switch(ch){
            case 1:insert();break;
            case 2:Delete();break;
            case 3:peek();break;
            case 4:display();break;
            case 5:exit(0);break;
            default:
            cout<<"Invalid Choice\n";
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
    }
    return 0;
}