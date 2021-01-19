#include<iostream>
using namespace std;
typedef struct node{
    struct node *prev;
    int data;
    struct node* next;
}Node;
Node* head,*curr,*ptr;
void create(){
    int i=0;
    char ch='y';
    do{
        curr=new Node;
        if(curr==NULL){
            cout<<"Out of Memory\n";
            return;
        }
        i++;
        cout<<"Enter node "<<i<<" data\n";
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
            curr->prev=ptr;
        }
        curr->next=head;
        head->prev=curr;
        cout<<"Do you want more nodes(y/n)\n";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
}
Node* insert_end(){
    curr=new Node;
    if(curr==NULL){
        cout<<"Out of Memory\n";
        return head;
    }
    cout<<"Enter data\n";
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
        curr->prev=ptr;
    }
    curr->next=head;
    head->prev=curr;
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
        curr->prev=ptr;
    }
    curr->next=head;
    head->prev=curr;
    head=curr;
    return head;
}
Node* fdisplay(){
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
    return head;
}
Node* bdisplay(){
    if(head==NULL){
        cout<<"Empty List\n";
        return head;
    }
    ptr=head->prev;
    while(ptr->prev!=head->prev){
        cout<<ptr->data<<'\n';
        ptr=ptr->prev;
    }
    cout<<ptr->data<<'\n';
    return head;
}
Node* delete_begin(){
    ptr=head;
    if(ptr==NULL){
        cout<<"Empty List\n";
        return head;
    }
    if(ptr->next==head){
        head=NULL;
        delete ptr;
        return head;
    }
    head->next->prev=head->prev;
    head->prev->next=head->next;
    head=head->next;
    delete ptr;
    return head;
}
Node* delete_end(){
    ptr=head;
    if(ptr==NULL){
        cout<<"Empty List\n";
        return head;
    }
    if(ptr->next==head){
        head=NULL;
        delete ptr;
        return head;
    }
    head->prev->prev->next=head;
    head->prev=head->prev->prev;
    delete ptr;
    return head;
}
int main(){
    create();
    char ch='y'; 
    int val;
    while(ch=='y'|| ch=='Y'){
        cout<<"Enter your Choice\n";
        cout<<"1.Insert At Begin\n2.Insert At End\n3.Delete At Begin\n4.Delete At End\n5.Forward Display\n6.BackWard Dispaly\n8.Exit\n";
        cin>>val;
        switch(val){
            case 1:head=insert_begin();break;
            case 2:head=insert_end();break;
            case 3:head=delete_begin();break;
            case 4:head=delete_end();break;
            case 5:head=fdisplay();break;
            case 6:head=bdisplay();break;
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