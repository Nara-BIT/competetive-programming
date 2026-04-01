#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int LOGN = 18;
int st[MAXN][LOGN];
int lg2[MAXN];

// Range Maximum Query using Sparse Table
int query(int L, int R) {
    int j = lg2[R - L + 1];
    int idx1 = st[L][j];
    int idx2 = st[R - (1 << j) + 1][j];
    // Return the index that has the larger reachability (a[i])
    return (idx1 > idx2) ? idx1 : idx2; // This is a simplified comparison for logic
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }

    // Precompute logs for O(1) query
    lg2[1] = 0;
    for (int i = 2; i <= n; i++)
        lg2[i] = lg2[i / 2] + 1;

    // Build Sparse Table based on the values of a[i]
    // We store the INDEX that gives the maximum a[i]
    auto get_max_idx = [&](int i, int j) {
        return (a[i] > a[j]) ? i : j;
    };

    for (int i = 1; i < n; i++) st[i][0] = i;
    
    for (int j = 1; j < LOGN; j++) {
        for (int i = 1; i + (1 << j) - 1 < n; i++) {
            st[i][j] = get_max_idx(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    vector<ll> dp(n + 1, 0);
    ll total_sum = 0;

    // Solve from right to left
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] >= n - 1) {
            // Case 1: Can reach the last station (and all others) in 1 jump
            dp[i] = (ll)(n - i);
        } else {
            // Case 2: Find the best station m in range [i+1, a[i]]
            int m = st[i + 1][0]; // Default
            int L = i + 1, R = a[i];
            int j = lg2[R - L + 1];
            m = get_max_idx(st[L][j], st[R - (1 << j) + 1][j]);

            // Apply DP formula
            dp[i] = dp[m] + (n - i) - (a[i] - i);
        }
        total_sum += dp[i];
    }

    cout << total_sum << endl;

    return 0;
}