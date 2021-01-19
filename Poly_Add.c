#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5
int cnt=0;
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
        //coefficients swap
        temp=max_add->coeff;
        max_add->coeff=p->coeff;
        p->coeff=temp;
        //exponents swap
        temp=max_add->exp;
        max_add->exp=p->exp;
        p->exp=temp;
        p=p->next;
    }
}
int no_memory(Poly *p){
    if(p==NULL){
        printf("No memory\n");
        return 1;
    }
    return 0;
}
Poly* create_pol(Poly *head){
    Poly *curr=(Poly*)malloc(sizeof(Poly));
    if(no_memory(curr))
        return NULL;
    printf("Enter coeff:\n");
    scanf("%d",&curr->coeff);
    printf("Enter exponent:\n");
    scanf("%d",&curr->exp);
    curr->next=NULL;
    head=curr;
    while(1){
        fflush(stdin);
        printf("Do you want to continue(yes/no):\n");
        char str[5];
        gets(str);
        if(strcmp(str,"no")==0)
            break;
        curr->next=(Poly*)malloc(sizeof(Poly));
        if(no_memory(curr->next))
            return NULL;
        curr=curr->next;
        printf("Enter coeff:\n");
        scanf("%d",&curr->coeff);
        printf("Enter exponent:\n");
        scanf("%d",&curr->exp);
        curr->next=NULL;
    } 
    return head;
}
void add(Poly *p1,Poly *p2,Poly *p3){
    while(p1!=NULL && p2!=NULL){
        if(cnt!=0)
        {
            p3->next=(Poly*)malloc(sizeof(Poly));
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
            printf("%dx^%d",p->coeff,p->exp);
        else
            printf(" + %dx^%d",p->coeff,p->exp);
        i++;
        p=p->next;
    }
    printf("\n");
}
int main(){
    Poly *head1=(Poly*)malloc(sizeof(Poly));
    if(no_memory(head1))
        return 0;
    printf("First Polynomial create:\n");
    head1=create_pol(head1);
    select_sort(head1);
    Poly *head2=(Poly*)malloc(sizeof(Poly));
    if(no_memory(head2))
        return 0;
    printf("Second Polynomial create:\n");
    head2=create_pol(head2);
    select_sort(head2);
    Poly *head3=(Poly*)malloc(sizeof(Poly));
    if(no_memory(head3))
        return 0;
    add(head1,head2,head3);
    printf("First Polynomial:\n");
    display(head1);
    printf("Second Polynomial:\n");
    display(head2);
    printf("Resultant Polynomial after Addition:\n");
    display(head3);
    return 0;
}