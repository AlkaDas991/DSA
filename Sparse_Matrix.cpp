#include<iostream>
#define nl '\n'
using namespace std;
typedef struct node{
    int data1;
    int data2;
    int data3;
    struct node* next;
}Node;
Node *head=NULL,*curr=NULL,*temp=NULL;
int **sparse_matrixr(int nzero,int **arr,int r,int c){
    int k=0;
    int **sparse=new int*[nzero+1];
    for(int i=0;i<=nzero;i++)
        sparse[i]=new int[3];
    sparse[0][0]=r;
    sparse[0][1]=c;
    sparse[0][2]=nzero;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(arr[i][j]!=0)
            {
                k++;
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=arr[i][j];
            }
    return sparse;
}
int **sparse_matrixc(int nzero,int **arr,int r,int c){
    int k=0;
    int **sparse=new int*[nzero+1];
    for(int i=0;i<=nzero;i++)
        sparse[i]=new int[3];
    sparse[0][0]=c;
    sparse[0][1]=r;
    sparse[0][2]=nzero;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(arr[i][j]!=0)
            {
                k++;
                sparse[k][0]=j;
                sparse[k][1]=i;
                sparse[k][2]=arr[i][j];
            }
    return sparse;
}
Node* sparse_matrixlr(int nzero,int **arr,int r,int c){
    curr=new Node;
    if(curr==NULL)
    {
        cout<<"Out of Memory\n";
        return curr;
    }
    if(head==NULL){
        curr->data1=r;
        curr->data2=c;
        curr->data3=nzero;
        curr->next=NULL;
        head=curr;
        temp=curr;
    }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(arr[i][j]!=0)
            {
                curr=new Node;
                temp->next=curr;
                curr->data1=i;
                curr->data2=j;
                curr->data3=arr[i][j];
                curr->next=NULL;
                temp=curr;
            }
    return head;
}
Node* sparse_matrixlc(int nzero,int **arr,int r,int c){
    curr=new Node;
    if(curr==NULL)
    {
        cout<<"Out of Memory\n";
        return curr;
    }
    if(head==NULL){
        curr->data1=c;
        curr->data2=r;
        curr->data3=nzero;
        curr->next=NULL;
        head=curr;
        temp=curr;
    }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(arr[i][j]!=0)
            {
                curr=new Node;
                temp->next=curr;
                curr->data1=j;
                curr->data2=i;
                curr->data3=arr[i][j];
                curr->next=NULL;
                temp=curr;
            }
    return head;
}
void display(int **sparse,int nzero){
    for(int i=0;i<=nzero;i++)
    {
        for(int j=0;j<3;j++)
            cout<<sparse[i][j]<<" ";
        cout<<'\n';
    }
}
void displayl(Node* ptr){
    if(ptr==NULL){
        cout<<"Empty List\n";
        return;
    }
    while(ptr!=NULL){
        cout<<ptr->data1<<" "<<ptr->data2<<" "<<ptr->data3<<"-->\n";
        ptr=ptr->next;
    }
}
int main(){
    int r,c,nzero{0}; 
    cout<<"Enter no of rows and columns for matrix:\n";
    cin>>r>>c;
    int **arr=new int*[r];
    for(int i=0;i<r;i++)
        arr[i]=new int[c];
    cout<<"Enter the elements of the matrix\n";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]!=0)
                nzero++;
        }
    } 
    if(nzero>r*c/2)
        cout<<"Not a sparse Matrix\n";
    else
    {
        int ch;
        cout<<"Enter your choice for sparse matrix:\n";
        cout<<"1.Row Format\n2.Column Format\n3.Linked List Row Format\n4.Linked List Column Format\n5.exit\n";
        cin>>ch;
        int **sparse;
        switch(ch)
        {
            case 1:sparse=sparse_matrixr(nzero,arr,r,c);
                   cout<<"Row Format Display:\n";
                   display(sparse,nzero);
                   break;
            case 2:sparse=sparse_matrixc(nzero,arr,r,c);
                   cout<<"Column Format Display:\n";
                   display(sparse,nzero);
                   break;
            case 3:head=sparse_matrixlr(nzero,arr,r,c);
                   cout<<"Linked List Row Format Display:\n";
                   displayl(head);
                   break;
            case 4:head=sparse_matrixlc(nzero,arr,r,c);
                   cout<<"Linked List Column Format Display:\n";
                   displayl(head);
                   break;
            case 5:exit(0);
            default:cout<<"Invalid Choice\n";
        }
    }
    return 0;
}                            