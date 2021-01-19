#include<iostream>
using namespace std;
int global = 100;

int& setGlobal()
{
    return global;    
}
int main(){
    setGlobal() = 400;
    cout<<global<<'\n';
    return 0;
}