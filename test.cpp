#include<iostream>
using namespace std;
int sum(int a,int b,int c){
    return a+b+c;
}
int main(){
    int (*p)(int,int,int);
    p=sum;
    cout<<*p<<" "<<sum(10,20,30);
    return 0;
}
