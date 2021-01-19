#include<iostream>
#include<stack>
#include<map>
using namespace std;
int main(){
    string str;
    map<char,int> mpp;
    mpp.insert({'<',1});
    mpp.insert({'(',3});
    mpp.insert({'[',5});
    mpp.insert({'{',7});
    mpp.insert({'>',2});
    mpp.insert({')',6});
    mpp.insert({']',10});
    mpp.insert({'}',14});
    bool flag=true;
    stack<char>stk;
    cout<<"Enter a string\n";
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='<' || str[i]=='(' || str[i]=='{'|| str[i]=='[')
            stk.push(str[i]);
        else if(stk.empty()){
            flag=false;
            break;
        }
        else if(mpp[str[i]]==2*mpp[stk.top()]){
            stk.pop();
        }
    }
    if(!stk.empty())flag=false;
    flag?cout<<"Balanced Parenthesis\n":cout<<"Not a Balanced Parenthesis\n";
}