#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Map to store the frequencies of (PrefixSum_i - i)
    map<long long, long long> freq;
    
    // Base case: Before the array starts (index 0), 
    // the prefix sum is 0 and the index is 0. 
    // So, P_0 - 0 = 0.
    freq[0] = 1; 

    long long current_prefix_sum = 0;
    long long good_subarrays = 0;

    for (int i = 0; i < n; i++) {
        // Convert char to integer digit
        int digit = s[i] - '0'; 
        current_prefix_sum += digit;
        
        // Calculate V_i = P_i - index
        // Since our loop is 0-based, the actual mathematical index is (i + 1)
        long long val = current_prefix_sum - (i + 1);
        
        // If we've seen this 'val' before, every previous occurrence 
        // forms a valid "good subarray" ending at our current index.
        good_subarrays += freq[val];
        
        // Record this current 'val' for future subarrays to use
        freq[val]++;
    }

    cout << good_subarrays << "\n";
}

int main() {
    // Fast I/O is essential for Codeforces
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}