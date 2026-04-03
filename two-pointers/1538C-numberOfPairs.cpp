#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countPairsWithSumLess(const vector<int>& a, int limit) {
    long long count = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        // Find index of the first element > (limit - a[i])
        auto it = upper_bound(a.begin() + i + 1, a.end(), limit - a[i]);//Bisect right
        count += distance(a.begin() + i + 1, it);
    }
    return count;
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    cout << countPairsWithSumLess(a, r) - countPairsWithSumLess(a, l - 1) << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
