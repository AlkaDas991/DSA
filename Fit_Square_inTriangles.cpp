#include<iostream>
#define ll long long
#define nl '\n'
#define loop(x,y) for(int i=x;i<y;i++)
#define rloop(x,y) for(int j=x;j>=y;j--)
using namespace std;
void count(ll i,ll b,ll cnt){
    if(i>=b)cout<<cnt<<nl;
    if(i<=b-2){
        cnt+=(b-i)/2;
        count(i+2,b,cnt);
    }
}
void solve(){
    ll t,b;
    cin>>t;
    while(t--){
        ll i{2},cnt{0};
        cin>>b;
        if(b>=4){
            if(b&1) b--;
            count(i,b,cnt);
        }
        else
        cout<<cnt<<nl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}