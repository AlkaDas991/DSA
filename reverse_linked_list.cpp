//#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct node{
    int data;
    struct node *next;
}Node;
Node* head=NULL;
Node* temp;
Node* sort(){
    if(head==NULL){
        cout<<"Empty List\n";
        return head;
    }
    Node* ptr=head;
    int min;
    while(ptr->next!=NULL){
        min=ptr->data;
        temp=ptr->next;
        while(temp!=NULL){
            if(temp->data<min){
                ptr->data=temp->data;
                temp->data=min;
                min=ptr->data;
            }
            temp=temp->next;
        }
        ptr=ptr->next;
    }
    return head;
}
Node * reverse(){
    if(head==NULL){
        cout<<"Empty list\n";
        return head;
    }
    Node * prev,*curr,*temp1;
    curr=head->next;
    head->next=NULL;
    prev=head;
    while(curr->next!=NULL){
        temp1=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp1;
    }
    curr->next=prev;
    head=curr;
    return head;
}
Node* insert_end(){
    Node* ptr=(struct node*)malloc(sizeof(struct node));
    cout<<"Enter data:\n";
    cin>>ptr->data;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        temp=head;
        return head;
    }
    temp->next=ptr;
    temp=ptr;
    return head;
}
void display(){
    Node* trav=head;
    while(trav!=NULL){
        cout<<trav->data<<'\n';
        trav=trav->next;
    }
}
int main(){
    char c='y';
    while(c=='y'|| c=='Y'){
        cout<<"Enter your choice:\n";
        cout<<"1.insert at beg\n2.insert at end\n3.reverse\n4.display\n5.Sort\n6.exit\n";
        int ch;
        cin>>ch;
        switch(ch){
            //case 1:insert_beg();break;
            case 2:head=insert_end();break;
            case 3:head=reverse();break;
            case 4:display();break;
            case 5:head=sort();break;
            case 6:exit(0);
            default:
                cout<<"Invalid choice\n";
        }
        cout<<"Do you want to continue:(y/n)";
        cin>>c;
    }
    return 0;
}