#include <algorithm>  
#include<stdlib.h>
#include <iostream> 
#include<vector>
#include<sstream>
using namespace std; 
int main(){
    int n,i=0;
    vector<string> arr;
    string longest;
    int index;
    int l,ml=0,tl=0;
    string str1,str2;
    getline(cin,str1);
    stringstream ss;
    ss<<str1;
    while(ss>>str2){
        arr.push_back(str2);
        l = arr[i].length();
        if(l>=ml){
            index = i;
            ml = l;
            longest = arr[i];
        }
        tl += l;
        i++;
    }
    if(tl != ml*2){
        cout<<-1<<'\n';
    }
    else{
        string str;
        n=arr.size();
        str="";
        string temp=arr[n-1];
        arr[n-1]=arr[index];
        arr[index]=temp;
        sort(arr.begin(),arr.begin()+n-1); 
    do{
        str="";
        for(int i=0;i<n-1;i++){
            str+=arr[i];
        }
        if(str==arr[n-1])
        {
            cout<<arr[n-1]<<'\n';
            exit(0);
        }
    }while(next_permutation(arr.begin(),arr.begin()+n-1));
    cout<<-1<<'\n';
    }
    return 0;
}