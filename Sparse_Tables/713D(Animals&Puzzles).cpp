#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int LOG = 10; // because 2^10 = 1024 > 1000

short st[LOG][LOG][MAXN][MAXN];
int dp[MAXN + 1][MAXN + 1];
int lg[MAXN + 1];

// Query maximum in rectangle [r1..r2][c1..c2] in 0-based indexing
int queryMax(int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) return 0;

    int k1 = lg[r2 - r1 + 1];
    int k2 = lg[c2 - c1 + 1];

    int rowOffset = 1 << k1;
    int colOffset = 1 << k2;

    return max({
        (int)st[k1][k2][r1][c1],
        (int)st[k1][k2][r2 - rowOffset + 1][c1],
        (int)st[k1][k2][r1][c2 - colOffset + 1],
        (int)st[k1][k2][r2 - rowOffset + 1][c2 - colOffset + 1]
    });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Step 1: Read grid and compute dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // Step 2: Build log table
    lg[1] = 0;
    for (int i = 2; i <= max(n, m); i++) {
        lg[i] = lg[i / 2] + 1;
    }

    // Step 3: Initialize sparse table base
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            st[0][0][i][j] = dp[i + 1][j + 1];
        }
    }

    // Step 4: Build 2D sparse table
    for (int k1 = 0; (1 << k1) <= n; k1++) {
        for (int k2 = 0; (1 << k2) <= m; k2++) {
            if (k1 == 0 && k2 == 0) continue;

            for (int i = 0; i + (1 << k1) <= n; i++) {
                for (int j = 0; j + (1 << k2) <= m; j++) {
                    if (k1 == 0) {
                        st[k1][k2][i][j] = max(
                            st[k1][k2 - 1][i][j],
                            st[k1][k2 - 1][i][j + (1 << (k2 - 1))]
                        );
                    } else {
                        st[k1][k2][i][j] = max(
                            st[k1 - 1][k2][i][j],
                            st[k1 - 1][k2][i + (1 << (k1 - 1))][j]
                        );
                    }
                }
            }
        }
    }

    // Step 5: Answer queries
    int q;
    cin >> q;

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int low = 0;
        int high = min(r2 - r1 + 1, c2 - c1 + 1);

        while (low < high) {
            int mid = (low + high + 1) / 2;

            // valid bottom-right corner area for square of side = mid
            int nr1 = r1 + mid - 2; // convert to 0-based
            int nc1 = c1 + mid - 2;
            int nr2 = r2 - 1;
            int nc2 = c2 - 1;

            if (queryMax(nr1, nc1, nr2, nc2) >= mid) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        cout << low << '\n';
    }

    return 0;
}