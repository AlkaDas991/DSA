#include<iostream>
#include<algorithm>
#define ll long long
#define nl '\n'
#define loop(x,y) for(int i=x;i<y;i++)
#define rloop(x,y) for(int j=x;j>=y;j--)
using namespace std;
int calc_each(int arr[],int temp[],int start,int end,int used){
    
    if(start==end) return used;
    temp[arr[start]]=arr[start];
    rloop(arr[start]-1,0){
        if(temp[j]!=0){
            used+=arr[start]-temp[j];
            break;
        }
        if(j==0) used+=arr[start];
    }
    loop(arr[start]+1,end+1){
        if(temp[i]!=0){
            used+=temp[i]-arr[start];
            break;
        }
    }
    return calc_each(arr,temp,start+1,end,used);
}
void solve(){
    cout<<"hi\n";
    ll t;
    cin>>t;
    while(t--){
        int n,m,minn;
        bool flag{false};
        cin>>n>>m;
        int arr[n];
        loop(0,n) arr[i]=i+1;
        if(m-n*(n+3)/2>=0)
            minn=m-n*(n+3)/2;
        else minn=1000000000;
        while(next_permutation(arr,arr+n)){
            int temp[n+2]{0},used{0};
            temp[n+1]=n+1;
            used=calc_each(arr,temp,0,n+1,used);
            if(m-used==0){
                flag=true;
                minn=0;
            }
            else if(m-used>0){
                flag=true;
                minn=min(minn,m-used);
            }
        }
        flag?cout<<minn:cout<<"-1";
        cout<<nl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
ll t;
    cin>>t;
    while(t--){
        int n,m,minn;
        bool flag{false};
        cin>>n>>m;
        int arr[n];
        loop(0,n) arr[i]=i+1;
        if(m-n*(n+3)/2>=0)
            minn=m-n*(n+3)/2;
        else minn=1000000000;
        while(next_permutation(arr,arr+n)){
            int temp[n+2]{0},used{0};
            temp[n+1]=n+1;
            used=calc_each(arr,temp,0,n+1,used);
            if(m-used==0){
                flag=true;
                minn=0;
            }
            else if(m-used>0){
                flag=true;
                minn=min(minn,m-used);
            }
        }
        flag?cout<<minn:cout<<"-1";
        cout<<nl;
    }
    cout<<nl;
            