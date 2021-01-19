#include<iostream>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}Node;
Node* head,*curr,*ptr;
Node* insert_end(){
    curr=new Node;
    if(curr==NULL){
        cout<<"Out of Memory";
        return head;
    }
    cout<<"Enter data:";
    cin>>curr->data;
    if(head==NULL){
        head=curr;
    }
    else{
        ptr=head;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        ptr->next=curr;
    }
    curr->next=head;
    return head;
}
Node* insert_begin(){
    curr=new Node;
    if(curr==NULL){
        cout<<"Out of Memory";
        return head;
    }
    cout<<"Enter data:";
    cin>>curr->data;
    if(head==NULL){
        head=curr;
    }
    else{
        ptr=head;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        ptr->next=curr;
    }
    curr->next=head;
    head=curr;
    return head;
}
Node* display(){
    if(head==NULL){
        cout<<"Empty List\n";
        return head;
    }
    ptr=head;
    while(ptr->next!=head){
        cout<<ptr->data<<'\n';
        ptr=ptr->next;
    }
    cout<<ptr->data<<'\n';
    /*do{
        cout<<ptr->data<<'\n';
        ptr=ptr->next;
    }while(ptr!=NULL);*///better for display
    return head;
}
void create(){
    char ch='y';
    int i=0;
    do{
        curr=new Node;
        if(curr==NULL){
            cout<<"Out of Memory\n";
            return;
        }
        i++;
        cout<<"Enter node "<<i<<" data";
        cin>>curr->data;
        if(head==NULL){
            head=curr;
            curr->next=curr;
        }
        else{
            curr->next=head;
            ptr->next=curr;
        }
        ptr=curr;
        cout<<"Do you want to continue(y/n)";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
}
int main(){
    create();
    char ch='y';
    int val;
    while(ch=='y'|| ch=='Y'){
        cout<<"Enter your Choice\n";
        cout<<"1.Insert At Begin\n2.Insert At End\n5.Display\n8.Exit\n";
        cin>>val;
        switch(val){
            case 1:head=insert_begin();break;
            case 2:head=insert_end();break;
            /*case 3:head=delete_at_begin();break;
            case 4:head=delete_at_end();break;*/
            case 5:head=display();break;
           /* case 6:head=sort();break;
            case 7:head=reverse();break;*/
            case 8:exit(0);
            default:cout<<"Invalid Choice\n";
        }
        cout<<"Do you want to continue(y/n)";
        cin>>ch;
    }
    return 0;
}