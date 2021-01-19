#include<iostream>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}Node;
Node* sorted_merge(Node* ptr1,Node *ptr2){
    Node *head3,*ptr3;
    if(ptr1->data<=ptr2->data)
    {
        head3=ptr1;
        ptr1=ptr1->next;
    }
    else
    {
        head3=ptr2;
        ptr2=ptr2->next;
    }
    ptr3=head3;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
            ptr3=ptr3->next;
        }
        else if(ptr2->data<ptr1->data){
            ptr3->next=ptr2;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
        else{
            ptr3->next=ptr1;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
    }
    if(ptr1==NULL){
        ptr3->next=ptr2;
    }
    else{
        ptr3->next=ptr1;
    }
    return head3;
}
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
int main(){
    int i=1;
    int choice;
    char ch;
    Node* head1=NULL,*head2=NULL,*head3;
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
    cout<<"After Sorted Merge:\n";
    head3=sorted_merge(head1,head2);
    display(head3);
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   