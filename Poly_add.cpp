#include<iostream>
#include<string.h>
#include<algorithm>
#define max 5
using namespace std;
int cnt{0};
typedef struct poly{
    int coeff;
    int exp;
    struct poly *next;
}Poly;
void select_sort(Poly* p){
    Poly* max_add=p;
    Poly* ptr;
    int max_ele,temp;
    while(p->next!=NULL){
        max_ele=p->exp;
        ptr=p->next;
        while(ptr!=NULL){
            if(ptr->exp>max_ele)
                max_add=ptr;
            ptr=ptr->next;
        }
        swap(max_add->coeff,p->coeff);//coefficient swap
        swap(max_add->exp,p->exp);//exponent swap
        p=p->next;
    }
}
int no_memory(Poly *p){
    if(p==NULL){
        cout<<"No memory\n";
        return 1;
    }
    return 0;
}
Poly* create_pol(Poly *head){
    Poly *curr= new Poly;
    if(no_memory(curr))
        return NULL;
    cout<<"Enter coeff:\n";
    cin>>curr->coeff;
    cout<<"Enter exponent:\n";
    cin>>curr->exp;
    curr->next=NULL;
    head=curr;

    while(1){
        cin.ignore(256,'\n');
        cout<<"Do you want to continue(yes/no):\n";
        char str[5];
        gets(str);
        if(strcmp(str,"no")==0)
            break;
        curr->next=new Poly;
        if(no_memory(curr->next))
            return NULL;
        curr=curr->next;
        cout<<"Enter coeff:\n";
        cin>>curr->coeff;
        cout<<"Enter exponent:\n";
        cin>>curr->exp;
        curr->next=NULL;
    } 
    return head;
}
void add(Poly *p1,Poly *p2,Poly *p3){
    while(p1!=NULL && p2!=NULL){
        if(cnt!=0)
        {
            p3->next=new Poly;
            p3=p3->next;
            if(no_memory(p3))
                return;
        }
        if(p1->exp>p2->exp){
            p3->coeff=p1->coeff;
            p3->exp=p1->exp;
            p1=p1->next;
        }
        else if(p1->exp<p2->exp){
            p3->coeff=p2->coeff;
            p3->exp=p2->exp;
            p2=p2->next;
        }
        else{
            p3->coeff=p1->coeff+p2->coeff;
            p3->exp=p1->exp;
            p1=p1->next;
            p2=p2->next;
        }
        p3->next=NULL;
        cnt++;
    }
    if(p1==NULL)
        p3->next=p2;
    else if(p2==NULL)
        p3->next=p1;
}
void display(Poly *p){
    int i=0;
    while(p!=NULL){
        if(i==0)
            cout<<p->coeff<<"x^"<<p->exp<<" ";
        else
            cout<<"+ "<<p->coeff<<"x^"<<p->exp<<" ";
        i++;
        p=p->next;
    }
    cout<<'\n';
}
int main(){
    Poly *head1=new Poly;
    if(no_memory(head1))
        return 0;
    cout<<"First Polynomial create:\n";
    head1=create_pol(head1);
    select_sort(head1);
    Poly *head2=new Poly;
    if(no_memory(head2))
        return 0;
    cout<<"Second Polynomial create:\n";
    head2=create_pol(head2);
    select_sort(head2);
    Poly *head3=new Poly;
    if(no_memory(head3))
        return 0;
    add(head1,head2,head3);
    cout<<"First Polynomial:\n";
    display(head1);
    cout<<"Second Polynomial:\n";
    display(head2);
    cout<<"Resultant Polynomial after Adition:\n";
    display(head3);
    return 0;
}