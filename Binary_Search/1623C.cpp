#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;
 
bool check(const vector<ll>& heaps, ll mid) {
    vector<ll> curr_h = heaps;
    int n = heaps.size();
    
    for (int i = n - 1; i >= 2; i--) {
        if (curr_h[i] < mid) {
            return false;
        }
   
        ll d = min(heaps[i], curr_h[i] - mid) / 3;
        curr_h[i - 1] += d;
        curr_h[i - 2] += 2 * d;
    }
    return curr_h[0] >= mid && curr_h[1] >= mid;
}
 
ll get_ans(vector<ll>& heaps) {
    ll low = 0;
    ll high = *max_element(heaps.begin(), heaps.end());
    ll ans = 0;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(heaps, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
 
int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int m;
    if (!(cin >> m)) return 0;
    while (m--) {
        int n;
        cin >> n;
        vector<ll> heaps(n);
        for (int i = 0; i < n; i++) {
            cin >> heaps[i];
        }
        
        cout << get_ans(heaps) << "\n";
    }
    return 0;
}