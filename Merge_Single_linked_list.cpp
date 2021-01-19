#include<iostream>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}Node;
Node* create(Node* head,int n){
    Node* prev;
    char ch='y';
    int i=0;
    do{
        Node* curr=new Node;
        if(curr==NULL){
            cout<<"Out of Memory\n";
            return head;
        }
        i++;
        cout<<"Enter Linked List "<<n<<" node "<<i<<" data:\n";
        cin>>curr->data;
        curr->next=NULL;
        if(head==NULL){
            head=curr;
            prev=curr;
        }
        else{
            prev->next=curr;
            prev=curr;
        }
        cout<<"Do you want to continue:(y/n)\n";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return head;
}
void display(Node* ptr){
    if(ptr==NULL){
        cout<<"Empty List\n";
        return;
    }
    while(ptr!=NULL){
        cout<<ptr->data<<'\n';
        ptr=ptr->next;
    }
}
void merge(Node* ptr1,Node* ptr2){
    if(ptr1==NULL && ptr2==NULL)
    {
        cout<<"Both are Empty\n";
        return;
    }
    else if(ptr1==NULL && ptr2!=NULL){
        ptr1=ptr2;
        return;
    }
    else if(ptr1!=NULL && ptr2==NULL){
        return;
    }
    else{
        while(ptr1->next!=NULL){
            ptr1=ptr1->next;
        }
        ptr1->next=ptr2;
        return;
    }
}
int main(){
    int i=1;
    int choice;
    char ch;
    Node* head1=NULL,*head2=NULL;
    cout<<"Do you want to create Linked list 1?(y/n)\n";
    cin>>ch;
    if(ch=='y'|| ch=='Y')
    {
        head1=create(head1,1);
    }
    cout<<"Do you want to create Linked list 2?(y/n)\n";
    cin>>ch;
    if(ch=='y'|| ch=='Y')
    {
        head2=create(head2,2);
    }
    cout<<"Display Linked List 1 data:\n";
    display(head1);
    cout<<"Display Linked List 2 data:\n";
    display(head2);
    cout<<"Write the order of merging:\n1.1-->2\n2.2-->1\n";
    cin>>choice;
    if(choice==1)
    {
        merge(head1,head2);
        cout<<"After Merging 1 to 2:\n";
        display(head1);
    }
    else
    {
        merge(head2,head1);
        cout<<"After Merging 2 to 1:\n";
        display(head2);
    }
    return 0;
}