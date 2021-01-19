#include<iostream>
using namespace std;
void combination(int arr[],int data[],int start,int end,int index,int r){
    if(index==r){
        for(int i=0;i<r;i++)
            cout<<data[i]<<" ";
        cout<<"\n";
    }
    //end-i+1>=r-index is done to check whether there are sufficeint elements or not
    for(int i=start;i<=end && end-i+1>=r-index;i++){
        data[index]=arr[i];
        combination(arr,data,i+1,end,index+1,r);
    }
}
int main(){
    int n,r;
    cin>>n>>r;
    int * arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int data[r];
    combination(arr,data,0,n-1,0,r);
    delete arr;
    return 0;
}