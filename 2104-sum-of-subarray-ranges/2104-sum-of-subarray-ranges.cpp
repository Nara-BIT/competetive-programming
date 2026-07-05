class Solution {
public:
    vector<int> arrNGE(vector<int>& arr) {
        int n = arr.size();
        stack<int> nge_stack;
        vector<int> nge(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!nge_stack.empty() && (arr[nge_stack.top()] <= arr[i])) {
                nge_stack.pop();
            }
            nge[i] = (nge_stack.empty() ? n : nge_stack.top());
            nge_stack.push(i);
        }
        return nge;
    }

    vector<int> arrPGE(vector<int>& arr) {
        int m = arr.size();
        stack<int> pge_stack;
        vector<int> pge(m);
        for (int i = 0; i < m; i++) {
            while (!pge_stack.empty() && (arr[pge_stack.top()] < arr[i])) {
                pge_stack.pop();
            }
            pge[i] = (pge_stack.empty() ? -1 : pge_stack.top());
            pge_stack.push(i);
        }
        return pge;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        long long prod;
        vector<int> NGE = arrNGE(arr);
        vector<int> PGE = arrPGE(arr);
        int n = arr.size();
        long long total = 0;
        long long left, right;
        for (int i = 0; i < n; i++) {
            left = abs(i - PGE[i]);
            right = abs(NGE[i] - i);
            prod = (left * right);
            prod = (prod * arr[i]);
            total = (total + prod);
        }
        return total;
    }

    vector<int> arrNSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> nst;
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!nst.empty() && (arr[nst.top()] >= arr[i])) {
                nst.pop();
            }
            nse[i] = (nst.empty() ? n : nst.top());
            nst.push(i);
        }
        return nse;
    }

    vector<int> arrPSE(vector<int>& arr) {
        int m = arr.size();
        stack<int> pst;
        vector<int> pse(m);
        for (int i = 0; i < m; i++) {
            while (!pst.empty() && (arr[pst.top()] > arr[i])) {
                pst.pop();
            }
            pse[i] = (pst.empty() ? -1 : pst.top());
            pst.push(i);
        }
        return pse;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        long long prod;
        vector<int> NSE = arrNSE(arr);
        vector<int> PSE = arrPSE(arr);
        int n = arr.size();
        long long total = 0;
        long long left, right;
        for (int i = 0; i < n; i++) {
            left = abs(i - PSE[i]);
            right = abs(NSE[i] - i);
            prod = (left * right);
            prod = (prod * arr[i]);
            total = (total + prod);
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long max,min;
        max=sumSubarrayMaxs(nums);
        min=sumSubarrayMins(nums);
        return max-min;
    }
};