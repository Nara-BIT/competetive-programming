#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool can_solve(ll mid,ll h,vector<ll>&a){
    ll cnt=0;
    for(int i=0;i<a.size()-1;i++){
        cnt+=min(mid,a[i+1]-a[i]);
    }
    cnt+=mid;
    
    return cnt>=h;
    
}
 
void solve(){
    int n;
    ll h;
    cin >> n >> h;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    ll low = 1, high = h; 
    ll ans = h;
    while(low<=high){
        ll mid=low+(high-low)/2;
        if(can_solve(mid,h,a)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans<<"\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}