#include<iostream>
#include<algorithm>
#define ll long long
#define M 1000000007
#define nl '\n'
#define loop(i,x,y,z) for(ll i=x;i<=y;i+=z)
#define rloop(i,x,y,z) for(ll i=x;i>=y;i-=z)
using namespace std;
void solve(){
    ll n,m,d;
    cin>>n>>m>>d;
    ll **matrix= new ll*[n];
    for(ll i=0;i<n;i++)
        matrix[i]=new ll[m];
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>matrix[i][j];
    ll *arr=new ll[n*m];
    int rem=matrix[0][0]%d;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(matrix[i][j]%d!=rem){
                cout<<-1<<nl;
                exit(0);
            }
            arr[i*m+j]=matrix[i][j];
        }
    }
    sort(arr,arr+n*m);
    int mid_index1=(n*m)/2;
    int min_op{0};
    for(ll i=0;i<n*m;i++)
        min_op+=llabs(arr[i]-arr[mid_index1])/d;
    if((n*m)%2==0){
        int mid_index2=mid_index1-1;
        int min_op2{0};
        for(ll i=0;i<n*m;i++)
            min_op2+=llabs(arr[i]-arr[mid_index2])/d;
        min_op=min(min_op,min_op2);
    }
    cout<<min_op<<nl;
}
int main(){
  solve();
  return 0;
}