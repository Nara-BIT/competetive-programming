class Solution {
public:
    vector<int> arrNSE(vector<int>& arr){
        int i,j;
        int n=arr.size();
        stack<int>nst;
        vector<int>nse(n);
        for(i=n-1;i>=0;i--){
            while(!nst.empty()&&(arr[nst.top()]>=arr[i])){
                nst.pop();
            }
            nse[i]=(nst.empty()? n:nst.top());
            nst.push(i);

        }
        return nse;
    }
    vector<int> arrPSE(vector<int>& arr) {
        int i, j;
        int m = arr.size();
        stack<int> pst;
        vector<int> pse(m); 
        for (i = 0; i<m; i++) {
            while (!pst.empty() && (arr[pst.top()] >arr[i])) {
                pst.pop();
            }
            pse[i] = (pst.empty() ? -1 : pst.top());
            pst.push(i);
        }
        return pse; 
    }
    int sumSubarrayMins(vector<int>& arr) {
        int MOD=(1e9+7);
        long long prod;
        vector<int>NSE=arrNSE(arr);
        vector<int>PSE=arrPSE(arr);
        int i,j;
        int total=0,left,right;
        int n=arr.size();
        for(i=0;i<n;i++){
            left=abs(i-PSE[i]);
            right=abs(NSE[i]-i);
            prod=(left*right)%MOD;
            prod=(prod*arr[i])%MOD;
            total=(total+prod)%MOD;
        }
        return total;
    }
};