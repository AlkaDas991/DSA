#include<iostream>
using namespace std;
class Node{
    public:
    Node *lchild;
    int data;
    int height;
    Node *rchild;
};
Node *root=NULL;
int height(Node *temp){
    int lheight=temp && temp->lchild?temp->lchild->height:0;
    int rheight=temp && temp->rchild?temp->rchild->height:0;
    return lheight>=rheight?lheight+1:rheight+1;
}
int balanceFactor(Node *temp){
    if(temp==NULL)
        return 0;
    int lheight=temp && temp->lchild?temp->lchild->height:0;
    int rheight=temp && temp->rchild?temp->rchild->height:0;
    return lheight-rheight;
}
Node *LL_Rot(Node *par){
    Node *leftChild=par->lchild;
    Node *super_rchild=leftChild->rchild;
    par->lchild=super_rchild;
    leftChild->rchild=par;
    par->height=height(par);
    leftChild->height=height(leftChild);
    return leftChild;
}
Node *RR_Rot(Node *par){
    Node *rightChild=par->rchild;
    Node *super_lchild=rightChild->lchild;
    par->rchild=super_lchild;
    rightChild->lchild=par;
    par->height=height(par);
    rightChild->height=height(rightChild);
    return rightChild;
}
Node *LR_Rot(Node *par){
    Node *leftChild=par->lchild;
    Node *super_rchild=leftChild->rchild;
    par->lchild=super_rchild->rchild;
    leftChild->rchild=super_rchild->lchild;
    super_rchild->lchild=leftChild;
    super_rchild->rchild=par;
    par->height=height(par);
    leftChild->height=height(leftChild);
    super_rchild->height=height(super_rchild);
    return super_rchild;
}
Node *RL_Rot(Node *par){
    Node *rightChild=par->rchild;
    Node *super_lchild=rightChild->lchild;
    par->rchild=super_lchild->lchild;
    rightChild->lchild=super_lchild->rchild;
    super_lchild->lchild=par;
    super_lchild->rchild=rightChild;
    par->height=height(par);
    rightChild->height=height(rightChild);
    super_lchild->height=height(super_lchild);
    return super_lchild;
}
Node* NodeInsert(Node *ptr,Node *temp){
    if(ptr==NULL){
        return temp;
    }
    if(temp->data<ptr->data){
        ptr->lchild=NodeInsert(ptr->lchild,temp);
    }
    else if(temp->data>ptr->data){
        ptr->rchild=NodeInsert(ptr->rchild,temp);
    }
    else if(temp->data==ptr->data){
        cout<<"Insertion not possible\n";
        return ptr;
    }
    ptr->height=height(ptr);
    int bal_FactPar=balanceFactor(ptr);
    int bal_FactLchild=balanceFactor(ptr->lchild);
    int bal_FactRchild=balanceFactor(ptr->rchild);
    if(bal_FactPar==2 && bal_FactLchild==1){
        ptr=LL_Rot(ptr);
    }
    else if(bal_FactPar==-2 && bal_FactRchild==-1){
        ptr=RR_Rot(ptr);
    }
    else if(bal_FactPar==2 && bal_FactLchild==-1){
        ptr=LR_Rot(ptr);
    }
    else if(bal_FactPar==-2 && bal_FactRchild==1){
        ptr=RL_Rot(ptr);
    }
    return ptr;
}
void insert(){
    Node *temp=new Node;
    temp->lchild=NULL;
    temp->rchild=NULL;
    temp->height=1;
    if(temp==NULL){
        cout<<"Out of Memory\n";
        return;
    }
    cout<<"Enter Data to insert\n";
    int data;
    cin>>temp->data;
    root=NodeInsert(root,temp);
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
void printLevel(Node *root,int level){
    if(root==NULL)
        return;
    if(level==0)
        cout<<root->data<<" ";
    else if(level>0){
        printLevel(root->lchild,level-1);
        printLevel(root->rchild,level-1);
    }
}
void levelorder(Node *root){
    for(int i=0;i<root->height;i++){
        printLevel(root,i);
        cout<<'\n';
    }
}
int main(){
    int ch;
    while(1){
        cout<<"\nEnter Your choice\n";
        cout<<"1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Postorder\n6.Levelorder\n7.Exit\n";
        cin>>ch;
        switch(ch){
            case 1:insert();break;
            //case 2:Delete(root);cout<<'\n';break;
            case 3:inorder(root);cout<<'\n';break;
            case 4:preorder(root);cout<<'\n';break;
            case 5:postorder(root);cout<<'\n';break;
            case 6:levelorder(root);cout<<'\n';break;
            case 7:exit(0);
        }
    }
    return 0;
}