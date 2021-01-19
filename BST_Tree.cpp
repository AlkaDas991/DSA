#include<iostream>
using namespace std;
class Node{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};
Node* root=NULL;
int ctr{0};
void insert(){
    Node *temp=new Node;
    if(temp==NULL){
        cout<<"Out of Memory\n";
        return;
    }
    cout<<"Enter data\n";
    cin>>temp->data;
    temp->lchild=NULL;
    temp->rchild=NULL;
    if(root==NULL){
        root=temp;
        return;
    }
    else{
        int item=temp->data;
        int flag;
        Node *ptr=root;
        Node *par;
        while(ptr!=NULL){
            par=ptr;
            if(item<ptr->data){
                ptr=ptr->lchild;
                flag=1;
            }
            else if(item>ptr->data){
                ptr=ptr->rchild;
                flag=2;
            }
            else{
                cout<<"Not possible\n";
                return;
            }
        }
        switch(flag){
            case 1:par->lchild=temp;break;
            case 2:par->rchild=temp;
        }
    }
}
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->lchild);
        cout<<root->data<<" ";
        inorder(root->rchild);
    }
}
void preorder(Node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(Node *root){
    if(root!=NULL){
        postorder(root->rchild);
        postorder(root->lchild);
        cout<<root->data<<" ";
    }
}
int height(Node* root){
    if(root==NULL)
        return 0;
    int l_height=height(root->lchild);
    int r_height=height(root->rchild);
    if(l_height>=r_height) return l_height+1;
    else return r_height+1;
}
void printlevel(Node *root,int level){
    if(root==NULL)
        return;
    if(level==0){
        cout<<root->data<<" ";
        return;
    }
    if(level>0){
        printlevel(root->lchild,level-1);
        printlevel(root->rchild,level-1);
    }
}
void levelorder(Node* root){
    int tot_height=height(root);
    for(int i=0;i<tot_height;i++){
        printlevel(root,i);
    }
}
void Delete(Node* root){
    if(root==NULL){
        cout<<"Out of Memory\n";
        return;
    }
    cout<<"Enter Data to delete\n";
    int ele;
    cin>>ele;
    int flag=0;
    Node *par,*ptr=root;
    while(ptr!=NULL){
        par=ptr;
        if(ele==ptr->data){ 
            flag=1;
            break;
        }
        else if(ele<ptr->data){
            ptr=ptr->lchild;
            flag=2;
        }
        else{
            ptr=ptr->rchild;
            flag=3;
        }
    }
    if(ptr==NULL){
        cout<<"Element not found\n";
        return;
    }
}
int main(){
    int ch;
    while(1){
        cout<<"Enter Your choice\n";
        cout<<"1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Levelorder\n6.Delete\n.7.Exit\n";
        cin>>ch;
        switch(ch){
            case 1:insert();break;
            case 2:inorder(root);cout<<'\n';break;
            case 3:preorder(root);cout<<'\n';break;
            case 4:postorder(root);cout<<'\n';break;
            case 5:levelorder(root);cout<<'\n';break;
            case 6:Delete(root);cout<<'\n';break;
            case 7:exit(0);
        }
    }
    return 0;
}